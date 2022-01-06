#include<bits/stdc++.h>
using namespace std;

typedef pair<string,string> ss;
int main(){
  int n,g;
  cin>>n;
  map<string,string> mapa;
  string linea1,linea2;
  getchar();
  for(int i=0;i<n;i++){
    getline(cin,linea1);
    getline(cin,linea2);
    mapa.insert(ss(linea1,linea2));
  }
  cin>>g;
  getchar();
  for(int i=0;i<g;i++){
    getline(cin,linea1);
    cout<<mapa[linea1]<<endl;
  }


  return 0;
}
