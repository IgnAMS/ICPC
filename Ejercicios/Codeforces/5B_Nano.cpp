#include<bits/stdc++.h>
using namespace std;
int main(){
  bool cambio=false;
  vector<string> frase;
  string linea;
  int maxi=0;
  while(getline(cin,linea)){
    frase.push_back(linea);
    maxi=max((int)linea.length(),maxi);
    //cout<<maxi<<endl;
  }
  for(int i=0;i<maxi+2;++i){
    cout<<'*';
  }
  cout<<endl;
  for(int i=0;i<frase.size();i++){
    cout<<"*";
    int space=maxi-frase[i].length();
    //cout<<space<<endl;
    if(space%2!=0){
      if(cambio){
        for(int j=0;j<(int)space/2+1;j++){
          cout<<" ";
        }
        cout<<frase[i];
        for(int j=0;j<(int)space/2;j++){
          cout<<" ";
        }
      }
      else{
        for(int j=0;j<(int)space/2;j++){
          cout<<" ";
        }
        cout<<frase[i];
        for(int j=0;j<(int)space/2+1;j++){
          cout<<" ";
        }
      }
      cambio=!cambio;
    }
    else{
      for(int j=0;j<space/2;j++){
        cout<<" ";
      }
      cout<<frase[i];
      for(int j=0;j<space/2;j++){
        cout<<" ";
      }
    }
    cout<<"*"<<endl;
  }
  for(int i=0;i<maxi+2;i++){
    cout<<"*";
  }
  cout<<endl;


  return 0;

}
