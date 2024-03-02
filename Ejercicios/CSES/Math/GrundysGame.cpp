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

const int mxN = 2e3+5;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll G[mxN];
    G[1] = 0;
    repx(i, 2, mxN) {
        vl A(mxN, 0);
        repx(j, 1, (i+1)/2) {
            A[G[j] ^ G[i - j]] = 1;
        }
        int mex = mxN;
        rep(i, mxN) if(!A[i]) {
            mex = i;
            break;
        }
        G[i] = mex; 
    }

    ll t; cin>>t;
    while(t--) {
        ll n; cin>>n;
        if(n >= 2000) cout<<"first\n";
        else if(G[n] == 0) cout<<"second\n";
        else cout<<"first\n";
    }


    return 0;
}