#include<bits/stdc++.h>
using namespace std;
int main(){
  string linea;
  int maxi=0;
  vector<string> lineas;
  while(getline(cin,linea)){
    //if(linea=="END") break;
    maxi=max(maxi,(int)linea.length());
    lineas.push_back(linea);

  }
  bool left=false;
  for(int i=0;i<maxi+2;i++) cout<<"*";
  cout<<endl;
  for(int i=0;i<lineas.size();i++){
    cout<<"*";
    int spaces= maxi-lineas[i].length();
    if(spaces%2!=0){
      int side1=spaces/2; //truncado
      int side2=spaces-side1; //grande
      if(left){
        for(int j=0;j<side2;j++) cout<<" ";
        cout<<lineas[i];
        for(int j=0;j<side1;j++) cout<<" ";
      }
      else{
        for(int j=0;j<side1;j++) cout<<" ";
        cout<<lineas[i];
        for(int j=0;j<side2;j++) cout<<" ";
      }
      left=!left;
    }
    else{
      for(int j=0;j<spaces/2;j++) cout<<" ";
      cout<<lineas[i];
      for(int j=0;j<spaces/2;j++) cout<<" ";
    }
    cout<<"*"<<endl;

  }
  for(int i=0;i<maxi+2;i++) cout<<"*";
  cout<<endl;


  return 0;
}
