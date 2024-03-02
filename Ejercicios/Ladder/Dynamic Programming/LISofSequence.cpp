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



int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    ll A[n]; rep(i, n) cin>>A[i];
    
    vl T(n + 1, 1000000), Ans(n, 0);
    ll F1[n], F2[n];
    ll mx = 0;
    rep(i, n) {
        ll ind = lower_bound(T.begin(), T.end(), A[i]) - T.begin();
        F1[i] = ind + 1;
        mx = max(mx, ind + 1);
        T[ind] = A[i]; 
    }

    T.assign(n + 1, 1000000);
    for(int i = n - 1; i >= 0; i--) {
        ll ind = lower_bound(T.begin(), T.end(), -A[i]) - T.begin();
        F2[i] = ind + 1;
        T[ind] = -A[i];
    }
    
    rep(i, n) {
        if(F1[i] + F2[i] - 1 != mx) Ans[i] = 1;
    }

    vl C(n + 2, 0);
    rep(i, n) {
        if(Ans[i] != 1) C[F1[i]]++;
    }

    rep(i, n) {
        if(Ans[i] != 1 and C[F1[i]] > 1) Ans[i] = 2;
        if(Ans[i] != 1 and C[F1[i]] == 1) Ans[i] = 3;
    }

    rep(i, n) cout<<Ans[i]; cout<<'\n';


    return 0;
}