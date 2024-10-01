#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin>>n;
  n++;
  int u,d,c,m;
  u=n%10;
  d= (n%100-u)/10;
  c= (n%1000-d*10-u)/100;
  m= (n%10000-c*100-d*10-u)/1000;
  bool entre=false;

  while(u==d || u==c || u==m || d==c || d==m || c==m){
    u=n%10;
    d= (n%100-u)/10;
    c= (n%1000-d*10-u)/100;
    m= (n%10000-c*100-d*10-u)/1000;
    n++;
    entre=true;
  }
  if(entre) cout<<n-1<<endl;
  else cout<<n<<endl;



  return 0;
}
