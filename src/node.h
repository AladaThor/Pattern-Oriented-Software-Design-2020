#ifndef _NODE_H_
#define _NODE_H_

#include <list>
#include <iostream>
#include <math.h>
#include <string>
#include <iomanip>
#include "iterator.h"
#include "visitor.h"
//#include "null_iterator.h"

using namespace std;

//class Iterator;

class Node{
public:
        Node(std::string id, std::string name, double size);

        std::string id() const;

        std::string name() const;

        virtual std::string route() const; // the "virtual" of this funtion is optional.

        virtual double size() const;

        virtual void updatePath(std::string path);

        virtual void addNode(Node* node);

        virtual void addNodes(list<Node*> nodes);

        virtual Node* getNodeById(std::string id) const;

        virtual void deleteNodeById(std::string id);

        virtual Iterator* createIterator() const;

        virtual void accept(Visitor* visitor) = 0;

        virtual ~Node();
private:
        string _id, _name;
        double _size;
};


#endif
