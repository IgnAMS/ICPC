#pragma GCC optimize("O2")
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

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    vl A(n); rep(i, n) cin>>A[i];
    sort(A.begin(), A.end());
    vl B; B.pb(A[0]);
    repx(i, 1, n) if(A[i] != A[i - 1]) B.pb(A[i]);
    A = B;

    ll mx = 0;
    rep(i, n - 1) mx = max(mx, A[i] * A[n - 1] / __gcd(A[i], A[n - 1]));

    vector<vl> Div(100001, vl());
    for(int i = 1; i <= 100000; i++) {
        for(int j = i; j <= 100000; j += i) Div[j].pb(i);
    }
    cerr<<"sali :)\n";
    ll suma = 0;
    rep(i, 100001) suma += Div[i].size() * Div[i].size();
    cout<<suma<<'\n';

    ll cont = 0;
    ll bound = 8370000;
    for(int i = n - 1; i >= 0; i--) {
        int ind = upper_bound(A.begin(), A.end(), mx / A[i]) - A.begin();
        for(int j = n - 1; j >= max(ind, i + 1) and A[i] * A[j] >= mx; j--) {
            if(cont++ >= bound) break;
            mx = max(mx, A[i] * A[j] / __gcd(A[i], A[j]));
        }
        if(cont++ >= bound) break;
    }
    cout<<mx<<'\n';
    return 0;
}