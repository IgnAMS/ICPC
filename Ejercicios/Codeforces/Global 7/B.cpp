#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  vector<int> asd;
  for(int i=0;i<n;i++){
    int h;
    cin>>h;
    asd.push_back(h);
  }
  int maxi=0;
  vector<int> num;
  for(int i=0;i<n;i++){
    //cout<<maxi<<endl;
    int xd=asd[i]+maxi;
    maxi=max(maxi,xd);
    cout<<xd;

    if(i<n-1) cout<<" ";
  }
  cout<<endl;


  return 0;
}
