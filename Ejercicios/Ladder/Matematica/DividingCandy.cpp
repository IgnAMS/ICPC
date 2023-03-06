#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma") // could make sigill runtime error
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

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    vl S(1e6, 0);
    rep(i, n) {
        int x; cin>>x;
        S[x]++;
    }
    ll imps = 0;
    rep(i, 1e6 - 1) {
        if(S[i] % 2) imps++;
        S[i + 1] += S[i] / 2;
    }
    if(imps <= 2 and n > 1) cout<<"Y\n";
    else cout<<"N\n";



    return 0;
}