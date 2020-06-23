#include<iostream>
#include<vector>
#include<string>
using namespace std;



class nodes{
private:
  string concat;
  class node{
  public:
    string key;
    int value;
    node* next;
  }*begin,*end,*buff;
public:
  nodes(){
    begin=nullptr;
    end=nullptr;
    buff=nullptr;
    begin = new node();
    end=begin;
    begin->next=nullptr;
    addEntry("SP",0);
    addEntry("LCL",1);
    addEntry("ARG",2);
    addEntry("THIS",3);
    addEntry("THAT",4);
    addEntry("SCREEN",16384);
    addEntry("KBD",24576);
    for(int i=0;i<16;i++){
      concat=to_string(i);
      concat = "R"+concat;
      addEntry(concat,i);
    }

  }
  void addEntry(string k,int v){
    buff = new node();
    end->next=buff;
    buff->key=k;
    buff->value=v;
    buff->next=nullptr;
    end=buff;
      //write it so that it doesnt allocate used numbers
  }
  void print(){
    buff=begin;
    while(buff->next){
      buff=buff->next;
      cout<<"\nkey: "<<buff->key<<"\nvalue: "<<buff->value;
    }
    cout<<"\nDone";
  }
  int contains(string s){
    buff=begin;
    while(buff->next){
      buff=buff->next;
      if(buff->key==s)
        return 1;
    }
    return 0;
  }

  int getAddress(string s){
    buff=begin;
    while(buff->next){
      buff=buff->next;
      if(buff->key==s)
        return buff->value;
    }
  }

};
