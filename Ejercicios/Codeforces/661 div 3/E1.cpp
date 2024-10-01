#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll DP[int(1e5+1)][21];
//la dp me indica que dada la cantidad de operaciones que he hecho cuanto es el minimo para que el nodo este de pana

ll s;
ll edgep[int(1e5+1)]; 
//peso del nodo que conecta el padre con el hijo
int p[int(1e5+1)]; //el padre del nodo u
ll dp(ll k,ll u,ll x){
    if(k<=s) return 0;
    if(DP[u][x]!=-1) return DP[u][x];
    if(u==x) 
    

    //le pregunto cuanto necesito para que el nodo actual este de pana
    DP[u][x]=dp(k,p[u],1);
}


int main(){




    return 0;
}