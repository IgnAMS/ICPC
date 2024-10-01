#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,t,c;
  cin>>n>>t>>c;
  int Array[n];
  int cont=0;
  int ans=0;

  for(int i=0;i<n;i++){
    cin>>Array[i];
    if(Array[i]<=t) cont++;
    else{
      if(cont>=c){
        ans+=cont-c+1;
      }

      cont=0;
    }
  }
  if(cont>=c){
    ans+=cont-c+1;
  }
  cout<<ans<<endl;






  return 0;
}
