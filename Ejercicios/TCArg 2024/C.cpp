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
        int n, m; cin>>n>>m;
        vector<array<ll, 2>> E;
        vl A(n), B(m);
        rep(i, n) cin>>A[i];
        rep(i, m) cin>>B[i];

        rep(i, n) if(A[i] > 0) E.pb({A[i], 0});
        rep(i, m) if(B[i] > 0) E.pb({B[i], 2});
        ll right = 0;
        rep(i, n) if(A[i] > 0) {
            auto it = lower_bound(B.begin(), B.end(), A[i]);
            if(it != B.end() and *it == A[i]) {
                E.pb({A[i], 1});
                right++;
            }
        }
        sort(E.begin(), E.end());
        ll ans1 = right;
        ll acc = 0;
        set<ll> S;
        for(auto [ind, type]: E) {            
            if(type == 2) {
                S.insert(ind);
                while(!S.empty() and *S.begin() <= ind - acc) S.erase(S.begin());
                ans1 = max(ans1, right + (ll)S.size());
            }
            else if(type == 1) right--;
            else acc += 1;
        }
        E.clear(); S.clear();
        
        rep(i, n) if(A[i] < 0) E.pb({-A[i], 0});
        rep(i, m) if(B[i] < 0) E.pb({-B[i], 2});
        right = 0;
        rep(i, n) if(A[i] < 0) {
            auto it = lower_bound(B.begin(), B.end(), A[i]);
            if(it != B.end() and *it == A[i]) {
                E.pb({-A[i], 1});
                right++;
            }
        }

        sort(E.begin(), E.end());
        ll ans2 = right;
        acc = 0;
        for(auto [ind, type]: E) {            
            if(type == 2) {
                S.insert(ind);
                while(!S.empty() and *S.begin() <= ind - acc) S.erase(S.begin());
                ans2 = max(ans2, right + (ll)S.size());
            }
            else if(type == 1) right--;
            else acc += 1;
        }
        // cout<<ans1<<' '<<ans2<<'\n';
        cout<<ans1 + ans2<<'\n';    
    }


    return 0;
}