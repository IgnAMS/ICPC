#include<bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin>>t;

  while(t--){
    int n;
    cin>>n;
    map<char,int> costo;
    char aux;
    int h;

    for(int i=0;i<n;i++){
      cin>>aux>>h;
      costo.insert(pair<char,int> (aux,h));
    }

    int lin;
    string linea;
    cin>>lin;
    getchar();
    int cont=0;

    for(int i=0;i<lin;i++){
      getline(cin,linea);
      for(int j=0;j<linea.length();j++){
        if(costo.count(linea[j])){
          cont+=costo[linea[j]];
        }
      }
    }
    int seg=cont%10;
    int asd=(cont%100-seg)/10;
    cont/=100;
    cout<<cont<<"."<<asd<<seg<<"$"<<endl;


  }



  return 0;
}
