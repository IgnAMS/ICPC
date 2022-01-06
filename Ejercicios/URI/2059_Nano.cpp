#include<bits/stdc++.h>
using namespace std;

int main(){
  int j1,j2;
  bool p,r,a;
  cin>>p>>j1>>j2>>r>>a;
  int sum=j1+j2;
  if(r&&a){
    cout<<"Jogador 2 ganha!"<<endl;
  }
  else if(a&&!r){
    cout<<"Jogador 1 ganha!"<<endl;
  }
  else if(!a&&r){
    cout<<"Jogador 1 ganha!"<<endl;
  }
  else{
    if((sum%2==0&&p) || (sum%2!=0&&!p)){
      cout<<"Jogador 1 ganha!"<<endl;
    }
    else{
      cout<<"Jogador 2 ganha!"<<endl;
    }
  }

  return 0;
}
