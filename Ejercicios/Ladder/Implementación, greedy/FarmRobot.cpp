#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,c,s;
  cin>>n>>c>>s;
    int pos=1;
    int cont=0;
    int h;
    if(s==1) cont++;
    for(int i=0;i<c;i++){
      cin>>h;
      if(h==1) pos++;
      else pos--;
      if(pos>n) pos-=n;
      if(pos<1) pos+=n;
      if(pos==s) cont++;
    }
    cout<<cont<<endl;


  return 0;
}