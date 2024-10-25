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

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--) {
        int n; cin>>n;
        ll A[n]; 
        rep(i, n) cin>>A[i];

        ll imps = 0, par = 0;
        ll mximp = 0;
        rep(i, n) {
            if(A[i] % 2 == 0) par++;
            else {
                imps++;
                mximp = max(mximp, A[i]);
            }
        }
        if(par == n or imps == n) {
            cout<<"0\n";
        }
        else {
            ll mayor = 0;
            vl X;
            rep(i, n) {
                if(A[i] % 2 == 0) X.pb(A[i]);
            }
            sort(X.begin(), X.end());
            for(auto u: X) {
                if(u > mximp) mayor = 1;
                mximp = mximp + u;
            }

            cout<<par + mayor<<'\n';
        }
    }


    return 0;
}