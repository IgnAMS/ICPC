#include<bits/stdc++.h>
using namespace std;
int main(){
  string linea;
  set<string> asd;
  while(cin>>linea){
    //if(linea=="0") break;
    string aux="";

    for(int i=0;i<linea.length();i++){
      if('A'<=linea[i] && linea[i]<='Z'){
        linea[i]+= -'A'+'a';
      }
      if(('a'<=linea[i] && linea[i]<='z') ||('A'<=linea[i] && linea[i]<='Z' && linea[i]) && linea[i]!=' '){
        aux+=linea[i];
      }

      if(linea[i]==' ' || i==linea.length()-1 || !('a'<=linea[i] && linea[i]<='z') ||('A'<=linea[i] && linea[i]<='Z' && linea[i]) ){
        //cout<<aux<<endl;
        asd.insert(aux);
        aux="";
      }
    }
  }
  set<string>::iterator it;
  for(it =asd.begin();it!=asd.end();++it){
    if(*it!="")
      cout<<*it<<endl;
  }



  return 0;
}
