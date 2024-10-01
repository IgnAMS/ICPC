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

vl KMP(string& s) {
    int n = s.length();
    vl L(n, 0);
    rep(j, n - 1) {
        int i = L[j]; while (s[i] != s[j + 1] && i) i = L[i - 1];
        L[j + 1] = (s[i] == s[j + 1] ? i + 1 : 0);
    }
    return L;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    string s; cin>>s;
    int n = s.length();
    vl L = KMP(s);
    // rep(i, n) cout<<L[i]<<' '; cout<<'\n';
    
    set<ll> S;
    ll x = n - 1;
    while(x > 0) {
        // cout<<x<<' '<<L[x]<<'\n';
        S.insert(L[x]);
        x = L[x] - 1;
    }
    ll mx = 0;
    repx(i, 1, n - 1) {
        if(S.count(L[i])) mx = max(mx, L[i]);
    }
    string ans = "";
    rep(i, mx) ans += s[i];
    if(mx != 0) cout<<ans<<'\n';
    else cout<<"Just a legend\n";


    return 0;
}