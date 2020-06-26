#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<ctype.h>
#include<string.h>
#include"nodey.h"

//namespaces
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
      if(ch!=' ' && newline != 2 && !feof(fi))
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
    //cout<<"destroyed";
    //fclose(fo);
  }

  int hasMoreCommands(){
    return !feof(fi);
  }

  void advance(){
    do{
      if(fgets(line,200,fi)==NULL)
        line[0]='/';
    }while(hasMoreCommands() && line[0]=='/');
    
  }

  char commandType(){
    if(line[0]=='@')
      return 'A';
    else if(line[0]=='(')
      return 'L';
    else if(line[0]=='A'||line[0]=='M'||line[0]=='D'||line[0]=='0')
      return 'C';
    else if(line[0]=='/' || line[0]=='\n')
      return 'O';
      
  }

  string symbol(){
    int i=0;
    char line[200];
    strcpy(line,parser::line);
    while(line[i+1]!='\n' && line[i+1]!=')')
    {
      line[i]=line[i+1];
      i++;
    }
    line[i]='\0';
    return line;
  }

  string dest(){
    string temp="abc";
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
    temp = to_string(A) + to_string(D) + to_string(M);
    return temp;
  }

  string comp(){
    int i=0,flag=0;
    char ch[10];
    char *temp=ch;
    while(line[i]!='\0'){
      if(line[i]=='=')
        {
          flag=1;
          i++;
          break;
        }
        i++;
    }

    //cout<<flag;

    if(!flag)
      i=0;
    if(present(';',line)){
      flag=0;
    }
    //cin>>flag;
    int k=0;
      while(line[i]!='\0' && line[i]!=';' && line[i]!='\n'){
        temp[k]=line[i];
        i++;
        k++;
      }
      temp[k]='\0';
      temp[k+1]='\0';
      if (present('M',temp)==1)
        {
          temp=replace(temp);
          codea=1;
        }
      else
        codea=0;
      if(!strcmp(temp,"0")) return "101010";
      if(!strcmp(temp,"1")) return "111111";
      if(!strcmp(temp,"-1")) return "111010";
      if(!strcmp(temp,"D")) return "001100";
      if(!strcmp(temp,"A")) return "110000";
      if(!strcmp(temp,"!D")) return "001101";
      if(!strcmp(temp,"!A")) return "110001";
      if(!strcmp(temp,"-D")) return "001111";
      if(!strcmp(temp,"-A")) return "110011";
      if(!strcmp(temp,"D+1")) return "011111";
      if(!strcmp(temp,"A+1")) return "110111";
      if(!strcmp(temp,"D-1")) return "001110";
      if(!strcmp(temp,"A-1")) return "110010";
      if(!strcmp(temp,"D+A")) return "000010";
      if(!strcmp(temp,"D-A")) return "010011";
      if(!strcmp(temp,"A-D")) return "000111";
      if(!strcmp(temp,"D&A")) return "000000";
      if(!strcmp(temp,"D|A")) return "010101";
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

  char* replace(char *flag)
  {
    int i;
    for(i=0;flag[i]!='\0';i++)
    {
      if(flag[i]=='M')
        flag[i]='A';
    }
    return flag;
  }

  string jump(){
    int i=0;
    string temp="abc";
    while( line[i]!=';' && line[i]!='\0')
      i++;
    if(line[i]=='\0')
      return "000";
    int k=0; 
    i++;
    while(line[i]!='\0'){
      temp[k]=line[i];
      i++;
      k++;
    }
    temp[k]='\0';
    if(temp=="JGT") return "001";
    if(temp=="JEQ") return "010";
    if(temp=="JGE") return "011";
    if(temp=="JLT") return "100";
    if(temp=="JNE") return "101";
    if(temp=="JLE") return "110";
    if(temp=="JMP") return "111";
  }

  void res(){
    fseek(fi, 0, SEEK_SET);
  }

};

//functions
int isnumb(parser *p){
   string temp = p->symbol();
   int decimal=0;
   int ten=1;
   int flag=0,i=0;
   while(temp[i]!='\n' && temp[i]!='\0'){
      if(!isdigit(temp[i])){
        flag=1;
        break;
      }
      i++;
   }
   i--;
   if(flag==0){
     while(i<=0){
        decimal+=(temp[i]-48)*ten;
        ten*=10;
        i++;
     }
     return decimal;
   }
   else
   {
     return 0;
   }
   
}

string tobin(int num){
  int i=15;
  string temp=" ";
  string binary="0234567890123456";
  while(i>0){
    temp=to_string(num%2);
    binary[i]=temp[0];
    num=num/2;
    i--;
  }
  return binary;
}

//main
int main(int argc, const char *argv[]) {
  rename(argv[1],"temp1.txt");  //sometimes my genius, it frightens me..
  //following lines to get the target file name.
  int k=0;
  char ch[100];
  while(argv[1][k]!='.'){
    ch[k]=argv[1][k];

    k++;
  }
  ch[k]='\0';
  strcat(ch,".hack");

  //initializations
  prepro p; //preprocessing will be done by the constructor..haha
  //start writing actual shit here
  nodes SymTable;
  parser parse;

  //debug
/*if(parse.hasMoreCommands()){
    parse.advance();
    cout<<"111"<<parse.code7()<<parse.dest()<<parse.jump();
  }
*/
  //first pass 
  //adds (Xxx)types of symbols into the Symable
  int commandnumber=-1;
  while(parse.hasMoreCommands()){
    parse.advance();
    commandnumber++;
    if(parse.commandType()=='L'){
      if(!SymTable.contains(parse.symbol()))
      {
        SymTable.addEntry(parse.symbol(),commandnumber);
        commandnumber--;
      }
    }
  }
  parse.res();
  //second pass
  //writes to the target file
  int tableaddress=16;
  fo=fopen("temp1.txt","w");
  while(parse.hasMoreCommands()){
    parse.advance();
    if(parse.commandType()=='A'){
      if(SymTable.contains(parse.symbol())){
        string temp=tobin(SymTable.getAddress(parse.symbol()));        
        for(int i=0;i<16;i++){
          putc(temp[i],fo);
        }
        putc('\n',fo);
      }
      else{
      if(isnumb(&parse)){
        string temp=tobin(isnumb(&parse));
        int i;
        for(i=0;i<16;i++){
          putc(temp[i],fo);
        }
        putc('\n',fo);
        }
      else{
        SymTable.addEntry(parse.symbol(),tableaddress);
        string temp=tobin(tableaddress);
        tableaddress++;
        for(int i=0;i<16;i++){
          putc(temp[i],fo);
        }
        putc('\n',fo);
        }
      }
      
    }
    if(parse.commandType()=='C'){
      string temp="111"+parse.code7()+parse.dest()+parse.jump();
      for(int i=0;i<16;i++){
          putc(temp[i],fo);
      }
        putc('\n',fo);
    }
  }
  fclose(fo);
  remove("temp.txt");
  //renames final file to targetfile.hack
  rename("temp1.txt",ch);
}
