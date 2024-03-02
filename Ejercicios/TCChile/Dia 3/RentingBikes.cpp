#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma") // could make sigill runtime error
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
    ll n, m, a; cin>>n>>m>>a;
    vl B(n); rep(i, n) cin>>B[i];
    vl P(m); rep(i, m) cin>>P[i];
    sort(B.begin(), B.end());
    sort(P.begin(), P.end());

    int l = 0, r = min(n, m);
    while(l < r) {
        ll mid = (l + r + 1) / 2;
        ll falta = 0;
        for(int i = n - mid, j = 0; i < n; i++, j++) {
            if(B[i] < P[j]) falta += P[j] - B[i];
        } 
        if(falta <= a) l = mid;
        else r = mid - 1;
    }
    ll falta = 0, coloca = 0;
    for(int i = n - l, j = 0; i < n; i++, j++) {
        if(B[i] < P[j]) falta += P[j] - B[i];
        coloca += min(B[i], P[j]);
    }
    cout<<l<<' '<<max(coloca - (a - falta), 0LL)<<'\n';

    return 0;
}