#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin>>n;
  n++;
  int aux=n;

  int u= aux%10;
  aux/=10;
  int d= aux%10;
  aux/=10;
  int c=aux%10;
  aux/=10;
  int m=aux%10;

  while(m==c || m==d ||m==u || c==d || c==u || d==u){
    n++;
    aux=n;
    u= aux%10;
    aux/=10;
    d= aux%10;
    aux/=10;
    c=aux%10;
    aux/=10;
    m=aux%10;

  }
  cout<<n<<endl;





  return 0;
}
