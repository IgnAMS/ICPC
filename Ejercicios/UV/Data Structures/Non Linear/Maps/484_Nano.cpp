#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
int main(){
  int a;
  map<int,int> mapa;
  map<int,int>::iterator it;
  vector<int> asd;
  while(cin>>a){
    if(!mapa.count(a)){
      mapa.insert(ii(a,1));
      asd.push_back(a);
    }
    else{
      mapa[a]++;
    }
  }
  for(int i=0; i<asd.size();i++){
    cout<<asd[i]<<" "<<mapa[asd[i]]<<endl;
  }


  return 0;
}
