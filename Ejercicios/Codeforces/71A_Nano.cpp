#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin>>n;
  while(n--){
    string linea;
    cin>>linea;
    if(linea.length()<=10) cout<<linea<<endl;
    else{
      cout<<linea[0]<<linea.length()-2<<linea[linea.length()-1]<<endl;
    }
  }


  return 0;
}
