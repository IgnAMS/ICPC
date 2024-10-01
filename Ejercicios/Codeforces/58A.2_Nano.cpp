#include<bits/stdc++.h>
using namespace std;
int main(){
  string linea;
  cin>>linea;
  char asd[]={'h','e','l','l','o'};
  int ind=0;
  bool yes=false;

  for(int i=0;i<linea.length();++i){
    if(linea[i]==asd[ind]){
      ind++;
      if(ind==5) {
        yes=true;
        break;
      }
    }
  }
  if(yes) cout<<"YES\n";
  else cout<<"NO\n";




  return 0;
}
