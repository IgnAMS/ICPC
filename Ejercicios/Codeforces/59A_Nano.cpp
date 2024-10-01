#include<bits/stdc++.h>
using namespace std;
int main(){
  string linea;
  cin>>linea;
  int mayus=0,minus=0;

  for(int i=0;i<linea.length();i++){
    if(linea[i]>='A' && linea[i]<='Z') mayus++;
    else minus++;
  }
  if(mayus>minus){
    for(int i=0;i<linea.length();i++){
      if(linea[i]>='a' && linea[i]<='z') linea[i]+='A'-'a';
    }
  }
  else{
    for(int i=0;i<linea.length();i++){
      if(linea[i]>='A' && linea[i]<='Z') linea[i]-='A'-'a';
    }
  }
  cout<<linea<<endl;



  return 0;
}
