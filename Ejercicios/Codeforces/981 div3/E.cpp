#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<ll, ll> pll;
typedef double db;
typedef vector<ll> vl;
#define ff first
#define ss second
#define pb push_back
// g++ -std=c++11 A.cpp -o a && a <input.txt> output.txt
// ulimit -s 1000000
// g++ -O2 D.cpp && time ./a.out <input.txt> output.txt

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--) {
        int n; cin>>n;
        ll P[n], Ind[n]; 
        
        rep(i, n) {
            cin>>P[i];
            P[i]--;
            Ind[P[i]] = i;
        }
        ll ans = 0;
        rep(i, n) {
            if(P[P[i]] != i) {
                // cout<<"entre con "<<i<<" cambio los indices "<<P[i]<<' '<<Ind[i]<<'\n';
                ll aux = Ind[i];
                ll prev = P[P[i]];
                swap(P[Ind[i]], P[P[i]]);
                Ind[prev] = aux;
                // cout<<"asigno a "<<prev<<" con indice "<<aux<<'\n';
                // rep(i, n) cout<<P[i]<<' '; cout<<'\n';
                ans++;
            }
        }
        // rep(i, n) cout<<P[i] + 1<<' '; cout<<'\n';
        cout<<ans<<'\n';
    }


    return 0;
}