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
//  g++ -O2 D.cpp && time ./a.out < input.txt > output.txt
ll inf = 1000000;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    map<int, int> L, R;
    vi A(n); rep(i, n) cin>>A[i];
    rep(i, n) {
        if(!L.count(A[i])) L[A[i]] = 1000000, R[A[i]] = 0;
        L[A[i]] = min(L[A[i]], i);
        R[A[i]] = max(R[A[i]], i);
    }
    vector<ii> E;
    for(auto u: L) {
        if(R[u.ff] - u.ss >= 2) E.push_back(ii(u.ss, R[u.ff]));
    }
    sort(E.begin(), E.end());
    ll ans = 0;
    int lx = inf, rx = -inf;
    ll cost = 0;
    rep(i, E.size()){
        if(E[i].ff > rx) {
            if(lx != inf) ans += rx - lx - 1 - cost;
            lx = E[i].ff, rx = E[i].ss;
            cost = 0;
        }
        else {
            ll maxi = rx;
            while(i < E.size() and E[i].ff <= rx) maxi = max(maxi, E[i++].ss);
            i--;
            if(maxi > rx) cost++, rx = maxi;
        }
    }
    if(lx != inf) ans += rx - lx - 1 - cost;
    cout<<ans<<'\n';

    return 0;
}