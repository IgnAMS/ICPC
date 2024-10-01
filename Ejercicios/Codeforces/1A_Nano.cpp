#include<bits/stdc++.h>
using namespace std;
int main(){
  double a,b,c;
  cin>>a>>b>>c;

  double x,d;
  x= a*1.0/c;
  d=b*1.0/c;
  int e=x;
  int f=d;
  double asdasdas=x-e;
  //cout<<x<<" "<<asdasdas<<endl;

  if(x-e>0) x=x-(x-e*1.0)+1;
  if(d-f>0) d=d-(d-f*1.0)+1;
  //cout<<x<<" "<<d<<endl;
  long long asd=x*d;
  cout<<asd<<endl;


  return 0;
}
