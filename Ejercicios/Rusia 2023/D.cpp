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


void match(string &p, string &t) {
    int n = p.size(), m = t.size(), L[n]; L[0] = 0;
    rep(j, n - 1) {
        int i = L[j]; while (p[i] != p[j + 1] && i) i = L[i - 1];
        L[j + 1] = (p[i] == p[j + 1] ? i + 1 : 0);
    }
    pll best = {-1, -1};
    int ans = 0, i = 0; 
    rep(j, m) {
        cout<<p[i]<<' '<<t[j]<<'\n';
        while(p[i] != t[j] && i) i = L[i - 1];
        
        cout<<i<<' '<<p[i]<<' '<<t[j]<<'\n';
        if(p[i] == t[j] && ++i == n) i = L[n - 1], ans++;
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    string s; cin>>s;
    int n = s.length();
    string s2 = "";
    for(int i = n - 1; i >= 0; i--) {
        if(s[i] == 'A') s2 += 'T';
        if(s[i] == 'T') s2 += 'A';
        if(s[i] == 'G') s2 += 'C';
        if(s[i] == 'C') s2 += 'G';
    }
    cout<<s2<<'\n';
    match(s, s2);



    return 0;
}