#include<bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin>>t;
  vector<string> ans;
  while(t--){
    int n;
    cin>>n;
    int h;
    map<int,int> conts;
    vector<int> a;
    bool yep=false;
    for(int i=0;i<n;i++){
      cin>>h;
      if(conts.count(h)){
        conts[h]++;
        if(a[a.size()-1]!=h) yep=true;
      }
      else conts.insert(pair<int,int>(h,1));
      if(conts[h]>=3) yep=true;
      a.push_back(h);
    }
    if(yep){
      ans.push_back("YES");
    }
    else{
      ans.push_back("NO");
    }

  }
  for(int i=0;i<ans.size();i++) cout<<ans[i]<<endl;

  return 0;
}
