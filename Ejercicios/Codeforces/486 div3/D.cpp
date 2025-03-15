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
    int n; cin>>n;
    ll A[n]; 
    multiset<ll> S;
    rep(i, n) {
        cin>>A[i];
        S.insert(A[i]);
    }

    rep(i, n) {
        rep(b, 31) if(S.count(A[i] - (1LL<<b)) and S.count(A[i] + (1LL<<b))) {
            cout<<3<<'\n';
            cout<<A[i] - (1LL<<b)<<' '<<A[i]<<' '<<A[i] + (1LL<<b)<<'\n';
            return 0;
        }
    }
    rep(i, n) {
        rep(b, 31) if(S.count(A[i] - (1LL<<b))) {
            cout<<2<<'\n';
            cout<<A[i] - (1LL<<b)<<' '<<A[i]<<'\n';
            return 0;
        }
    }
    cout<<1<<'\n';
    cout<<A[0]<<'\n';



    return 0;
}