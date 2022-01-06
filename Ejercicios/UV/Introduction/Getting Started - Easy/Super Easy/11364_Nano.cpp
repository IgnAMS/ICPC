#include<bits/stdc++.h>
using namespace std;
int main(){
  int t,n;
  cin>>t;
  while(t--){
    cin>>n;
    vector<int> local;
    int h;
    int sum=0;
    int mini=INT_MAX;
    int maxi=INT_MIN;

    for(int i=0;i<n;i++){
      cin>>h;
      local.push_back(h);
      sum+=h;
      mini=min(mini,h);
      maxi=max(maxi,h);
    }
    double prom= sum*1.0/n;
    //cout<<prom<<endl;
    double dist1=abs(prom-mini);
    double dist2=abs(prom-maxi);
    cout<<2*(dist1+dist2)<<endl;

  }


  return 0;
}
