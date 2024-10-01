#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;


int main(){
  int t; cin>>t;
  while(t--){
    int n; cin>>n;
    ll arr[n];
    vector<int> neg;
    vector<int> pos;
    for(int i=0;i<n;i++){
      cin>>arr[i];
      if(arr[i]>=0) pos.push_back(arr[i]);
      else neg.push_back(arr[i]);
    }
    sort(neg.begin(), neg.end());
    sort(pos.begin(), pos.end(),greater<int>());
    //cout<<neg[0]<<endl;
    ll mult=1;
    ll maxi=-1e18;

    if(pos.empty()){
      mult=1;
      for(int i=0;i<5;i++){
        mult*=neg[neg.size()-1-i];
      }
      maxi=max(maxi,mult);
    }

    if(pos.size()>=5){
      mult=1;
      for(int i=0;i<5;i++){
        mult*=pos[i];
      }
      maxi=max(maxi,mult);
    }

    if(neg.size()>=4 && pos.size()>=1){
      mult=1;
      for(int i=0;i<4;i++) mult*=neg[i];
      mult*=pos[0];
      maxi=max(maxi,mult);
    }

    if(neg.size()>=2 && pos.size()>=3){
      mult=1;
      for(int i=0;i<2;i++) mult*=neg[i];
      for(int i=0;i<3;i++) mult*=pos[i];
      maxi=max(maxi,mult);
    }

    if(n==5){
      mult=1;
      for(int i=0;i<n;i++) mult*=arr[i];
      maxi=max(maxi,mult);
    }


    cout<<maxi<<"\n";
  }

  return 0;
}
