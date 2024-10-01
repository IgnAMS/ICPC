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
    int t; cin>>t;
    while(t--) {
        int n; cin>>n;
        vector<vl> A(n, vl(n));
        rep(i, n) rep(j, n) cin>>A[i][j];
        ll aux = (1LL<<30) - 1;
        vl Ans(n, aux); 
        rep(i, n) rep(j, n) if(i != j) Ans[i] &= A[i][j];

        bool valid = 1;
        rep(i, n) rep(j, n) if(i != j) {
            if(A[i][j] != (Ans[i] | Ans[j])) valid = 0;
            // if(A[i][j] != (Ans[i] | ))
        }
        if(valid) {
            cout<<"YES\n";
            rep(i, n) cout<<Ans[i]<<' '; cout<<'\n';    
        }
        else cout<<"NO\n";
        

    }





    return 0;
}