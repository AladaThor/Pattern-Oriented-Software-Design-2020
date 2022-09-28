#pragma once

#include "node.h"
#include "app.h"
#include "folder.h"
#include <stack>
#include <deque>
#include <vector>

using namespace std;

class NodeBuilder {
public:
    void buildApp(string name, double size) {
        // build a app with an unique id and push in a std::stack.
        Node * app = new App(to_string(_pushdown.size()), name, size);
        _pushdown.push(app);
    }

    void buildFolderBegin(string name) {
        // notify begin of folder.
        Node * folder = new Folder(to_string(_pushdown.size()), name);
        _pushdown.push(folder);
        _id.push(folder->id());
    }

    void buildFolderEnd() {
        // notify end of folder.
        vector<Node *> v;
        while(_pushdown.top()->id() != _id.top()){
          v.push_back(_pushdown.top());
          _pushdown.pop();
        }
        _id.pop();
        for(auto it=v.rbegin(); it!=v.rend(); it++)
            _pushdown.top()->addNode(*it);
    }

    deque<Node*> getResult() {
      // return result.
        deque<Node *> result;

        while(!_pushdown.empty()){
            result.push_back(_pushdown.top());
            _pushdown.pop();
        }
        return deque<Node*>(result.rbegin(),result.rend());
    }

private:
    stack<Node *> _pushdown;
    stack<string> _id;
};
