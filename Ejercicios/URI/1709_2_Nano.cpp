#include<bits/stdc++.h>;
using namespace std;
int main(){
  vector<int> Or;
  vector<int> aux;
  vector<int> xd;
  int n;
  cin>>n;
  //for(n=2;n<=100;n+=2){
  Or.clear();
  aux.clear();
  xd.clear();

  for(int i=0;i<n;i++){
    Or.push_back(i+1);
  }
  for(int i=0;i<n/2;i++){
    xd.push_back(Or[i+n/2]);
    xd.push_back(Or[i]);

  }
  int cont=1;
  //xd.push_back(1000);

  bool switchh=true;
  while((switchh && xd[0]!=1)||(!switchh && aux[0]!=1)){
    cont++;
    if(switchh){
      for(int i=0;i<n;i++){
        //cout<<xd[i]<<" ";
      }
      //cout<<endl;
    }
    else {
      for(int i=0;i<n;i++){
        //cout<<aux[i]<<" ";
      }
      //cout<<endl;
    }

    for(int i=0;switchh && i<n/2;i++){
      aux.push_back(xd[n/2+i]);
      aux.push_back(xd[i]);
    }
    for(int i=0;!switchh && i<n/2;i++){
      xd.push_back(aux[n/2+i]);
      xd.push_back(aux[i]);
    }
    if(!switchh) aux.clear();
    else xd.clear();
    switchh=!switchh;
  }
  cout<<cont<<endl;

  //}
  return 0;
}
