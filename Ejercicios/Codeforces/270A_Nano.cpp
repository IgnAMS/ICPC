#include<bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin>>t;
  while(t--){
  int n;
  cin>>n;
  if(n==180){
    cout<<"NO\n";
  }
  else if(360%(180-n)!=0){
    cout<<"NO\n";
  }
  else{
    cout<<"YES\n";
  }


  }

  return 0;
}
