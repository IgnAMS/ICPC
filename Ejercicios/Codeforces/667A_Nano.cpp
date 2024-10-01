#include<bits/stdc++.h>
using namespace std;
int main(){
  int d,h,v,e;
  cin>>d>>h>>v>>e;
  double pi= 3.1415926535;
  double area= d*d*pi*0.25;
  double vel= v/area;
  double xdd= 0.5;
  if(vel<=e){
    cout<<"NO\n";
  }
  else{
    double xdd=vel-e;
    double t= h/xdd;
    cout<<"YES\n";
    cout<<setprecision(10)<<fixed<<t<<endl;
  }




  return 0;
}
