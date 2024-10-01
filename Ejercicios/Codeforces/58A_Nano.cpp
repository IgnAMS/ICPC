#include<bits/stdc++.h>
using namespace std;

int main(){
  string linea;
  cin>>linea;
  bool yes=false;
  for(int f=0;f<linea.length()-4;f++){
    for(int i=f+1;i<linea.length()-3;i++){
      for(int j=i+1;j<linea.length()-2;j++){
        for(int h=j+1;h<linea.length()-1;h++){
          for(int g=h+1;g<linea.length();g++){
            if(linea[f]=='h' && linea[i]=='e' && linea[j]=='l' && linea[h]=='l' && linea[g]=='o'){
              yes=true;
              break;
            }
          }
        }
      }
    }
  }
  if(yes) cout<<"YES\n";
  else cout<<"NO\n";




  return 0;
}
