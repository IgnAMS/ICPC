#include<bits/stdc++.h>
using namespace std;

int main(){
  string linea;
  cin>>linea;
  int cont1=0;
  int cont2=0;
  int maxi=0;

  for(int i=0;i<linea.length();i++){
    if(linea[i]=='('){
      cont1++;
      //cout<<cont1<<endl;
    }
    else if(linea[i]==')' && cont1>0){
      cont1--;
      cont2++;
    }
  }
  maxi=max(maxi,cont2*2);
  cout<<maxi<<endl;


  return 0;
}
