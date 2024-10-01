#include<bits/stdc++.h>
using namespace std;
int main(){
  int a,b;
  cin>>a>>b;
  int p,v;
  v= min(a,b);
  p= (a+b-1)-v;
  cout<<p<<" "<<v<<endl;


  return 0;
}

