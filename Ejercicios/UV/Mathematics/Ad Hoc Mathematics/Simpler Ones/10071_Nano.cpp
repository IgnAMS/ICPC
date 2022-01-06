#include<bits/stdc++.h>
using namespace std;
int main(){
  int v,t;
  vector<int> a;
  while(cin>>v>>t){
    //cout<<v*2*t<<endl;
    //if(v==0 && t==0) break;
    a.push_back(v*2*t);
  }
  for(int i=0;i<a.size();i++){
    cout<<a[i]<<endl;
  }

  return 0;
}
