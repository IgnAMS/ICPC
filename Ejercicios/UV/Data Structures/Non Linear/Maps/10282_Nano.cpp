#include<bits/stdc++.h>
using namespace std;
int main(){
  map<string,string> mapa;
  string linea,linea1,linea2;
  while(getline(cin,linea)){
    if(linea=="") break;
    bool change=true;
    linea1="";
    linea2="";
    for(int i=0;i<linea.length();i++){
      if(linea[i]==' '){
        change=false;
        continue;
      }
      if(change) linea1+=linea[i];
      else linea2+=linea[i];
    }
    mapa.insert(pair<string,string>(linea2,linea1));
  }

  while(cin>>linea){
    if(mapa.count(linea)) cout<<mapa[linea]<<endl ;
    else cout<<"eh"<<endl;
  }

  return 0;
}
