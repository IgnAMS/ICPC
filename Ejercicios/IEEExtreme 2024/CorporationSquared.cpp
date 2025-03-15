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
    int n, q; cin>>n>>q;
    ll A[n], F[n]; 
    rep(i, n) cin>>A[i], F[i] = 0;
    while(q--) {
        int t;  cin>>t;
        if(t == 0) {
            ll l, r, c; cin>>l>>r>>c; l--, r--;
            repx(i, l, r + 1) {
                if(A[i] < c) F[i]++;
                if(A[i] > c) F[i]--;
                A[i] = c;
            }
        }
        if(t == 1) {
            ll l, r, c; cin>>l>>r>>c; l--, r--;
            ll sign = (c == 0? 0: (c < 0? -1: 1));
            repx(i, l, r + 1) {
                F[i] += sign;
                A[i] += c;
            }
        }
        if(t == 2) {
            ll l, r; cin>>l>>r; l--, r--;
            ll salario = 0;
            repx(i, l, r + 1) salario += A[i];
            ll g = __gcd(abs(salario), r - l + 1);
            cout<<salario / g<<"/"<<(r - l + 1) / g<<'\n';
        }
        if(t == 3) {
            ll l, r; cin>>l>>r; l--, r--;
            ll salario = 0;
            repx(i, l, r + 1) salario += F[i];
            ll g = __gcd(abs(salario), r - l + 1);
            cout<<salario / g<<"/"<<(r - l + 1) / g<<'\n';
        }
    }

    return 0;
}