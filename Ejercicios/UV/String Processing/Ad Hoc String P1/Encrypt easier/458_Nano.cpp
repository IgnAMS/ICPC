#include<bits/stdc++.h>
using namespace std;
int main(){
  string linea;
  while(getline(cin,linea)){
    for(int i=0;i<linea.length();i++){
      linea[i]+= 'C'-'J';
    }
    cout<<linea<<endl;
  }


  return 0;
}
