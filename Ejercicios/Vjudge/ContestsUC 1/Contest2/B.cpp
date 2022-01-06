#include<bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin>>t;
  while(t--){
    int l1,r1,l2,r2;
    cin>>l1>>r1>>l2>>r2;
    vector<int> ans1;
    vector<int> ans2;
    for(int i=l1;i<=r1;i++){
      ans1.push_back(i);
      if(ans1.size()>=2) break;
    }
    for(int i=l2;i<=r2;i++){
      ans2.push_back(i);
      if(ans2.size()>=2) break;
    }
    if(ans1[0]!=ans2[0]){
      cout<<ans1[0]<<" "<<ans2[0]<<endl;
    }
    else{
      cout<<ans1[1]<<" "<<ans2[0]<<endl;
    }
  }


  return 0;
}
