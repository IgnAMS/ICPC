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
        ll n, m, k; cin>>n>>m>>k;
        vector<array<ll, 3>> A(k);
        
        rep(i, k) {
            cin>>A[i][0]>>A[i][1]; A[i][2] = i;
        }
        
        sort(A.begin(), A.end(), [&](const array<ll, 3>& a, const array<ll, 3>& b){
            return a[1] > b[1] or (a[1] == b[1] and a[0] < b[0]);
        });

        vl V(k + 1, 0);
        vector<array<ll, 3>> S = {{n + 1, m + 1, k}};
        ll acc = 0;
        rep(i, k) {
            auto [x, y, ind] = A[i];
            cout<<x<<' '<<y<<' '<<ind<<'\n';
            ll last = 0;
            while(S.back()[0] <= x) {
                acc += V[S.back()[2]];
                V[S.back()[2]] = 0;
                S.pop_back();
            }
            cout<<acc<<'\n';
            V[ind] = x * (m - y + 1) - acc;
            S.push_back(A[i]);
        }


        cout<<n * m - acc<<'\n';
        rep(i, k) cout<<V[i]<<' '; cout<<'\n';
    }


    return 0;
}