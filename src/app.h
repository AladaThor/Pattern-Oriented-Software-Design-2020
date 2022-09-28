#ifndef _APP_H_
#define _APP_H_

#include "node.h"

class App : public Node {
public:
    App(string id, string name, double size): Node(id, name, size) {
      _path = "";
    }
    void updatePath(std::string path) override {
      _path = path;
    }
    // implement any functions inherit from Node that you think is suitable.
    string route() const{
      //string rout = _path + "/" + name();
      return _path + "/" + name();
    }

    void accept(Visitor* visitor){
      visitor->visitApp(this);
    }

private:
  string _path;
};


#endif
