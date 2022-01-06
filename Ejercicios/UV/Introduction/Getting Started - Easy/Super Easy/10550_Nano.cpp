#include<bits/stdc++.h>
using namespace std;
int main(){
  double vueltas=3.0;
  int pos;
  int pas1,pas2,pas3;
  while(cin>>pos>>pas1>>pas2>>pas3){
    if(pos==0 && pas1==0 && pas2==0 && pas3==0) break;
    int cont=0;
    while(pos!=pas1){
      //cout<<pos<<endl;
      pos--;
      cont++;
      if(pos<0) pos+=40;
    }
    while(pos!=pas2){
      //cout<<pos<<endl;
      pos++;
      cont++;
      if(pos>=40) pos-=40;
    }
    while(pos!=pas3){
      //cout<<pos<<endl;
      pos--;
      cont++;
      if(pos<0) pos+=40;
    }
    cout<<vueltas*360+cont*9<<endl;

  }


  return 0;
}
