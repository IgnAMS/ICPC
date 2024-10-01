#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<ll, ll> ii;
typedef double db;
typedef vector<ll> vi;
#define ff first
#define ss second
// g++ -std=c++11 A.cpp -o a && a <input.txt> output.txt
// g++ -O2 D.cpp && time ./a.out <input.txt> output.txt

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--) {
        ll n, m; cin>>n>>m;
        vi A(n); rep(i, n) cin>>A[i];
        vector<ii> AP(n); 
        rep(i, n) {
            ll x = A[i];
            ll cant = 1;
            while(x % m == 0) x /= m, cant *= m;
            AP[i] = {x, cant};
        }
        vector<ii> AA;
        ll x = -1;
        rep(i, n) {
            if(AP[i].ff == x) AA.back().ss += AP[i].ss;
            else AA.push_back(AP[i]);
            x = AP[i].ff;
        }
        
        ll k; cin>>k;
        vi B(k); rep(i, k) cin>>B[i];
        
        vi P; // potencias de m
        x = 1;
        while(x < 1e11) {
            P.push_back(x);
            x *= m;
        }
        
        ll j = 0;
        bool pos = 1;
        rep(i, k) {
            // cout<<AA[j].ff<<' '<<B[i]<<'\n';
            if(j == AA.size()) { pos = 0; break; }
            ll aux = min(B[i] / AA[j].ff, AA[j].ss);
            aux = *prev(upper_bound(P.begin(), P.end(), aux));
            // cout<<aux<<' '<<AA[j].ff<<' '<<aux * AA[j].ff<<' '<<B[i]<<'\n'; 
            AA[j].ss -= aux;
            if(aux * AA[j].ff != B[i]) { pos = 0; break; }
            if(AA[j].ss == 0) j++;
        }
        if(j != AA.size()) pos = 0; // aun me quedan
        cout<<(pos? "Yes": "No")<<'\n';
    }





    return 0;
}