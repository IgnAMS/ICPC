#include<bits/stdc++.h>
using namespace std;
int main(){
  int a,b,n;
  cin>>a>>b>>n;
  int Array[n];
  n--;
  Array[0]=a;
  Array[1]=b;

  for(int i=1;i+1<=n;i++){
    Array[i+1]=Array[i]&1000000007-Array[i-1]%1000000007;
  }
  cout<<Array[n]<<endl;

  //1000000007

  return 0;
}
