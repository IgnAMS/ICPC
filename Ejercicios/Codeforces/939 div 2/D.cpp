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

vector<pll> Ops;
ll mx;
void ops(ll i, ll x, vl& A) {
    while(x == 0 and A[i] != x) {
        Ops.pb({i + 1, i + 1});
        if(A[i] == 0) A[i] = 1;
        else A[i] = 0;
    }
    if(x == 0) return;
    

    // x >= 1
    if(x != A[i]) {
        ops(i, x - 1, A);
        Ops.pb({i - x + 2, i + 1});
        repx(j, i - x + 1, i + 1) A[j] = x;
    }
    // voy a querer aumentar a i - 1 a x - 1
    if(x != mx) ops(i - 1, x - 1, A);
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    vl A(n); rep(i, n) cin>>A[i];

    ll best = 0, ans = 0;
    vector<pll> B;
    rep(mask, (1<<(n - 1))) {
        ll curr = 0, largo = 1;
        vector<pll> S;
        rep(i, n - 1) {
            if(mask & (1<<i)) largo++;
            else {
                if(largo == 1) {
                    if(A[i] == 0) curr += 1, S.pb({i, i});
                    else curr += A[i];
                }
                else {
                    curr += largo * largo;
                    S.pb({i - largo + 1, i});
                }
                largo = 1;
            }
        }
        if(largo == 1) {
            if(A[n - 1] == 0) S.pb({n - 1, n - 1}), curr += 1;
            else curr += A[n - 1];
        }
        else {
            curr += largo * largo;
            S.pb({n - largo, n - 1});
        }
        if(curr > best) best = curr, ans = mask, B = S;
    }
    for(auto& [a, b]: B) {
        ops(b, 0, A);
        ll largo = b - a + 1;
        mx = largo;
        ops(b, largo, A);
    }
    cout<<best<<' '<<Ops.size()<<'\n';
    for(auto& [a, b]: Ops) cout<<a<<' '<<b<<'\n';

    return 0;
}