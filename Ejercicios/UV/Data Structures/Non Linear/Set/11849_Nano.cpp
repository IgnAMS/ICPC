#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,m;
  while(cin>>n>>m){
    if(n==0 && m==0) break;
    set<int> asd;
    int h;
    for(int i=0;i<n;i++){
      cin>>h;
      asd.insert(h);
    }
    int cont=0;
    for(int i=0;i<m;i++){
      cin>>h;
      if(asd.count(h)) cont++;
    }
    cout<<cont<<endl;
  }

  return 0;
}
