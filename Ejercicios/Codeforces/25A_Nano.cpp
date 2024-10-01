#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin>>n;
  int Array[n];
  int par=0,impar=0;
  int indice;
  int parin,imparin;
  for(int i=0;i<n;i++){
    cin>>Array[i];
    if(Array[i]%2==0){
      par++;
      parin=i+1;
    }
    else {
      impar++;
      imparin=i+1;
    }
  }
  if(par>impar) cout<<imparin<<endl;
  else cout<<parin<<endl;
  return 0;
}
