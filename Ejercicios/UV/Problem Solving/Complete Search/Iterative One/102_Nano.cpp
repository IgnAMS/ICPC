#include<bits/stdc++.h>
using namespace std;
int main(){
  int b1,b2,b3;
  int g1,g2,g3;
  int c1,c2,c3;

  while(cin>>b1>>g1>>c1>>b2>>g2>>c2>>b3>>g3>>c3){
    string aux;
    int total=b1+g1+c1+b2+g2+c2+b3+g3+c3;
    //cout<<total<<endl;
    int mini= INT_MAX;
    if(total-b1-c2-g3<mini){
      aux="BCG";
      mini=total-b1-c2-g3;
    }
    if(total-b1-g2-c3<mini){
      aux="BGC";
      mini=total-b1-g2-c3;
    }
    if(total-c1-b2-g3<mini){
      aux="CBG";
      mini=total-c1-b2-g3;
    }
    if(total-c1-g2-b3<mini){
      aux="CGB";
      mini=total-c1-g2-b3;
    }
    if(total-g1-b2-c3<mini){
      aux="GBC";
      mini=total-g1-b2-c3;
    }
    if(total-g1-c2-b3<mini){
      aux="GCB";
      mini=total-g1-c2-b3;
    }
    cout<<aux<<" "<<mini<<endl;
  }
  return 0;
}
