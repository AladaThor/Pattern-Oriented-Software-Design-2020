#ifndef _UTILITY_H_
#define _UTILITY_H_

#include <deque>
#include "node.h"
#include "iterator.h"
#include "folder.h"
/*
Shape* getShapeById(Shape* shape, std::string id) {
    // access the shape with iterator pattern.
    // DO NOT use Type Checking or Dynamic Type that would violate OCP to implement the function.
    // return a shape under the input shape tree sturctur that matches the id.
    // throw std::string "Only compound shape can get shape!" when the input shape is not iterable.
    // throw std::string "Expected get shape but shape not found" when no shape found with the given id.
    Iterator * it = shape->createIterator();
    if(it->isDone()){
      delete it;
      throw (string)"Only compound shape can get shape!";
    }
    for(; !it->isDone(); it->next()){

      Shape * s = it->currentItem();
      if(s->id() == id){
        delete it;
        return s;
      }
      Iterator *ita = s->createIterator();
      if(!ita->isDone()){
          Shape * underS = s->getShapeById(id);
          if(underS->id() == id){
            delete ita;
            delete it;
            return underS;
          }
      } // if(!ita->isDone())
      delete ita;
    }  //for(; !it->isDone(); it->next())
    delete it;
    throw (string)"Expected get shape but shape not found";
}*/

/*
template <class Filter>
std::deque<Shape*> filterShape(Shape* shape, Filter filter) {
    // access the shape with iterator pattern.
    // DO NOT use Type Checking or Dynamic Type that would violate OCP to implement the function.
    // return the shapes under the input shape tree sturctur that match the given filter.
    // throw std::string "Only compound shape can filter shape!" when the input shape is not iterable.
    deque<Shape*> ansQue;
    Iterator * it = shape->createIterator();
    if(!it->isDone()){
      for(; !it->isDone(); it->next()){
        Shape * s = it->currentItem();
        if(filter(s))
          ansQue.push_back(s);
        Iterator *ita = s->createIterator();
        if(!ita->isDone()){
          try{
            deque<Shape*> dq = filterShape(s,filter);
            if(!dq.empty()){
              Iterator * itb;
              for(itb = new ShapeIterator<deque<Shape *>::const_iterator>(dq.begin(), dq.end());
                  !itb->isDone(); itb->next()){
                      ansQue.push_back(itb->currentItem());
              } //for(itb = new ShapeIterator<deque<Shape *>::const_iterator>(dq.begin(), dq.end());
                //    !itb->isDone(); itb->next())
              delete itb;
            } //if(!dq.empty())
          }catch(string e){}
        } // if(!ita->isDone())
        delete ita;
      } // for(; !it->isDone(); it->next())
      delete it;
      return ansQue;
    } // if(!it->isDone())
    else{
      delete it;
      throw (string)"Only compound shape can filter shape!";
    }
}

class AreaFilter {
  public:
    AreaFilter(double upperBound, double lowerBound): _upper(upperBound), _lower(lowerBound){}
    bool operator() (Shape* shape) const {
      if(_upper >= shape->area() && shape->area() >= _lower)
        return true;
      else
        return false;
    }
  private:
    double _upper, _lower;
};

class PerimeterFilter {
  public:
    PerimeterFilter(double upperBound, double lowerBound): _upper(upperBound), _lower(lowerBound){}
    bool operator() (Shape* shape) const {
      if(shape->perimeter() <= _upper && shape->perimeter() >= _lower)
        return true;
      else
        return false;
    }
  private:
    double _upper, _lower;
};

class ColorFilter {
  public:
    ColorFilter(std::string color): _color(color){}
    bool operator() (Shape* shape) const {
      if(shape->color() == _color)
        return true;
      else
        return false;
    }
  private:
    string _color;
};

class TypeFilter {
  public:
    TypeFilter(std::string type): _type(type){}
    bool operator() (Shape* shape) const {
      if(shape->type() == _type)
        return true;
      else
        return false;
    }
  private:
    string _type;
};
*/

template<class Filter>
std::deque<Node*> filterNode(Node* node, Filter filter) {
    // access the node with iterator pattern.
    // DO NOT use Type Checking or Dynamic Type that would violate OCP to implement the function.
    // return the nodes under the input node tree sturctur that match the given filter.
    // throw std::string "Only folder can filter node!" when the input node is not iterable.
    deque<Node*> ansQue;
    Iterator * it = node->createIterator();
    if(!it->isDone()){
      for(; !it->isDone(); it->next()){
        Node * s = it->currentItem();
        if(filter(s))
          ansQue.push_back(s);
        Iterator *ita = s->createIterator();
        if(!ita->isDone()){
          try{
            deque<Node*> dq = filterNode(s,filter);
            if(!dq.empty()){
              Iterator * itb;
              for(itb = new NodeIterator<deque<Node *>::const_iterator>(dq.begin(), dq.end());
                  !itb->isDone(); itb->next()){
                      ansQue.push_back(itb->currentItem());
              } //for(itb = new ShapeIterator<deque<Shape *>::const_iterator>(dq.begin(), dq.end());
                //    !itb->isDone(); itb->next())
              delete itb;
            } //if(!dq.empty())
          }catch(string e){}
        } // if(!ita->isDone())
        delete ita;
      } // for(; !it->isDone(); it->next())
      delete it;
      return ansQue;
    } // if(!it->isDone())
    else{
      delete it;
      throw (string)"Only folder can filter node!";
    }
}


class SizeFilter {
public:
    SizeFilter(double upperBound, double lowerBound):  _upper(upperBound), _lower(lowerBound){}
    bool operator() (Node* node) const {
      if(_upper >= node->size() && node->size() >= _lower)
        return true;
      else
        return false;
    }
private:
    double _upper, _lower;
};


#endif
