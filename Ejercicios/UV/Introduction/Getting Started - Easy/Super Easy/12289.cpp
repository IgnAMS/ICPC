#include<bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin>>t;
  while(t--){
    string linea;
    cin>>linea;
    string uno="one";
    string dos="two";
    string tres="three";
    int error=0;
    for(int i=0;i<linea.length() && linea.length()==3;i++){
      if(linea[i]!=uno[i]) error++;
    }
    if(linea.length()==5){
      cout<<3<<endl;
    }
    else if(error<=1){
      cout<<1<<endl;
    }
    else{
      cout<<2<<endl;
    }
  }

  return 0;
}
