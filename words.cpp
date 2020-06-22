#include<iostream>
#include<string>
using namespace std;
string getdig(int twodig){
  string ones[10] = {" ","one ","two ","three ","four ","five ","six ","seven ","eight ","nine "};
  string tens[10] = {" ","ten ","twenty ","thirty ","forty ","fifty ","sixty ","seventy ","eighty ","ninety "};
  string lolz[10] = {"ten ","eleven ","twelve ","thirteen ","fourteen ","fifteen","sixteen ","seventeen ","eighteen ","nineteen"};
  if(tens[twodig/10]=="ten ")
    return lolz[twodig%10];
  if(tens[twodig/10]==" ")
    return ones[twodig%10];
  return tens[twodig/10]+ones[twodig%10];
}

int main(){
  string buf="0";
  int cur;
  int number=111111;
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
