#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(ll i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<ll, ll> ii;
typedef double db;
typedef vector<ll> vi;
#define ff first
#define ss second
// g++ -std=c++11 A.cpp -o a && a <input.txt> output.txt
// g++ -O2 D.cpp && time ./a.out <input.txt> output.txt


vi Acc;

ll brute(ll l, ll r) {
    ll mn = (l - r) * (l - r) + (Acc[r] - Acc[l]) * (Acc[r] - Acc[l]);
    repx(i, l, r + 1) repx(j, i + 1, r + 1) 
        mn = min(mn, (i - j) * (i - j) + (Acc[i] - Acc[j]) * (Acc[i] - Acc[j]));
    return mn;
}

ll strip(vector<ii>& P, ll d) {
    sort(P.begin(), P.end());
    rep(i, P.size()) 
        for(ll j = i + 1; j < P.size() and (P[i].ff - P[j].ff) * (P[i].ff - P[j].ff) < d; j++)
            d = min(d, (P[i].ff - P[j].ff) * (P[i].ff - P[j].ff) + (P[i].ss - P[j].ss) * (P[i].ss - P[j].ss));
    return d;
}

ll solve_seg(ll l, ll r) {
    if(r - l <= 3) return brute(l, r);
    ll m = (l + r) / 2;
    ll d = min(solve_seg(l, m), solve_seg(m + 1, r));
    vector<ii> P;
    repx(i, l, r + 1) if((i - m) * (i - m) < d) P.push_back({Acc[i], i});
    cerr<<"La sol del seg "<<l<<' '<<r<<" es: "<<strip(P, d)<<'\n'; 
    return min(strip(P, d), d);
}




int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    vi A(n); rep(i, n) cin>>A[i];
    Acc.assign(n, 0); 
    rep(i, n) Acc[i] = A[i];
    repx(i, 1, n) Acc[i] += Acc[i - 1];

    cout<<solve_seg(0, n - 1)<<'\n';


    return 0;
}