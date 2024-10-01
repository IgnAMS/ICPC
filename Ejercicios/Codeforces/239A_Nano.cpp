#include<bits/stdc++.h>
using namespace std;
int main(){
  int y,n,k;
  cin>>y>>k>>n;
  bool asd=true;
  bool primer=true;
  int aux = -1*y%n;
  //cout<<aux<<endl;

  for(int i=aux+k ; i+y<=n ;i+=k){
      //cout<<i<<endl;
    if(i>=1){
      asd=false;
      if(!primer) cout<<" ";
      primer=false;
      cout<<i;
    }
  }

  if(asd){
    cout<<-1<<endl;
  }
  else{
    cout<<endl;
  }



  return 0;
}
