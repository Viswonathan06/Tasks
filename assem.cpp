#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include"nodey.h"

//namespca
using namespace std;

//globals
FILE *fi;
FILE *fo;

//classes
class prepro {

public:
  int newline;
  char ch;
  prepro(){
    newline=0;
    fi=fopen("temp1.txt","r");
    fo=fopen("temp.txt","w");
    while(!feof(fi)){
      newline=0;
      if(ch=='\n')
        newline++;
      ch=fgetc(fi);
      if(ch=='\n')
        newline++;
      if(ch!=' '&& newline != 2 && !feof(fi))
      fputc(ch,fo);
    }
    fclose(fi);
    remove("temp1.txt");
    fclose(fo);
  }
};

class parser {

public:
  char line[200];
  int codea;
  parser(){
    fi=fopen("temp.txt","r");
  //  fo=fopen("temp1.txt","w");
  }
  ~parser(){
    fclose(fi);
    //fclose(fo);
  }



  int hasMoreCommands(){
    return !feof(fi);
  }

  void advance(){
    do{
      fgets(line,200,fi);
    }while(hasMoreCommands() && line[0]=='/');
  }

  char commandType(){
    if(line[0]=='@')
      return 'A';
    else if(line[0]=='(')
      return 'L';
    else if(line[0]=='A'||line[0]=='M'||line[0]=='D'||line[0]=='0')
      return 'C';
    else
      exit(0);
  }

  string symbol(){
    int i=0;
    while(line[i+1]!='\0' || line[i+1]!=')')
    {
      line[i]=line[i+1];
      i++;
    }
    line[i]='\0';
    return line;
  }

  string dest(){
    string temp;
    int A=0,M=0,D=0;
    int i=0;
    while(line[i]!='\0'){
      if(line[i]==';')
        {
          i=-1;
          break;
        }
        i++;
    }
    if(line[0]=='0'||i==-1){
      return "000";
    }

    i=0;
    while(line[i]!='='){
      temp[i] = line[i];
      i++;
    }
    temp[i]='\0';
    i=0;
    while(temp[i]!='\0'){
      if(temp[i]=='A')
        A=1;
      if(temp[i]=='M')
        M=1;
      if(temp[i]=='D')
        D=1;
      i++;
    }
    temp = to_string(A*100+M*10+D);
    return temp;
  }

  string comp(){
    int i=0,flag=0;
    string temp="123";
    while(line[i]!='\0'){
      if(line[i]=='=')
        {
          flag=1;
          i++;
          break;
        }
        i++;
    }
    cout<<flag;

    if(!flag)
      i=0;
    cin>>flag;
    int k=0;
      while(line[i]!='\0' && line[i]!=';'){
        temp[k]=line[i];
        i++;
        k++;
      }
      if (present('M',temp)==1)
        {
          temp=replace(temp);
          codea=1;
        }
      else
        codea=0;
      if(temp=="0") return "101010";
      if(temp=="1") return "111111";
      if(temp=="-1") return "111010";
      if(temp=="D") return "001100";
      if(temp=="A") return "110000";
      if(temp=="!D") return "001101";
      if(temp=="!A") return "110001";
      if(temp=="-D") return "001111";
      if(temp=="-A") return "110011";
      if(temp=="D+1") return "011111";
      if(temp=="A+1") return "110111";
      if(temp=="D-1") return "001110";
      if(temp=="A-1") return "110010";
      if(temp=="D+A") return "000010";
      if(temp=="D-A") return "010011";
      if(temp=="A-D") return "000111";
      if(temp=="D&A") return "000000";
      if(temp=="D|A") return "010101";

      return "-1";
  }

  string code7(){
    string sol = to_string(codea) + comp();
    return sol;
  }

  int present(char ch, string line){
    int i;
    for(i=0;line[i]!='\0';i++)
    {
      if(line[i]==ch)
        return 1;
    }
    return 0;
  }
  string replace(string flag)
  {
    int i;
    for(i=0;flag[i]!='\0';i++)
    {
      if(flag[i]=='M')
        flag[i]='A';
    }
    return flag;
  }
};

int main(int argc, const char *argv[]) {
  rename("fil.txt","temp1.txt");  //sometimes my genius, it frightens me..
  prepro p; //preprocessing will be done by the constructor..haha
  //start writing actual shit here
  nodes SymTable;
  parser pa;
  

}
