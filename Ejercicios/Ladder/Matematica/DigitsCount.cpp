#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma") // could make sigill runtime error
#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(ll i=a; i<b; i++)
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


vl S(ll x) {
    vl A(10, 0);
    ll left = 0, right = x;
    ll div = 1e8;
    // 100000000
    ll notcero = 0;
    rep(_, 9) { // digits
        ll d = (x / div) % 10;
        right -= d * div;
        // cerr<<left<<' '<<right<<'\n';
        if(x >= div) {
            if(d != 0) {
                A[0] += notcero * left * div;
                // cerr<<notcero * left * div<<' ';
            }
            else {
                A[0] += notcero * ((left - 1) * div + right + 1); 
                // cerr<<notcero * ((left - 1) * div + right + 1)<<' ';
            }
            repx(i, 1, d) {
                A[i] += (left + 1 - (d == 0)) * div;
                // cerr<<(left + 1) * div<<' ';
            }
            if(d != 0) {
                A[d] += (right + 1) + (left - (d == 0)) * div;
                // cerr<<(right + 1) + (left - (d == 0)) * div<<' ';
            }
            repx(i, d + 1, 10) {
                A[i] += left * div;
                // cerr<<left * div<<' ';
            }
            // cerr<<'\n';
        }
        notcero |= (d != 0);
        left = left * 10 + d;
        div /= 10;
    }
    return A;
}

// x2x -> 321 + 32... + 22... + 12... + 02... = right + 1 + left * div

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    ll a, b;
    while(cin>>a>>b and a) {
        vl A = S(a - 1), B = S(b);
        // rep(i, 10) cout<<A[i]<<' '; cout<<'\n';
        // rep(i, 10) cout<<B[i]<<' '; cout<<'\n';
        rep(i, 10) cout<<B[i] - A[i]<<" \n"[i==9]; 
    }
    

    return 0;
}