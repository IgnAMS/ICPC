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

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    ll n; cin>>n;
    ll A[n]; 
    rep(i, n) cin>>A[i];
    ll L[2][n], R[2][n];
    rep(b, 2) {
        ll inside = 0, not_inside = 0;
        rep(i, n - 1) {
            ll v = A[i] ^ A[i + 1];
            int big = 31;
            while(v != 0 and !(v & (1LL<<big))) big--;
            if(A[i] < A[i + 1]) not_inside |= (1LL<<big);
            else if(A[i] > A[i + 1]) inside |= (1LL<<big);
            L[0][i] = inside, L[1][i] = not_inside;
        }

        rep(j, 2) rep(i, n) swap(L[j][i], R[j][i]);
        reverse(A, A + n);
    }
    reverse(R[0], R[0] + n);
    reverse(R[1], R[1] + n);


    ll ans = -1, curr = 0;
    rep(i, n - 2) {
        ll not_in = L[1][i] | R[1][i + 2];
        ll inside = L[0][i] | R[0][i + 2];
        if(not_in & inside) continue;
        ans = inside;
        // cout<<not_in<<' '<<inside<<'\n';
    }
    cout<<ans<<'\n';


    return 0;
}