#include <iostream>
#include<bits/stdc++.h>
using namespace std;



int main() {
  int N,V;
  vector<int> v;
  while(cin>>N>>V){
    if(N==0&&V==0) break;

    v.clear();
    int cont=0;
    bool state=false;
    while(V>=0&&!state){
      for(int i=0;i<V;i++){
        cont+=V;
        if(cont==N) {
          state=true;
          break;
        }

        int help=cont;
        for(int j=0;j<v.size();j++){
          help-=v[j];
          if(help<0) break;
          if(help==N){
            state=true;
            break;
          }
        }
      }
      v.push_back(V*V);
      V--;
    }
    if(state) cout<<"possivel\n";
    else cout<<"impossivel\n";

  }




	return 0;
}
