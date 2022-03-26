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
//  g++ -O2 D.cpp && time ./a.out < input.txt > output.txt

double eps = 1e-11;


bool choque(vector<ii>& P, int n, db t) {
    bool pos = 0;
    db lx = -2e15, rx = -2e15;
    bool positive = 0;
    rep(i, n) {
        positive |= P[i].ss > 0;
        if(P[i].ss > 0 and P[i].ff <= rx + eps) rx = max(rx, P[i].ff + t * P[i].ss);
        else if(P[i].ss > 0) lx = P[i].ff, rx = P[i].ff + t * P[i].ss;
        if(positive and P[i].ss < 0 and (P[i].ff + t * P[i].ss <= rx + eps or P[i].ff <= rx + eps)) {
            pos = 1;
        }
    }
    return pos;
}

db bs(vector<ii>& P, int n) {
    db l = 0, r = 1e9;
    rep(i, 100) {
        db m = (l + r) / 2;
        if(choque(P, n, m)) r = m;
        else l = m;
    }
    return (l + r) / 2.0;
}




int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll n; cin>>n;
    vector<ii> P(n);
    rep(i, n) cin>>P[i].ff>>P[i].ss;
    sort(P.begin(), P.end());
    bool positive = 0, posneg = 0;
    rep(i, n) {
        if(P[i].ss > 0) positive = 1;
        if(P[i].ss < 0 and positive) posneg = 1;
    }
    if(!posneg) {
        cout<<"-1\n";
        return 0;
    }
    cout<<setprecision(13)<<fixed<<bs(P, n)<<'\n';




    return 0;
}