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

vl KMP(string &p) {
    int n = p.size();
    vl L(n); L[0] = 0;
    rep(j, n - 1) {
        int i = L[j]; 
        while(p[i] != p[j + 1] && i) i = L[i - 1];
        L[j + 1] = (p[i] == p[j + 1] ? i + 1 : 0);
    }
    return L;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    repx(cas, 1, t + 1) {
        cout<<"Test case #"<<cas<<'\n';
        int n; cin>>n;
        string s; cin>>s;
        
        vl L = KMP(s);
        vl Ans(n, 1);
        rep(i, n) {
            ll largo = i - L[i] + 1;
            if(largo and (i + 1) % largo == 0) Ans[i] = max(Ans[i], ll(i + 1) / largo);
            if(Ans[i] != 1) cout<<i + 1<<' '<<Ans[i]<<'\n';
        }
        cout<<'\n';
    }

    return 0;
}