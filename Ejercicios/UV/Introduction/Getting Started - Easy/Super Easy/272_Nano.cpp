#include<bits/stdc++.h>
using namespace std;
int main(){
  string linea;
  bool asd=true;
  while(getline(cin,linea)){
    string str="";
    string aux="";

    for(int i=0;i<linea.length();i++){

      if(linea[i]=='"'){
        str.append(aux);
        aux="";
        if(asd){
          str.append("``");
          asd=!asd;
        }
        else{
          str.append("''");
          asd=!asd;
        }
      }
      else{
        aux+=linea[i];
      }
      if(i==linea.length()-1){
        str.append(aux);
      }
    }
    cout<<str<<endl;


  }


  return 0;
}
