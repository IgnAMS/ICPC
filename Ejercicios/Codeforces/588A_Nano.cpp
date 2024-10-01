#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  int meet[n],price[n];
  for(int i=0;i<n;i++){
    cin>>meet[i]>>price[i];
  }
  int cont=0;
  int minn=1000;
  for(int i=0;i<n;i++){
    minn=min(minn,price[i]);
    cont+=meet[i]*minn;
  }
  cout<<cont<<endl;

  return 0;
}
