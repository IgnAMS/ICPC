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
        vl A(n); rep(i, n) cin>>A[i];
        
        vector<bool> X(n, 0);
        ll curr = 0;
        vl Ans(n);
        rep(i, n) {
            if(A[i] >= 1) {
                Ans[i] = curr;
                X[curr] = 1;
            }
            else {
                Ans[i] = curr - A[i];
                X[curr - A[i]] = 1;
            }
            while(X[curr]) curr++;
        }
        rep(i, n) cout<<Ans[i]<<' '; cout<<'\n';
    }


    return 0;
}