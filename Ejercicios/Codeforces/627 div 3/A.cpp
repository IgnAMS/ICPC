#include<bits/stdc++.h>
using namespace std;

bool check(vector<int> a){
  bool aux=true;
  for(int i=0;i<a.size();i++){
    if(a[i]>0) aux=false;
  }
  return aux;
}
int ind;
void erase(vector<int> &a){
  int mini= INT_MAX;
  for(int i=0;i<a.size();i++){
    if(a[i]<=mini){
      mini=a[i];
      ind=i;
    }
  }
  for(int i=0;i<a.size();i++) a[i]-=mini;
}

int main(){
  int t;
  cin>>t;
  vector<string> ans;
  while(t--){
    int n;
    cin>>n;
    vector<int> columns;
    int h;
    for(int i=0;i<n;i++){
      cin>>h;
      columns.push_back(h);
    }
    set<vector<int> > asd;
    while(!check(columns) && !asd.count(columns) ){
      asd.insert(columns);
      erase(columns);
      if(check(columns)) break;
      columns[ind]+=2;
      //for(int i=0;i<columns.size();i++) cout<<columns[i]<<" ";
      //cout<<endl;
    }
    if(asd.count(columns)) ans.push_back("NO");
    else ans.push_back("YES");
  }
  for(int i=0;i<ans.size();i++) cout<<ans[i]<<endl;

  return 0;
}
