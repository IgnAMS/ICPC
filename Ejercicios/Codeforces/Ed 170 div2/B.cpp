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

const ll MOD = 1e9+7;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    
    ll X[100005];
    X[0] = 1;
    repx(i, 1, 100005) X[i] = X[i - 1] * 2LL % MOD; 

    ll N[t], K[t];
    rep(i, t) cin>>N[i];
    rep(i, t) cin>>K[i];
    rep(i, t) {
        cout<<X[K[i]]<<'\n';
    }


    return 0;
}