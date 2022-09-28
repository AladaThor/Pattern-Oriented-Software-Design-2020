#ifndef _NULL_ITERATOR_H_
#define _NULL_ITERATOR_H_

#include "node.h"
#include "iterator.h"
#include <string>
using namespace std;

class NullIterator : public Iterator {
public:
    void first() {
        throw (string)"No child member!";
    }

    void next() {
        throw (string)"No child member!";
    }

    bool isDone() const {
        return true;
    }

    Node* currentItem() const {
        throw (string)"No child member!";
    }
};

/*
class NullIterator : public Iterator {
public:
    void first() {

        throw (string)"No child member!";
    }

    void next() {
        throw (string)"No child member!";
    }

    bool isDone() const {
        return true;
    }

    Shape* currentItem() const {
      if(isDone()){
        throw (string)"No child member!";
      }
      return nullptr;
    }
};*/

#endif
