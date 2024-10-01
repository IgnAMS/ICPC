#include<bits/stdc++.h>
using namespace std;

int elev(int a, int b){
  int mult=1;
  for(int i=0;i<b;i++){
    mult*=a;
  }
  return mult;
}


int main(){
  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    int aux=n;
    int cont=0;
    while(aux>0){
      int pot=log10(aux);
      int rest=elev(10,pot);
      cont+=rest;
      aux-=rest;
      //cout<<rest<<endl;
      aux+=rest/10;
    }
    //cout<<"aaaaa\n";

    cout<<cont<<endl;


  }


  return 0;
}
