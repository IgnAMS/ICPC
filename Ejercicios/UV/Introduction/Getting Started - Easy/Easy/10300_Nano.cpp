#include<bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    int cont=0;
    int a,b,c;
    for(int i=0;i<n;i++){
      cin>>a>>b>>c;
      cont+=a*c;
      //cout<<a*c<<endl;
    }
    cout<<cont<<endl;

  }

  return 0;
}
