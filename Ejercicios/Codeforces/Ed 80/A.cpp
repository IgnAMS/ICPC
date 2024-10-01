#include<bits/stdc++.h>
using namespace std;
int main(){
  int t;
  int n,d;
  cin>>t;
  while(t--){
    cin>>n>>d;
    if(d<=n) cout<<"YES\n";
    else{
      bool logrado=false;
      for(int i=1;i<=n+1;i++){
        int sub=i;
        int asd=d/i;
        if(d%i>0) asd++;
        if(asd+i-1<=n){
          logrado=true;
          //cout<<i-1<<endl;
          //cout<<"aaaaaaaaa\n";
          break;
        }

      }

      if(logrado) cout<<"YES\n";
      else cout<<"NO\n";
    }

  }



  return 0;
}
