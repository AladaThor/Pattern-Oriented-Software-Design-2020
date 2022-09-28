#ifndef _NODE_ITERATOR_H_
#define _NODE_ITERATOR_H_

#include "node.h"
#include "iterator.h"
#include <string>
//using namespace std;

template<class ForwardIterator>
class NodeIterator : public Iterator {
public:
    NodeIterator(ForwardIterator begin, ForwardIterator end):
      _begin(begin), _end(end){
      first();
        // initialize iterator.
    }

    void first() {
        // initialize iterator.
        _current = _begin;
    }

    void next() {
        // move iterator to next position,
        // throw std::string "Moving past the end!" when iterator move over the range of the structure.
        if(_current != _end)
          _current++;
        else
          throw (string)"Moving past the end!";
    }

    bool isDone() const {
        // return true when iterator reach the end of the structure.
        return _current == _end;
    }

    Node* currentItem() const {
        // return the Node that iterator currently point at.
        return * _current;
    }
private:
    ForwardIterator _begin;
    ForwardIterator _end;
    ForwardIterator _current;

};


#endif
