#include<iostream>
#include<string>
using namespace std;
string getdig(int twodig){
  string ones,tens;
  string ret;
  int i=0;
  while(i<2)
  {
    switch(twodig%10){
      case 0: ones=" "; tens=" "; break;
      case 1: ones="one "; tens="ten "; break;
      case 2: ones="two "; tens="twenty "; break;
      case 3: ones="three "; tens="thirty "; break;
      case 4: ones="four ";tens="forty "; break;
      case 5: ones="five ";tens="fifty "; break;
      case 6: ones="six ";tens="sixty "; break;
      case 7: ones="seven ";tens="seventy "; break;
      case 8: ones="eight ";tens="eighty "; break;
      case 9: ones="nine ";tens="ninety "; break;
      default:;
    }
    if(!i){
      ret=ones;
    }
    i++;
    twodig=twodig/10;
  }
  if(tens==" ")
    return ret;
  return tens + ret;
}

int main(){
  string buf="0";
  int cur;
  int number=90890;
  int mainnumber=number;
  string only=" ";
  if(number%10==0)
    only = "only";
  cur=number/10000000;
  string crore= getdig(cur);
  crore==" "?buf="0":crore = crore + "crore ";
  number=number%10000000;
  cur=number/100000;
  string lakh= getdig(cur);
  lakh==" "?buf="0":lakh=lakh+"lakh ";
  number= number%100000;
  cur=number/1000;
  string thousand = getdig(cur);
  thousand==" "?buf="0":thousand=thousand+ "thousand ";
  number=number%1000;
  cur=number/100;
  string hundred = getdig(cur);
  hundred==" "?buf="0":hundred = hundred + "hundred and ";
  number=number%100;
  cur=number;
  string lefty= getdig(cur);
  if(mainnumber!=0)
  cout<<crore<<lakh<<thousand<<hundred<<lefty<<only;
  else
  cout<<"zero";
}
