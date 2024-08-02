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
    string s; cin>>s;
    int n = s.length();
    // vvvovvv -> [1,2,4,5,6] [1,2,4,6,7] [2,3,4,5,6] [2,3,4,6,7]
    ll L[n + 1], R[n + 1];
    // vvv -> 2 
    // vv -> 1
    // vvvv -> 3
    L[0] = 0;
    rep(i, n) {
        ll cnt = 0;
        while(i < n and s[i] == 'v') {
            cnt++;
            L[i + 1] = L[i];
            i++;
        }
        if(i < n) L[i] += (cnt > 1? (cnt - 1): 0);
        L[i + 1] = L[i];
    }
    R[n] = 0;
    for(int i = n - 1; i >= 0; i--) {
        ll cnt = 0;
        while(i >= 0 and s[i] == 'v') {
            cnt++;
            R[i] = R[i + 1];
            i--; 
        }
        R[i + 1] += (cnt > 1? (cnt - 1): 0);
        R[i] = R[i + 1];
    }
    // rep(i, n) cout<<L[i]<<' '; cout<<'\n';
    // rep(i, n) cout<<R[i]<<' '; cout<<'\n';
    ll ans = 0;
    repx(i, 1, n - 1) {
        // cout<<s[i]<<' '<<L[i]<<' '<<R[i]<<'\n';
        if(s[i] == 'o') ans += L[i] * R[i]; 
    }
    cout<<ans<<'\n';





    return 0;
}