#include<bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin>>t;
  double hot,cold,ideal;
  double mindif;
  while(t--){
    cin>>hot>>cold>>ideal;
    mindif=ideal;
    bool cambio=true;
    double dif=0;
    double cont=0;
    double tactual=0;
    double sum=0;
    int asd=0;
    while(true){
      if(cambio) sum=hot;
      else sum=cold;
      dif=(cont*tactual*1.0+sum*1.0)/((cont+1.0)*1.0);
      //cout<<cont*tactual+sum<<" "<<cont+1<<endl;
      //printf("la temperatura actual es %lf\n",dif);
      if(abs(dif-ideal)<=mindif){
        mindif=abs(dif-ideal);
        tactual=dif;
        cont++;
        cambio=!cambio;
        asd=0;
        if(mindif==0) break;
      }
      else{
        asd++;
        cont++;
        cambio=!cambio;
        tactual=dif;
        if(asd>=2){
          //cout<<"ahhhh\n"<<endl;
          break;
        }
      }
    }
    if(asd==2){
      cout<<cont-2<<endl;
    }
    else cout<<cont<<endl;
  }


  return 0;
}
