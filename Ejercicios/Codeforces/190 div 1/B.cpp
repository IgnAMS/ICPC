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

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m; cin>>n>>m;
    vl Def, At;
    rep(i, n) {
        string s; ll x; 
        cin>>s>>x;
        if(s == "ATK") At.pb(x);
        else Def.pb(x);
    }

    vl A(m); rep(i, m) cin>>A[i];
    
    sort(Def.begin(), Def.end());
    sort(At.begin(), At.end());
    sort(A.begin(), A.end());

    ll ans = 0;

    // Primera opcion, tomo todo
    multiset<ll> S;
    rep(i, m) S.insert(A[i]);
    
    bool pos = 1;
    for(auto u: Def) {
        if(S.upper_bound(u) == S.end()) {
            pos = 0;
            break;
        }
        ll x = *S.upper_bound(u);
        S.erase(S.find(x));
    }
    
    ll suma = 0;
    for(auto u: At) {
        if(S.lower_bound(u) == S.end()) {
            pos = 0;
            break;
        }
        ll x = *S.lower_bound(u);
        suma += x - u;
        S.erase(S.find(x));
    }
    for(auto u: S) suma += u;
    if(pos) ans = max(ans, suma);

    // Segunda opcion, tomo los primero i ataques
    for(int i = 1; i <= At.size(); i++) {
        suma = 0;
        for(int j = 0; j < i; j++) if(m - j - 1 >= 0) {
            suma += max(0LL, A[m - j - 1] - At[j]);
        }
        ans = max(ans, suma);
    }
    cout<<ans<<'\n';

    return 0;
}