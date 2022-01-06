#include<bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin>>t;
  int a,b;
  while(t--){
    cin>>a>>b;
    double asd=(a-2)*1.0/3;
    double meh=(b-2)*1.0/3;
    int aux1=asd;
    int aux2=meh;
    if(asd-aux1>0) aux1++;
    if(meh-aux2>0) aux2++;
    cout<<aux1*aux2<<endl;
  }


  return 0;
}
