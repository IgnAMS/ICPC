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

struct E {
    int a, b; 
    bool operator<(const E& e) const { return a < e.a or (a == e.a and b < e.b); }
};


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    E X[n];
    rep(i, n) cin>>X[i].a>>X[i].b;
    sort(X, X + n);

    ll curr = 0;
    rep(i, n) {
        if(X[i].b < curr) curr = X[i].a;
        else curr = X[i].b;
    }
    cout<<curr<<'\n';


    return 0;
}