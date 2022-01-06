#include<bits/stdc++.h>
using namespace std;
int main () {
  int t;
  int contador=0;
  while(cin>>t){
    if(t==0) break; // una accion

    int cont=0; // mi respuesta
    int aux; //
    while(t--){ // t repeticiones
      cin>>aux;
      if(aux==0){
        cont--;
      }
      else{ // 1, 2, 3 , 4, 5, ...99
        cont++;
      }
    }
    contador++;
    cout<<"Case "<<contador<<": "<<cont<<"\n";
  }
  // aca
  return 0;
}
