#include<bits/stdc++.h>
using namespace std;

int main() {
  int p,n;
  cin>>p>>n;
  int algo[n];
  bool state=true;
  for(int i=0;i<n;i++){
    cin>>algo[i];
    if(i!=0 && abs(algo[i]-algo[i-1])>p){
      state=false;
      break;
    }
  }
  if(state){
    cout<<"YOU WIN\n";
  }
  else{
    cout<<"GAME OVER\n";
  }





	return 0;
}
