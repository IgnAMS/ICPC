#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  vector<int> asd;
  int h;
  int xdd=0;
  for(int i=0;i<n;i++){
    cin>>h;
    asd.push_back(h);
    xdd=max(xdd,h);
  }
  sort(asd.begin(),asd.end(),greater<int>());
  //cout<<asd[0]<<endl;
  int maxi=0;

  for(int i=1;i<=xdd1;i++){
    h=i;
    if(h-1<asd.size()){
      if(asd[h-1]>=h){
        maxi=max(maxi,h);
        break;
      }
    }

  }
  cout<<maxi<<endl;

  return 0;
}
