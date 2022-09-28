#ifndef _FOLDER_H_
#define _FOLDER_H_


#include "node.h"
#include "iterator.h"
#include "node_iterator.h"

using namespace std;

class Folder : public Node {
public:
    Folder(string id, string name) : Node(id, name, 0) {
      _path = "";
    } // the default size of folder is zero.

    double size() const{
      double total = 0.0;
      Iterator * it;
      for(it = createIterator(); !it->isDone(); it->next()){
        total += it->currentItem()->size();
      }
      delete it;
      return total;
    }

    void updatePath(std::string path) override{
        if(!path.empty()){
          _path = path;
        }
        string tmp = _path + "/" + name();
        Iterator * it;
        for(it = createIterator(); !it->isDone(); it->next()){
          it->currentItem()->updatePath(tmp);
        }
        delete it;
    }

    string route() const{
      //string rout = _path + "/" + name();
      return _path + "/" + name();
    }

    void addNode(Node* node){
      _nodes.push_back(node);
      updatePath("");
    }

    void addNodes(list<Node*> nodes){
      if(!nodes.empty()){
        for(auto nl : nodes)
          _nodes.push_back(nl);
      }
      updatePath("");
    }

    Node* getNodeById(std::string id) const{
      Iterator * it;
      for(it = createIterator(); !it->isDone(); it->next()){
        Node * s = it->currentItem();
        if(s->id() == id)
          return s;
        Iterator *ita = s->createIterator();
        if(!ita->isDone()){
          try{
            Node * underS = s->getNodeById(id);
            if(underS->id() == id)
              return underS;
          }catch(string e){}
        }
        delete ita;
      }
      delete it;
        throw (string)"Expected get node but node not found.";
    }

    void deleteNodeById(std::string id){
      int Q = 0;
      Iterator * it;
      for(it = createIterator(); !it->isDone(); it->next()){
        Node * s = it->currentItem();

        if(s->id() == id){
          ++Q;
          _nodes.remove(it->currentItem());
          break;
        }
        Iterator *ita = s->createIterator();
        if(!ita->isDone()){
          try{
            ++Q;
            s->deleteNodeById(id);
          }catch(string e){
            Q = 0;
          }
        }
        delete ita;
      }
      delete it;
      if(Q == 0){
        throw (string)"Expected delete node but node not found.";
      }
    }

    Iterator* createIterator() const{
      return new NodeIterator<list<Node *>::const_iterator>(_nodes.begin(), _nodes.end());
    }

    // implement any functions inherit from Node that you think is suitable.

    void accept(Visitor* visitor){
      visitor->visitFolder(this);
    }

private:
    list<Node*> _nodes;
    string _path;
};

#endif
