#include<bits/stdc++.h>
using namespace std;
int main(){
  int h;
  int l;
  cin>>h>>l;
  long double A= (l-h)/2.0/h;
  A*=(l+h);
  cout<<setprecision(10)<<fixed<<A<<endl;

  return 0;
}
