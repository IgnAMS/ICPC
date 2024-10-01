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

pll Move[100];
ll solve(vector<ll> &A, vector<ll> &B, ll k, ll turn = 0) {
    ll ans = 0;
    for(auto u: A) ans += u;
    if(turn == k) return ans;

    Move[turn] = {-1, -1};
    if(turn % 2 == 0) {
        rep(i, A.size()) rep(j, B.size()) {
            swap(A[i], B[j]);
            ll newval = solve(A, B, k, turn + 1);
            if(newval > ans) {
                ans = newval;
                Move[turn] = {i, j};
            } 
            swap(A[i], B[j]);
        }
    }
    else {
        rep(i, A.size()) rep(j, B.size()) {
            swap(A[i], B[j]);
            ll newval = solve(A, B, k, turn + 1);
            if(newval < ans) {
                ans = newval;
                Move[turn] = {i, j};
            } 
            swap(A[i], B[j]);
        }
    }
    return ans;
}

ll suma(vector<ll> &A) {
    ll ans = 0;
    for(auto u: A) ans += u;
    return ans;
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--) {
        ll n, m, k; cin>>n>>m>>k;
        vl A(n), B(m);
        rep(i, n) cin>>A[i];
        rep(i, m) cin>>B[i];

        // rep(k2, 7) {
        //     cout<<solve(A, B, k2)<<'\n';
        //     rep(i, k2) cout<<Move[i].first<<' '<<Move[i].second<<'\n';
        //     cout<<'\n';
        // }
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        if(k % 2 == 1 and A[0] > B[m - 1]) {
            cout<<suma(A)<<'\n';
        }
        else if(k % 2 == 1 and A[0] <= B[m - 1]) {
            cout<<suma(A) - A[0] + B[m - 1]<<'\n';
        }
        else if(k % 2 == 0 and A[n - 1] < B[0]) {
            cout<<suma(A)<<'\n';
        }
        else if(k % 2 == 0 and A[n - 1] >= B[0]) {
            cout<<suma(A) - A[n - 1] + B[0]<<'\n';
        }

        // break;
    }


    return 0;
}