#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  while(cin>>n){

    if(n==0) return 0;
    int minim=INT_MAX;
    string planet;
    string linea;
    int llegada,demora;

    for(int i=0;i<n;i++){
      cin>>linea>>llegada>>demora;
      if(llegada-demora<minim){
        planet=linea;
        minim=llegada-demora;
      }
    }
    cout<<planet<<endl;

  }
  return 0;
}
