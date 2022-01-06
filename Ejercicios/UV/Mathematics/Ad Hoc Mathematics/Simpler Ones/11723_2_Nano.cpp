#include<bits/stdc++.h>
using namespace std;
int main(){
  int a,b;
  int cont=0;
  while(cin>>a>>b){
    if(a==0 && b==0) break;

    cont++;
    double asd= a*1.0/b-1;
    //cout<<asd<<endl;
    int meh=asd;
    double dif= asd-meh*1.0;
    if(dif>0) meh++;

    cout<<"Case "<<cont<<": ";
    if(meh>26) cout<<"impossible"<<endl;
    else cout<<meh<<endl;

  }


  return 0;
}
