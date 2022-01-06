#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  int a,b;
  int c,d;
  while(cin>>n){
    if(n==0) break;
    cin>>a>>b;
    for(int i=0;i<n;i++){
      cin>>c>>d;
      if(c==a || d==b) cout<<"divisa";
      else if(c>a && d>b) cout<<"NE";
      else if(c>a && d<b) cout<< "SE";
      else if(c<a && d>b) cout<<"NO";
      else if(c<a && d<b) cout<<"SO";
      cout<<endl;
    }
  }



}
