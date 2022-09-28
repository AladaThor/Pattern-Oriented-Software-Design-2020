#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "node_scanner.h"
#include "node_builder.h"

class NodeParser {
public:
    NodeParser(string input) {
        // initialize a scanner for handling input.
        // initialize a node builder for handling building node.
        ns = new NodeScanner(input);
        nb = new NodeBuilder();
    }

    void parser() {
        // using NodeScanner::nextToken() to get all information to determine what to build,
        // and provide the argument the node needed.
        // use functions in NodeBuilder to build out the node.
        // the node with invalid argument should be ignored.
        int Lb = 0;
        while(true){
            string ptr;
            try{
                ptr = ns->nextToken();
            }catch(string e){
                break;
            }
            //cout << "ptr: " << ptr <<endl;
            if(ptr == ","){
                //cout << "," <<endl;
                continue;
            }
            else if(ptr == "}" && Lb != 0){
                nb->buildFolderEnd();
                --Lb;
                //cout << "}" <<endl;
                continue;
            }
            
            bool staW = false;
            //while(isalpha(ptr[i]))
            for(int i = 0; i < ptr.size(); ++i){
                if(isalpha(ptr[i])){
                    staW = true;
                }
                else
                    staW = false;
            }
            if(staW == true){
                string tmp = ns->nextToken();
                //cout << "tmp: " << tmp <<endl;
                if(tmp == "("){
                    tmp = ns->nextToken();
                    //cout << "tmp: " << tmp <<endl;
                    staW = false;
                    for(int i = 0; i < tmp.size(); ++i){
                        if(isdigit(tmp[i]) || tmp[i] == '.'){
                            staW = true;
                        }
                        else
                            staW = false;
                    }
                    if(staW == true){
                        string tmp2 = ns->nextToken();
                        //cout << "tmp: " << tmp2 <<endl;
                        if(tmp2 == ")"){
                            
                            nb->buildApp(ptr, stod(tmp));
                            //cout << ptr<<endl<<"("<<endl<<tmp<<endl<<")"<<endl;
                            continue;
                            //staW = false;
                        }
                        else{
                            tmp.clear();
                            continue;
                        }
                    }
                    else{
                        tmp.clear();
                        continue;
                    }
                }
                else if(tmp == "{"){
                    ++Lb;
                    nb->buildFolderBegin(ptr);

                    //cout << ptr<<endl<<"{"<<endl;
                    //staW = false;
                }
            }
            ptr.clear();
        }
    }

    deque<Node*> getResult() {
        // return result.
        //deque<Shape *> result = sb->getResult();
        //return result;
        return nb->getResult();
    }
  private:
    NodeScanner *ns;
    NodeBuilder *nb;
};
