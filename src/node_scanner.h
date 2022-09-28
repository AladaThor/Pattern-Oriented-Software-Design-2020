#pragma once

#include <string>
#include <iostream>
#include <cstddef>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;


class NodeScanner {
public:
    NodeScanner(string input): _input(input) {}
    string nextToken() {
        // return next token.
        // throw exception std::string "next token doesn't exist." if next token not found.
        //skipInvalid();
        size_t lb, rb, cm, lB,rB;
        size_t Pos;
        int sta; //status
        string tmp;
        if(_input.empty())
          throw (string)"next token doesn't exist.";
        lb = _input.find_first_of("(");
        cm = _input.find_first_of(",");
        rb = _input.find_first_of(")");
        lB = _input.find_first_of("{");
        rB = _input.find_first_of("}");

        // cout << "lb: " <<lb<<endl;
        // cout << "rb: " <<rb<<endl;
        // cout << "cm: " <<cm<<endl;
        // cout << "lB: " <<lB<<endl;
        // cout << "rB: " <<rB<<endl;

        Pos = (int)lb == -1 ? INT_MAX : lb;
        //cout << "Pos: " <<Pos<<endl;
        Pos = (int)rb == -1 ? Pos : min(Pos, rb);
        //cout << "Pos: " <<Pos<<endl;
        Pos = (int)cm == -1 ? Pos : min(Pos, cm);
        //cout << "Pos: " <<Pos<<endl;
        Pos = (int)lB == -1 ? Pos : min(Pos, lB);
        //cout << "Pos: " <<Pos<<endl;
        Pos = (int)rB == -1 ? Pos : min(Pos, rB);
        //cout << "Pos: " <<Pos<<endl;
        sta = Pos == lB ? 1 : -1;
        sta = Pos == lb ? 2 : sta;
        sta = Pos == cm ? 3 : sta;
        sta = Pos == rb ? 4 : sta;
        sta = Pos == rB ? 5 : sta;

        if(sta == 1 && Pos != INT_MAX){
          if(Pos != 0){  // spilt string before "{"  (CompoundShape)
            //tmp = _input.substr(0,(int)(Pos));
            
            tmp  = isWord(_input.substr(0, (int)Pos));
            _input = _input.substr(Pos, _input.size());
            //cout << "Word: " <<tmp <<endl;
            if(tmp.empty())
              return nextToken();
            else
              return tmp;
            
          }
          else if(Pos != -1 && Pos == 0){
            _input = _input.substr(1, _input.size());
            return "{";
          }
        }

        //Pos = _input.find_first_of("(");
        else if(sta == 2 && Pos != INT_MAX){
          if(Pos != 0){  // spilt string before "("  (Other Shapes)
            //tmp = _input.substr(0,(int)(Pos)-1);
            
            tmp  = isWord(_input.substr(0, (int)Pos));
            _input = _input.substr((int)Pos, _input.size());
            //cout << "Word: " <<tmp <<endl;
            if(tmp.empty())
              return nextToken();
            else
              return tmp;
          }
          else if(Pos == 0){
            _input = _input.substr(1, _input.size());
            return "(";
          }
        }
        //Pos = _input.find_first_of(",");
        //cout << "Comma: "<<Pos<<endl;
        if(sta == 3 && Pos != INT_MAX){
          _input = _input.substr((int)(Pos)+1, _input.size());
          //cout << "CM: " << _input <<endl;
          return ",";

        }
        //Pos = _input.find_first_of(")");
        if(sta == 4 && Pos != INT_MAX){
          if(Pos != 0){
            //tmp = _input.substr(0,(int)Pos);
            
            tmp = isDigit(_input.substr(0,(int)Pos));
            _input = _input.substr(Pos, _input.size());
            stringstream ptr;
            ptr << fixed << setprecision(3) << tmp;
            return ptr.str();
          }
          else if(Pos == 0){
            if(_input.size() == 1)
              _input.clear();
            else
              _input = _input.substr((int)Pos+1, _input.size());
            return ")";
          }
        }
        //Pos = _input.find_first_of("}");
        if(sta == 5 && Pos != INT_MAX){
          //cout << "Input: " << _input << endl;
          //if(Pos == 0){
          if(_input.size() == 1)
            _input.clear();
          else
            _input = _input.substr((int)Pos+1, _input.size());
          return "}";
          
        }

        throw (string)"next token doesn't exist.";
    }

    string isWord(string word){
      //string ans;
      //cout << "Word in IsWord(): " << word << endl; 
      int f = -1;
      int e = 0;
      for(int i = 0; i < word.size(); ++i){
        if(isalpha(word[i])){
          if(e == 0){
            f = i;
          }
          e++;
        }
        else if(f != -1)
          break;
      }
      if(f == -1)
        return "";
      return word.substr(f,e);
    }

    string isDigit(string word){
      //string ans;
      //cout << "Word in IsDigit(): " << word << endl;
      int f = -1;
      int e = 0;
      int check_point = 0;
      for(int i = 0; i < word.size(); ++i){
        if(isdigit(word[i]) || word[i] == '.'){
          if(e == 0 && word[i] != '.'){
            f = i;
          }
          else if(word[i] == '.')
            check_point++;
          e++;
        }
        else if(f != -1)
          break;
      }
      if (check_point > 1)
        return "";
      return word.substr(f,e);
    }

 /*   bool isEnd(string str){
      size_t p;
      p = find()
    }*/
/*
    void skipInvalid() {
        for(int i = 0; i < _input.length(); ++i){
          bool iv = false;
          if((_input[i] <= 'Z' && _input[i] >= 'A') || (_input[i] <= 'z' && _input[i] >= 'a'))
            iv = true;
          else if(_input[i] <= '9' && _input[i] >= '0'))
            iv = true;
          else if(_input[i] == '{' || _input[i] == '}')
            iv = true;
          else if(_input[i] == '(' || _input[i] == ')')
            iv = true;
          else if(_input[i] == ',' || _input[i] == ' ')
            iv = true;
          else{
            _input.erase(i);
          }
        }
    }*/
    // you can add other public functions if you needed.

private:
    string _input;
    string::size_type pos = 0;
    const vector<string> tokenList = {"Node_Name", "Node_Size", "{", "}", "(", ")", ","};

};
