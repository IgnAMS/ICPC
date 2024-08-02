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

int match(vl &p, vl &t) {
    int n = p.size(), m = t.size();
    if(n == 0) return m + 1;
    if(m == 0) return 0;
    int L[n]; L[0] = 0;
    rep(j, n - 1) {
        int i = L[j]; while (p[i] != p[j + 1] && i) i = L[i - 1];
        L[j + 1] = (p[i] == p[j + 1] ? i + 1 : 0);
    }
    int ans = 0, i = 0; rep(j, m) {
        while (p[i] != t[j] && i) i = L[i - 1];
        if (p[i] == t[j] && ++i == n) i = L[n - 1], ans++;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, w; cin>>n>>w;
    vl A(n), D1(n - 1); 
    rep(i, n) {
        cin>>A[i];
        if(i) D1[i - 1] = A[i] - A[i - 1];
    }
    vl B(w), D2(w - 1); 
    rep(i, w) {
        cin>>B[i];
        if(i) D2[i - 1] = B[i] - B[i - 1];
    }

    cout<<match(D2, D1)<<'\n';


    return 0;
}