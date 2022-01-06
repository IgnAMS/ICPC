#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
    if (b == 0)
        return a;
    //cout<<b<<" "<<a%b<<endl;
    return gcd(b, a % b);
}


int main(){

  int a,b;
  cin>>a>>b;
  int d=gcd2(a,b);
  cout<<endl<<d<<endl;




}
