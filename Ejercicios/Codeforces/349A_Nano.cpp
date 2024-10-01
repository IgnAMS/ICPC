#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  int money=0;
  int h;
  bool perdi=false;
  int cont25=0;
  int cont50=0;
  int cont75=0;
  int cont100=0;

  for(int i=0;i<n;i++){
    cin>>h;
    //cout<<cont25<<" "<<cont50<<" "<<cont75<<" "<<cont100<<endl;
    if(h==25){
      cont25++;
    }
    else if(h==50){
      if(cont25>=1){
        cont25--;
      }
      else{
        perdi=true;
        break;
      }
      cont50++;
    }
    else if(h==75){
      if(cont50>=1){
        cont50--;
      }
      else if(cont25>=2){
        cont25-2;
      }
      else{
        perdi=true;
        break;
      }
      cont75++;
    }
    else if(h==100){
      if(cont75>=1){
        cont75--;
      }
      else if(cont50>=1 && cont25>=1){
        cont25--;
        cont50--;
      }
      else if(cont25>=3){
        cont25-=3;
      }
      else{
        perdi=true;
        break;
      }
    }
  }
  if(perdi) cout<<"NO\n";
  else cout<<"YES\n";




  return 0;
}
