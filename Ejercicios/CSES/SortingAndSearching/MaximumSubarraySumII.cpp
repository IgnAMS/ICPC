#pragma GCC optimize("Ofast")
#include<iostream>
#include<vector>
#include<string.h>
#include<set>
#include<map>
#include<algorithm>
#include<array>
#include<unordered_map>
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
// g++ -std=c++17 MissingCoinSum.cpp -o a && ./a <input.txt> output.txt
// ulimit -s 1000000
// g++ -O2 MaximumSubarraySumII.cpp && time ./a.out <input.txt> output.txt

struct ST {
    vl T;
    int n;
    ST(vector<ll>& A, int n): n(n) {
        T.resize(4 * n + 10);
        build(0, n - 1, 0, A);
    }  
    void build(int l, int r, int u, vl& A) {
        if(l == r) {
            T[u] = A[l];
            return;
        }
        int m = (l + r) / 2;
        build(l, m, 2 * u + 1, A);
        build(m+1, r, 2 * u + 2, A);
        T[u] = min(T[2 * u + 1], T[2 * u + 2]);
    }
    ll query(int l, int r, int i, int j, int u) {
        if(i <= l and r <= j) return T[u];
        if(r < i or j < l) return 1e16;
        int m = (l + r) / 2;
        return min(
            query(l, m, i, j, 2 * u + 1),
            query(m+1, r, i, j, 2 * u + 2)
        );
    }
    ll query(int i, int j) {
        return query(0, n - 1, i, j, 0);
    }
};


const int INF = 1e9+1;
const ll MOD = 1e9+7;
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, a, b; cin>>n>>a>>b;
    ll A[n]; rep(i, n) cin>>A[i]; 
    vl Acc(n+2);
    Acc[0] = 0;
    rep(i,n) {
        Acc[i+1] = Acc[i] + A[i];
    }
    Acc[n+1] = Acc[n];
    ST st(Acc, n+2);

    ll ans = -1e16;
    repx(i, a, n+1) {
        ans = max(
            ans,
            Acc[i] - st.query(max(0, i-b), i-a)
        );
        // cout<<i<<" "<<max(0, i-b)<<" "<<i-a<<" "<<Acc[i]<<" "<<st.query(max(0, i-b), i-a)<<"\n";
        // cout<<Acc[i] - st.query(max(0, i-b), i-a)<<"\n";
    }
    cout<<ans<<"\n";


    
    return 0;
}