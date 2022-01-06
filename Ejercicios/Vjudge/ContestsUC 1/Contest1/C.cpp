#include<bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin>>t;
  vector<int> ans;
  while(t--){
    int a;
    cin>>a;
    vector<int> asd;
    int h;
    for(int i=0;i<a;i++){
      cin>>h;
      asd.push_back(h);
    }
    sort(asd.begin(),asd.end(),greater<int>());
    int anss=1;
    for(int i=0;i<a;i++){
      if(asd[i]<i+1){
        break;
      }
      anss=i+1;
    }
    ans.push_back(anss);
  }
  for(int i=0;i<ans.size();i++){
    cout<<ans[i]<<endl;
  }

  return 0;
}
