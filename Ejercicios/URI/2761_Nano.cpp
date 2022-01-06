#include <iostream>
#include<bits/stdc++.h>
#include<string>
using namespace std;



int main() {
  int entero;
  double decimal;
  char charac;
  string linea;
  string ayudante;
  vector<char> algo;

  cin>>entero>>decimal>>charac;
  bool state=false;
  getline(cin,linea);
  char y;
  int i=0;
  bool primer=true;

  if(linea[0]==' '){
    for(int i=0;i<linea.size()-1;i++){
      algo.push_back(linea[i+1]);
    }
  }
  else{
    for(int i=0;i<linea.size();i++){
      algo.push_back(linea[i]);
    }
  }

  //cout<<ayudante<<"   asdsad"<<endl;
  //cout<<i<<endl<<endl;
  cout<<entero<<decimal<<charac;
  for(int j=0;j<algo.size();j++){
    cout<<algo[j];
  }

  cout<<endl<<entero<<"\t"<<decimal<<"\t"<<charac<<"\t";
  for(int j=0;j<algo.size();j++){
    cout<<algo[j];
  }
  cout<<endl<<entero<<"\t  "<<decimal<<"\t  "<<charac<<"\t  ";
  for(int j=0;j<algo.size();j++){
    cout<<algo[j];
  }
  cout<<endl;


	return 0;
}
