#include<bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin>>t;
  vector<vector<double> > ans;
  int test=0;
  while(t--){
    int n;
    cin>>n;
    map<int,int> todas;
    vector<set<int> > cartas;
    set<int> aux;
    for(int i=0;i<n;i++){
      int h;
      aux.clear();
      cin>>h;
      int asd;
      for(int j=0;j<h;j++){
        cin>>asd;
        if(todas.count(asd) && !aux.count(asd)) todas[asd]++;
        else if(!todas.count(asd)) todas.insert(pair<int,int>(asd,1));
        aux.insert(asd);
      }
      cartas.push_back(aux);
    }
    vector<double> conts(cartas.size(),0);
    int cont=0;
    set<int>::iterator it;
    int total=0;

    for(int i=0;i<cartas.size();i++){
      cont=0;
      for(it=cartas[i].begin();it!=cartas[i].end();it++){
        if(todas[*it]==1) {
          //cout<<"la carta "<<*it<<" es unica y la posee "<<i<<endl;
          total++;
          cont++;
        }
      }
      conts[i]=cont;
    }
    for(int i=0;i<conts.size();i++){
      conts[i]/=total;
      conts[i]*=100.0;
      //cout<<conts[i]<<endl;
    }
    ans.push_back(conts);
  }
  for(int i=0;i<ans.size();i++){
    cout<<"Case "<<i+1<<":";
    for(int j=0;j<ans[i].size();j++){
      cout<<" "<<setprecision(6)<<fixed<<ans[i][j]<<"%";
    }
    cout<<endl;
  }

  return 0;
}
