#ifndef _NODE_CPP_
#define _NODE_CPP_

#include "node.h"
#include "null_iterator.h"

using namespace std;
Node::Node(string id, string name, double size): _id(id), _name(name), _size(size){}

string Node::id() const{
  return _id;
}

string Node::name() const{
  return _name;
}

string Node::route() const{
  //return _path + "/" + _name;
} // the "virtual" of this funtion is optional.

double Node::size() const{
  return _size;
}

void Node::updatePath(std::string path){
//  _path = path;
}

void Node::addNode(Node* node){
  throw (string)"only folder can add node.";
}

void Node::addNodes(list<Node*> nodes){
  throw (string)"only folder can add nodes.";
}

Node* Node::getNodeById(std::string id) const{
  throw (string)"only folder can get node.";
}

void Node::deleteNodeById(std::string id){
  throw (string)"only folder can delete node.";
}

Iterator* Node::createIterator() const{
  return new NullIterator();
}

Node::~Node(){}

#endif
