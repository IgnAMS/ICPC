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
        ll n; cin>>n;
        ll A[n]; rep(i, n) cin>>A[i];
        ll B[n]; 
        multiset<ll> Unmatched, Matched;
        
        rep(i, n) {
            cin>>B[i];
            if(A[i] != B[i]) Unmatched.insert(B[i]);
            else Matched.insert(B[i]);
        }
        ll m; cin>>m;
        ll aux = 0;
        rep(i, m) {
            ll x; cin>>x;
            // Si x in Unmatched, lo matcheo
            if(Unmatched.count(x)) {
                Unmatched.erase(Unmatched.find(x));
                Matched.insert(x);
            }
            // Si x esta en los matcheds, lo mantengo
            else if(Matched.count(x)) {
                // si es que hay un unmatched random, me lo saco de encima
                aux = max(0LL, aux - 1);
            }
            // Si Unmatched.size() > 1 entonces se lo asigno a ese random y no me cambia
            // Caso contrario, aumento un contador
            else if(Unmatched.size() == 0) aux = 1;
        }
        // cout<<Matched.size()<<' '<<aux<<' '<<Unmatched.size()<<'\n';
        if(Unmatched.size() > 0 or aux > 0) cout<<"NO\n";
        else cout<<"YES\n";
    }

    return 0;
}