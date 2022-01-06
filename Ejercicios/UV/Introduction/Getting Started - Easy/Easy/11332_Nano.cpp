#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  while(cin>>n){
    if(n==0) break;

    int aux=n;
    int aux2=aux;

    while(log10(aux)>=1.0){
      //cout<<aux<<" "<<log10(aux)<<endl;
      aux2=aux;
      int suma=0;
      while(aux!=0){
        suma+=aux%10;
        aux/=10;
      }
      aux=suma;
    }
    cout<<aux<<endl;
  }


  return 0;
}
