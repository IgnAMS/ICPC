#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;

int DP[];



int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    string linea; cin>>linea;
    if(n%2!=0) { cout<<"0\n"; return 0; }
    int cont=0;
    for(int i=0;i<n;i++){
        char u=linea[i];
        if(u=='(') cont++;
        else cont--;
    }
    if(abs(cont)>1) { cout<<"0\n"; return 0; }




    return 0;
}