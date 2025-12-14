#pragma GCC optimize("Ofast")
#include<iostream>
#include<vector>
#include<map>
#include<set>
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

const ll MOD = 998244353;

void solve(int caso) {
    int n, m; cin>>n>>m;
    if(n < m) {
        cout<<"Case #"<<caso<<": NO\n";
        return;
    }
    if(m == 1 and n == 1) {
        cout<<"Case #"<<caso<<": NO\n";
        return;
    }
    if(n == m) {
        cout<<"Case #"<<caso<<": YES\n";
        return;
    }
    // cout<<"Case #"<<caso<<": A: "<<(n-2)/2 + 2<<", B: "<<(n-1)/2<<"\n"; 
    ll A = (n-2)/2 +2, B = (n-1)/2;
    // cout<<A<<" "<<B<<" "<<m<<"\n";
    if(A == B + 2 and A >= m) cout<<"Case #"<<caso<<": YES\n";
    else cout<<"Case #"<<caso<<": NO\n";
}


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    repx(i, 1, t + 1) solve(i);
    
    return 0;
}