#include<bits/stdc++.h>
using namespace std;
int main(){
  string linea;
  cin>>linea;
  vector<char> nice;

  for(int i=0;i<linea.length();i++){
    if(linea[i]!='y' && linea[i]!='Y' && linea[i]!='a' && linea[i]!='A' && linea[i]!='e' && linea[i]!='E' && linea[i]!='i' && linea[i]!='I' && linea[i]!='o' && linea[i]!='O' && linea[i]!='u' && linea[i]!='U'){

      nice.push_back('.');
      if(linea[i]<'a'){
        linea[i]-='A'-'a';
      }
      nice.push_back(linea[i]);
    }
  }
  for(int i=0;i<nice.size();i++){
  cout<<nice[i];
  }
  cout<<endl;


  return 0;
}
