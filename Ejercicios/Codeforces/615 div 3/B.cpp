#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
int main(){
  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    vector<ii> packs;
    int a,b;
    bool yes=true;
    for(int i=0;i<n;i++){
      cin>>a>>b;
      for(int j=0;j<packs.size();j++){
        //printf("a= %d, b=%d    ai= %d, bi= %d\n",a,b,packs[j].first,packs[j].second);
        if((a<packs[j].first && b>packs[j].second) || (a>packs[j].first && b<packs[j].second)) yes=false;
        if(!yes) break;
      }
      packs.push_back(ii(a,b));
    }
    if(!yes) cout<<"NO\n";
    else{
      cout<<"YES\n";
      sort(packs.begin(),packs.end());
      int posi=0,posj=0; //var en j es R y var en i es U
      for(int i=0;i<n;i++){
        int difj= packs[i].second-posj;
        int difi=packs[i].first-posi;
        posj=packs[i].second;
        posi=packs[i].first;
        for(int j=0;j<difi;j++) cout<<'R';
        for(int j=0;j<difj;j++) cout<<'U';
      }
      cout<<endl;
    }

  }

  return 0;
}
