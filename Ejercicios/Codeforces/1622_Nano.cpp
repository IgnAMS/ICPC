#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,q;
  while(cin>>n>>q){
    if(n==0 && q==0) break;

    string linea;
    cin>>linea;
    string aux=linea;

    int k, m;
    for(int i=0;i<q;i++){
        aux=linea;
        int ind=0;
        //cout<<i<<endl;
        cin>>k>>m;

        for(int j=0;j<m;j++){
            if(aux[ind%n]=='x'){
                aux[ind%n]='o';
                //cout<<aux[ind%n]<<" ";
            }
            else {
                aux[ind%n]='x';
                //cout<<aux[ind%n]<<" ";
            }
            ind+=k;
        }
        for(int j=0;j<n;j++){
            cout<<aux[j];
        }
        cout<<endl;
    }
  }


	return 0;
}
