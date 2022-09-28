#pragma once

#include <iomanip>
#include <iostream>
#include <string>
#include "visitor.h"
#include "app.h"
#include "folder.h"
//#include "iterator.h"
#include "node_iterator.h"


class FindVisitor : public Visitor {
public:
    FindVisitor(std::string name): _name(name){}

    void visitApp(App* app) {
        // find app when app's name matches given name,
        // add app's route as result.
        if(app->name() == _name){
          _result = app->route();
        }
    }

    void visitFolder(Folder* folder) {
        // find folder when folder's name matches given name,
        // add folder's route as result.
        // And find the tree structure bellow,
        // add the other match result with `\n`.
        string Find_result;
        if(folder->name() == _name){
          Find_result.append(folder->route());
        }
        //bool yn = false;
        Iterator * it;
        for(it = folder->createIterator(); !it->isDone(); it->next()){
          FindVisitor *fv = new FindVisitor(_name);
          it->currentItem()->accept(fv);
          //cout << "FV: " << fv->getResult() <<endl;
          if(!((fv->getResult()).empty())){
            if(!Find_result.empty())
              Find_result.append("\n");
            Find_result.append(fv->getResult());
          }
          delete fv;
        }
        delete it;
        _result = Find_result;
    }

    string getResult() const {
        // return result.
        return _result;
    }
private:
      string _name, _result;
      //bool yn = false;
};
