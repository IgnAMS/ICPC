#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin>>n;
  int sumx=0,sumy=0,sumz=0;
  int a,b,c;
  for(int i=0;i<n;i++){
    cin>>a>>b>>c;
    sumx+=a;
    sumy+=b;
    sumz+=c;
  }
  if(sumx==sumy && sumy==sumz && sumx==0){
    cout<<"YES\n";
  }
  else{
    cout<<"NO\n";
  }


  return 0;
}
