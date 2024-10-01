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
        int n; cin>>n;
        vi A(n); rep(i, n) cin>>A[i];
        vi B(n); rep(i, n) cin>>B[i];
        set<ll> S = { n - 1 };
        rep(i, n) {
            if(i and A[i] > B[i - 1]) S.insert(i - 1);
        }
        vi D(n), U(n);
        rep(i, n) {
            ll up = *S.lower_bound(i);
            ll down = lower_bound(B.begin(), B.end(), A[i]) - B.begin();
            auto it = lower_bound(B.begin() + down, B.begin() + up + 1, A[i]);
            D[i] = *it - A[i];
            U[i] = *(B.begin() + up) - A[i];

            // cout<<down<<' '<<up<<'\n';
        }
        rep(i, n) cout<<D[i]<<' '; cout<<'\n';
        rep(i, n) cout<<U[i]<<' '; cout<<'\n';
    }





    return 0;
}