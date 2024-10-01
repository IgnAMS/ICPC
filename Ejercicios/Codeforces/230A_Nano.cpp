#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,s;
  cin>>s>>n;
  vector<pair<int,int> > drag;

  for(int i=0;i<n;i++){
    int h,j;
    cin>>h>>j;
    pair<int,int> aux (h,j);
    drag.push_back(aux);
  }
  sort(drag.begin(),drag.end());

  bool win=true;
  for(int i=0;i<n;i++){
    if(s>drag[i].first){
      s+=drag[i].second;
    }
    else{
      win=false;
      break;
    }
  }
  if(win) cout<<"YES\n";
  else cout<<"NO\n";


  return 0;
}
