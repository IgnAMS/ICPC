#include<iostream>
#include<string>
using namespace std;

int main(){
  string linea;
  while(getline(cin,linea)){
    bool state=true;
    if(linea[0]=='*'){
      break;
    }
    else{
      char prim=linea[0];
      for(int i=0;i<linea.length();i++){
        if(linea[i]==' '){
          if(linea[i+1]!=prim && linea[i+1]+32!=prim && linea[i+1]-32!=prim){
            state=false;
            break;
          }
        }
      }
    }
    
    if(state){
      cout<<"Y"<<endl;
    }
    else{
      cout<<"N"<<endl;
    }
  }
  return 0;
}