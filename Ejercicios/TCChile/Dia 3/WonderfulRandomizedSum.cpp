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
    vl A(n); rep(i, n) cin>>A[i];
    ll l = 0, mxS = 0, curr = 0;
    pll ans = {-1,-1};
    rep(i, n) {
        curr += A[i];
        if(curr < 0) l = i + 1, curr = 0;
        if(curr > mxS) {
            mxS = curr;
            ans = {l, i};
        }
    }

    ll L = 0, R = 0;
    rep(i, ans.ff) L += A[i];
    repx(i, ans.ss + 1, n) R += A[i];
    // cout<<ans.ff<<' '<<ans.ss<<'\n';
    cout<<mxS - (L + R)<<'\n';


    return 0;
}