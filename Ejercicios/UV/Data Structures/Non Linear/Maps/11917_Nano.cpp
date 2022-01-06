#include<bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin>>t;
  vector<string> ans;
  while(t--){
    int n;
    cin>>n;
    int d;
    string linea;
    map<string,int> mapa;
    for(int i=0;i<n;i++){
      cin>>linea>>d;
      mapa.insert(pair<string,int>(linea,d));
    }
    int D;
    cin>>D;
    cin>>linea;
    if(!mapa.count(linea)) ans.push_back("Do your own homework!");
    else if(mapa[linea]<=D) ans.push_back("Yesss");
    else if(D<mapa[linea] && mapa[linea]<=D+5) ans.push_back("Late");
    else ans.push_back("Do your own homework!");
  }
  for(int i=0;i<ans.size();i++){
    cout<<"Case "<<i+1<<": "<<ans[i]<<endl;
  }


  return 0;
}
