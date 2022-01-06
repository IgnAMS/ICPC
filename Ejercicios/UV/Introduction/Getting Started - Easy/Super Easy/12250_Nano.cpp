#include<bits/stdc++.h>
using namespace std;
int main(){
  string linea;
  string ans;
  int cont=0;
  while(cin>>linea){
    cont++;
    if(linea=="HELLO") ans=      "ENGLISH";
    else if(linea=="HOLA") ans=  "SPANISH";
    else if(linea=="HALLO") ans= "GERMAN";
    else if(linea=="BONJOUR") ans=  "FRENCH";
    else if(linea=="CIAO") ans=  "ITALIAN";
    else if(linea=="ZDRAVSTVUJTE") ans=  "RUSSIAN";
    else if(linea=="#") break;
    else ans="UNKNOWN";
    printf("Case %d: %s\n",cont,ans.c_str());

  }

  return 0;
}
