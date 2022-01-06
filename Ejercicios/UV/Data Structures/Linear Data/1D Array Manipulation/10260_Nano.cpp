#include<bits/stdc++.h>
using namespace std;
int main(){
  string linea;
  while(cin>>linea){
    string aux="";
    for(int i=0;i<linea.length();i++){
      if((linea[i]=='B' || linea[i]== 'F' || linea[i]== 'P' || linea[i]== 'V')){
        if(i>0){
          if(!(linea[i-1]=='B' || linea[i-1]== 'F' || linea[i-1]== 'P' || linea[i-1]== 'V'))
            aux+='1';
        }
        else aux+='1';
      }
      if((linea[i]=='C' || linea[i]== 'G' || linea[i]== 'J' || linea[i]== 'K' || linea[i]== 'Q' || linea[i]== 'S' || linea[i]== 'X' || linea[i]== 'Z')){
        if(i>0){
          if(!(linea[i-1]=='C' || linea[i-1]== 'G' || linea[i-1]== 'J' || linea[i-1]== 'K' || linea[i-1]== 'Q' || linea[i-1]== 'S' || linea[i-1]== 'X' || linea[i-1]== 'Z'))
            aux+='2';
        }
        else aux+='2';
      }
      if(linea[i]=='D' || linea[i]== 'T'){
        if(i>0){
          if(!(linea[i-1]=='D' || linea[i-1]== 'T'))
            aux+='3';
        }
        else aux+='3';
      }
      if(linea[i]=='L'){
        if(i>0){
          if(!(linea[i-1]=='L'))
            aux+='4';
        }
        else aux+='4';
      }
      if(linea[i]=='M' || linea[i]== 'N'){
        if(i>0){
          if(!(linea[i-1]=='M' || linea[i-1]== 'N'))
            aux+='5';
        }
        else aux+='5';
      }
      if(linea[i]=='R'){
        if(i>0){
          if(!(linea[i-1]=='R'))
            aux+='6';
        }
        else aux+='6';
      }

    }
    cout<<aux<<endl;
  }


  return 0;
}
