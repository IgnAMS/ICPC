#include<bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin>>t;
  vector<int> ans;
  while(t--){
    int n,k;
    cin>>n>>k;
    int asd=0;
    int resp=k;
    int rest=k/n;
    asd=rest;

    while(rest>0){
      //printf("resp: %d y rest: %d y asd: %d\n",resp,rest,asd);
      resp+=rest;
      rest=resp/n-asd;
      asd+=rest;
    }
    ans.push_back(resp);
  }
  for(int i=0;i<ans.size();i++){
    cout<<ans[i]<<endl;
  }


  return 0;
}
