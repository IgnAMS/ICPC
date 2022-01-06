#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;

int main(){

  int n;
  vector<vector<int> > ans;
  while(cin>>n){
    if(n==0) break;
    vector<ii> posicion;
    int a,b;
    for(int i=0;i<n;i++){
      cin>>a>>b;
      posicion.push_back(ii(a,b));
    }
    for(int h=0;h<150;h++){
      bool ohyea=true;
      for(int i=0;i<n;i++){
        ii v= posicion[i];
        ii aux;
        if(v.second!=0) ohyea=false;
        //cout<<"esto "<<posicion[i].first<<" "<<posicion[i].second<<" se transformo en ";
        int j;
        if(v.second<0){

          for(j=0;j<-1*v.second;j++){
            if(i-j-1<0) break;
            posicion[i-j].second++;
            aux=posicion[i-j];
            posicion[i-j-1].second--;
            posicion[i-j]=posicion[i-j-1];
            posicion[i-j-1]=aux;
          }
        }
        else if(v.second>0){
          for(j=0;j<v.second;j++){
            if(i+j+1>=n) break;
            posicion[i+j].second--;
            aux=posicion[i+j];
            posicion[i+j+1].second++;
            posicion[i+j]=posicion[i+j+1];
            posicion[i+j+1]=aux;
          }
        }
        //cout<<posicion[i].first<<" "<<posicion[i].second<<endl;
      }
      if(ohyea) break;
    }
    /*cout<<endl<<endl;
    for(int i=0;i<n;i++){
      printf("%d  %d \n",posicion[i].first,posicion[i].second);
    }
    cout<<endl<<endl;
    */

    bool yes=true;
    vector<int> asd;
    for(int i=0;i<n;i++){
      if(posicion[i].second!=0) yes=false;
    }
    if(!yes) asd.push_back(-1);
    else{
      for(int i=0;i<n;i++){
        asd.push_back(posicion[i].first);
      }
    }
    ans.push_back(asd);
  }
  for(int i=0;i<ans.size();i++){
    for(int j=0;j<ans[i].size();j++){
      cout<<ans[i][j];
      if(j<ans[i].size()-1) cout<<" ";
    }
    cout<<endl;
  }




  return 0;
}
