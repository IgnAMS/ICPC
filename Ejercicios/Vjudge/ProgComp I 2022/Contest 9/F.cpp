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

int n;
vi Acc;
ll d = LLONG_MAX;
vector<ii> P;
void brute(ll l, ll r) {
    repx(i, l, r) repx(j, i + 1, r) {
        d = min(d, (i - j) * (i - j) + (Acc[i] - Acc[j]) * (Acc[i] - Acc[j]));
    }
}


void solve_seg(ll l, ll r) {
    
    if(r - l <= 3)  {
        brute(l, r);
        sort(P.begin() + l, P.begin() + r, [&](const auto& a, const auto& b){ 
            return a.ss < b.ss; 
        });
        return;
    }
    
    ll m = (l + r) / 2;
    solve_seg(l, m); solve_seg(m, r);

    vector<ii> Aux;
    ll a = l, b = m;
    ll xm = P[m].ff;
    while(a < m or b < r) {
        if(a == m) Aux.push_back(P[b++]);
        else if(b == r) Aux.push_back(P[a++]);
        else if(P[a].ss < P[b].ss) Aux.push_back(P[a++]);
        else Aux.push_back(P[b++]);
    }


    repx(i, l, r) P[i] = Aux[i - l];
    
    repx(i, l, r) if((P[i].ff - m) * (P[i].ff - m) < d) {
        for(ll j = i + 1; j < r and (P[j].ss - P[i].ss) * (P[j].ss - P[i].ss) < d; j++) { 
            d = min(d, (P[i].ff - P[j].ff) * (P[i].ff - P[j].ff) + (P[i].ss - P[j].ss) * (P[i].ss - P[j].ss));
        }
    }
    
    return;
}




int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    vi A(n); rep(i, n) cin>>A[i];
    
    Acc.assign(n, 0); 
    rep(i, n) Acc[i] = A[i];
    repx(i, 1, n) Acc[i] += Acc[i - 1];

    P.assign(n, {});
    rep(i, n) P[i] = {i, Acc[i]};

    solve_seg(0, n);
    cout<<d<<'\n';


    return 0;
}