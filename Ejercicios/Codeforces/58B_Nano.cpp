#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin>>n;
  vector<vector<int> > div;
  int maxi=0;
  int ind;

  for(int i=n-1;i>=1;i--){
    bool xd=true;
    if(n%i==0){
      for(int j=0;j<div.size();j++){
        if(div[j][div[j].size()-1]%i==0){
          xd=false;
          div[j].push_back(i);
          if(div[j].size()>maxi){
            maxi=div[j].size();
            ind=j;
          }
        }
      }
      if(xd){
        vector<int> aux;
        aux.push_back(i);
        div.push_back(aux);
        if(aux.size()>maxi){
          maxi=aux.size();
          ind=div.size()-1;
        }
        aux.clear();
      }
    }
  }
  //printf("hay %d vectores\n",div.size());
  cout<<n;
  for(int i=0;i<div[ind].size();i++){
    cout<<" "<<div[ind][i];
  }
  cout<<endl;





  return 0;
}
