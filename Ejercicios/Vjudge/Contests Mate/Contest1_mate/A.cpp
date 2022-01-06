#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;

#define INF (int)1e9
#define pb push_back
#define OJ                            \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

ll DP[3002];

ll f(int pos){
    //si fue precomputado entonces retorna DP del numero
    if(DP[pos]!=-1) return DP[pos];
    int aux=pos;
    int cambio=0;
    bool primer=true;
    int cont=0;
    while(aux%2==0){
        aux/=2;
        if(primer){
            cambio++;
            primer=false;
        }
    }
    primer=true;
    for(int i=3;i<=sqrt(pos);i+=2){
        if(cambio > 2) return DP[pos]=f(pos-1);
        if(aux==1) break;
        while(aux%i==0){
            aux/=i;
            if(primer){
                cambio++;
                primer=false;
            }
        }
    }
    if(aux!=1){
        cambio++;
    }
    if(cambio==2) return DP[pos]=f(pos-1)+1;
    return DP[pos]=f(pos-1);
}


int main(){
    //OJ; 
    int n;
    cin>>n;
    memset(DP,-1,sizeof(DP));
    for(int i=1;i<=5;i++) DP[i]=0;
    cout<<f(n)<<endl;


    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}