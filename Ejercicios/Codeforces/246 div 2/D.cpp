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

vl KMP(string& p) {
    int n = p.size(); 
    vl L(n, 0);
    rep(j, n - 1) {
        int i = L[j]; while (p[i] != p[j + 1] && i) i = L[i - 1];
        L[j + 1] = (p[i] == p[j + 1] ? i + 1 : 0);
    }
    return L;
}


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    string s; cin>>s;
    int n = s.length();
    vl kmp = KMP(s);
    
    vl L(n, 0);
    for(int i = n - 1; i >= 0; i--) {
        L[i]++;
        if(kmp[i] != 0) L[kmp[i] - 1] += L[i];
    }

    vector<pll> Ans;
    int u = n - 1;
    Ans.pb({u + 1, L[u]});
    while(kmp[u] > 0) {
        u = kmp[u] - 1;
        Ans.pb({u + 1, L[u]});
    }
    reverse(Ans.begin(), Ans.end());

    cout<<Ans.size()<<'\n';
    for(auto [l, c]: Ans) cout<<l<<' '<<c<<'\n';

    return 0;
}