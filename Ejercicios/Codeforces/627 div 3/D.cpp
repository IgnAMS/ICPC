#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  vector<int> teach;
  set<int> mevale;
  map<int,int> mapa;
  set<int>::iterator it;
  int h;
  for(int i=0;i<n;i++){
    cin>>h;
    teach.push_back(h);
  }
  int cont=0;
  for(int i=0;i<n;i++){
    cin>>h;
    int dif=teach[i]-h;
    int total=i;

    for(it=mevale.begin();it!=mevale.end();++it){
      if(*it+dif>0){
        cont+=total;
        break;
      }
      total-=mapa[*it];
    }

    mevale.insert(dif);
    if(mapa.count(dif)) mapa[dif]++;
    else mapa.insert(pair<int,int> (dif,1));
  }
  cout<<cont<<endl;


  return 0;
}
