#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<ll, ll> ii;
typedef double db;
typedef vector<ll> vi;
#define ff first
#define ss second
// g++ -std=c++11 A.cpp -o a && a <input.txt> output.txt
// g++ -O2 D.cpp && time ./a.out <input.txt> output.txt

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--) {
        int n, k; cin>>n>>k;
        vi A(n); rep(i, n) cin>>A[i];
        if(n == k) {
            cout<<1000000000<<'\n';
            continue;
        }

        set<ii> S;
        rep(i, n) S.insert({A[i], i});
        rep(i, k - 1) {
            ii a = (*S.begin());
            A[a.ss] = 1e9;
            S.erase(S.begin());
        }
        set<ii> P;
        ll ans = 0;
        rep(i, n - 1) P.insert({min(A[i], A[i + 1]), i});
        rep(i, n) {
            ll tmp = A[i];
            S.erase({A[i], i});
            if(i > 0) P.erase({min(A[i - 1], A[i]), i - 1});
            if(i < n - 1) P.erase({min(A[i], A[i + 1]), i});
            A[i] = 1e9;
            S.insert({A[i], i});
            if(i > 0) P.insert({min(A[i - 1], A[i]), i - 1});
            if(i < n - 1) P.insert({min(A[i], A[i + 1]), i});

            ans = max(ans, min(2 * S.begin()->ff, P.rbegin()->ff));
            
            S.erase({A[i], i});
            if(i > 0) P.erase({min(A[i - 1], A[i]), i - 1});
            if(i < n - 1) P.erase({min(A[i], A[i + 1]), i});
            A[i] = tmp;
            S.insert({A[i], i});
            if(i > 0) P.insert({min(A[i - 1], A[i]), i - 1});
            if(i < n - 1) P.insert({min(A[i], A[i + 1]), i});
       }
       cout<<ans<<'\n';
    }





    return 0;
}