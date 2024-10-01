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
    ll mn = 1e10, mncont = 0, mx = 0, mxcont = 0;
    rep(i, n) {
        if(A[i] < mn) mn = A[i], mncont = 1;
        else if(A[i] == mn) mncont++;
        if(A[i] > mx) mx = A[i], mxcont = 1;
        else if(A[i] == mx) mxcont++;
    }
    if(mx == mn) cout<<0<<' '<<mncont * (mncont - 1) / 2<<'\n';
    else cout<<mx - mn<<' '<<mncont * mxcont<<'\n';

    return 0;
}