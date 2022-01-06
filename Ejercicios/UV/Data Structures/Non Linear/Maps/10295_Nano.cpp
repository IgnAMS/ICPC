#include<bits/stdc++.h>
using namespace std;
int main(){
  map<string,int> mapa;
  int m,n;
  cin>>m>>n;
  string linea;
  int dolar;
  vector<int> ans;
  for(int i=0;i<m;i++){
    cin>>linea>>dolar;
    mapa.insert(pair<string,int>(linea,dolar));
  }
  while(n--){
    int cont=0;
    while(cin>>linea){
      if(linea==".") break;
      if(mapa.count(linea)) cont+=mapa[linea];
    }
    ans.push_back(cont);
  }
  for(int i=0;i<ans.size();i++){
    cout<<ans[i]<<endl;
  }

  return 0;
}
