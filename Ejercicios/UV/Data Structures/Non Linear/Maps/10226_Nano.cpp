#include<bits/stdc++.h>
using namespace std;
typedef pair<string,double> sd;
typedef pair<string,int> si;
typedef map<string,double> msd;

int main(){
  vector<msd> ans;
  int t;
  cin>>t;
  getchar();
  getchar();
  string linea;
  map<string,double>::iterator it;

  while(t--){
    int cont=0;
    map<string,double> mapa;
    while(getline(cin,linea)){
      if(linea=="") break;
      cont++;
      if(!mapa.count(linea)){
        mapa.insert(sd(linea,1));
      }
      else{
        mapa[linea]++;
      }
    }
    for(it=mapa.begin();it!=mapa.end();it++){
      it->second= it->second/cont*100.0;
    }
    ans.push_back(mapa);
  }
  for(int i=0;i<ans.size();i++){
    for(it=ans[i].begin();it!=ans[i].end();it++){
      cout<<it->first<<" "<<setprecision(4)<<fixed<<it->second<<endl;
    }
    if(i<ans.size()-1) cout<<endl;
  }


  return 0;
}
