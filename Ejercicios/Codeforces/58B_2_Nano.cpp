#include<bits/stdc++.h>
using namespace std;

int main(){

  int n;
  cin>>n;
  vector<int> div(n+1,0);
  int mult=1;
  int asd=2;
  int aux=n;

  while(mult!=n){
    if(aux%asd==0){
      aux/=asd;
      div[asd]++;
      mult*=asd;
    }
    else{
      asd++;
    }
  }

  mult=1;
  int ind=0;
  cout<<n;

  for(int i=0;i<div.size();i++){
    for(int j=0;j<div[i];j++){
      n/=i;
      cout<<" "<<n;
    }
  }

  cout<<endl;




  return 0;
}
