#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<ll, ll> pll;
typedef long double db;
typedef vector<ll> vl;
#define ff first
#define ss second
#define pb push_back
// g++ -std=c++11 A.cpp -o a && a <input.txt> output.txt
// ulimit -s 1000000
// g++ -O2 D.cpp && time ./a.out <input.txt> output.txt

const db EPS = 1e-8;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--) {
        int n; cin>>n;
        ll A[n];
        rep(i, n) cin>>A[i];

        bool notuno = 0;
        bool imp = 0;
        db X[n];
        rep(i, n) {
            if(A[i] != 1) notuno = 1;
            if(A[i] == 1 and notuno) {
                imp = 1;
                break;
            }
        }
        if(imp) {
            cout<<"-1\n";
            continue;
        }

        ll ans = 0;
        rep(i, n) { 
            if(A[i] != 1) {
                X[i] = log2(log(A[i]));
                // cout<<X[i]<<'\n';
                if(i and X[i] < X[i - 1]) {
                    ll k = 1 + (X[i - 1] - X[i] - 1e-8);
                    ans += k;
                    X[i] += k;
                }
            }
            else X[i] = -1000;
        }
        cout<<ans<<'\n';
    }
    

    return 0;
}