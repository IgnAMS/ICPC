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
        ll A[n]; rep(i, n) cin>>A[i];
        set<ll> S = {0};
        ll curr = 0;
        bool pos = 0;
        rep(i, n) {
            curr += A[i] * (i % 2 == 0? -1LL: 1LL);
            if(S.count(curr)) pos = 1;
            S.insert(curr);
        }
        if(pos) cout<<"YES\n"; 
        else cout<<"NO\n";
    }


    return 0;
}