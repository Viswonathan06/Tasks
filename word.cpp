#include<iostream>
#include<string.h>

int main(int argc, char *argv[]){
    int i=0;
    char str[100];
    while(argv[1][i]!='.'){
        str[i]=argv[1][i];
        i++;
    }
    str[i]='\0';
    char cmd[200];
    //
    strcpy(cmd,"g++ -o ");
    strcat(cmd,str);
    strcat(cmd," ");
    strcat(cmd,argv[1]);
    
    // "g++ -o " + str + " " +argv[1];
    system(cmd);
    //
    strcpy(cmd,"./");
    strcat(cmd,str);
    i=2;
    while(i<argc){
        strcat(cmd," ");
        strcat(cmd,argv[i]);
        i++;
    }
    system(cmd);
}