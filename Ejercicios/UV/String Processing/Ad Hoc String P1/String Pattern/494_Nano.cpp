#include<bits/stdc++.h>
using namespace std;
int main(){
  string linea;
  while(getline(cin,linea)){
    int cont=0;
    bool pal=false;
    string help="";
    for(int i=0;i<linea.length();i++){
      if(('a'<=linea[i] && linea[i]<='z') || ('A'<=linea[i] && linea[i]<='Z')){
        pal=true;
        help+=linea[i];
      }
      else{
        if(pal){
          cont++;
          //cout<<help<<" "<<cont<<endl;
          help="";
          pal=false;
        }
      }
    }
    cout<<cont<<endl;
  }

  return 0;
}
