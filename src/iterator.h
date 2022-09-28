#ifndef _ITERATOR_H_
#define _ITERATOR_H_

class Node;

class Iterator {
public:
    virtual void first() = 0;

    virtual void next() = 0;

    virtual bool isDone() const = 0;

    virtual Node* currentItem() const = 0;
    
};

#endif
