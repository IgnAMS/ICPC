#include<bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin>>t;
  while(t--){
    int n,m;
    cin>>n>>m;
    //vector<vector<int> > arr(n,vector<int> (m,0));
    int cont=0;
    int ans=(int)(m/2)*n;
    if(m%2==1) ans+=(n+1)/2;
    cout<<ans<<endl;
  }


  return 0;
}
