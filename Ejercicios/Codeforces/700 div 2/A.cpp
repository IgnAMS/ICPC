#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--){
        string linea; cin>>linea;
        for(int i=0;i<linea.length();i++){
            linea[i]= i%2==0? (linea[i]=='a'?'b':'a'):(linea[i]=='z'? 'y':'z');
        }
        cout<<linea<<"\n";
    }





    return 0;
}