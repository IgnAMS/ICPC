#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
int main(){
  int t;
  cin>>t;
  vector<iii> ans;
  while(t--){
    int n;
    cin>>n;
    deque<int> dulces;
    for(int i=0;i<n;i++){
      int h;
      cin>>h;
      dulces.push_back(h);
    }
    bool cambio=true;
    bool primer=true;
    int conta=0,contb=0,cont=0;
    int aux=0;
    int jug=0;
    while(!dulces.empty()){
      jug++;
      //cout<<"size: "<<dulces.size()<<endl;
      //cout<<cont<<endl;
      if(cambio){
        if(primer){
          conta+=dulces.front();
          cont=dulces.front();
          dulces.pop_front();
          primer=false;
        }
        else{
          while(aux<=cont){
            conta+=dulces.front();
            aux+=dulces.front();
            dulces.pop_front();
            if(dulces.empty()) break;
          }
          cont=aux;
          aux=0;
        }
      }
      else{
        while(aux<=cont){
          contb+=dulces.back();
          aux+=dulces.back();
          dulces.pop_back();
          if(dulces.empty()) break;
        }
        cont=aux;
        aux=0;
      }
      cambio=!cambio;
    }
    ans.push_back(iii(jug,ii(conta,contb)));
  }
  for(int i=0;i<ans.size();i++){
    cout<<ans[i].first<<" "<<ans[i].second.first<<" "<<ans[i].second.second<<endl;
  }
  return 0;
}
