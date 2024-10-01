#include<bits/stdc++.h>
using namespace std;

int main(){
  int a,b;
  cin>>a>>b;
  int x=min(a,b);
  unsigned int asd=1;
  for(int i=2;i<=x;i++){
    asd*=i;
  }
  cout<<asd<<endl;


  return 0;
}
