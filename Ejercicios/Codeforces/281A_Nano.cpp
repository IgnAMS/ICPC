#include<bits/stdc++.h>
using namespace std;
int main(){
  string linea;
  cin>>linea;
  if(linea[0]>='a' && linea[0]<='z') linea[0]+='A'-'a';
  cout<<linea<<endl;


  return 0;
}
