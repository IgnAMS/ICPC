#include<bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin>>t;
  while(t--){
    int n;
    int a,b,c;
    cin>>a>>b>>c>>n;
    int maxi=max(max(a,b),c);
    int A= maxi-a;
    int B= maxi-b;
    int C= maxi-c;
    n-=A+B+C;
    //cout<<n<<endl;
    if(n%3==0 && n>=0) cout<<"YES\n";
    else cout<<"NO\n";


  }

  return 0;
}
