#include<bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin>>t;
  while(t--){
    int a,b,n,s;
    cin>>a>>b>>n>>s;
    //tenemos a monedas de valor n y b monedas de valor 1
    int mona=s/n;
    if(mona>a) mona=a;
    int monb=s-mona*n;
    bool pos=true;
    if(monb>b) pos=false;
    //printf("se necesitan %d monedas de %d y %d monedas de 1\n",mona,n,monb);
    //printf("actualmente se tienen %d monedas de %d y %d monedas de 1\n",a,n,b);
    if(pos) cout<<"YES\n";
    else cout<<"NO\n";
  }

  return 0;
}
