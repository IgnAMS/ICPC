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
//  g++ -O2 D.cpp && time ./a.out < input.txt > output.txt
 
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll n, m, k; cin>>n>>m>>k;
    vi A(n); rep(i, n) cin>>A[i];
    vector<vi> E;
    ll sqr = sqrt(m);
    rep(i, m) {
        ll l, r; cin>>l>>r; l--, r--;
        E.push_back({l / sqr, l, r, i});
    }
    sort(E.begin(), E.end(), [&](const auto& a, const auto& b) {
        return (a[0] == b[0]? a[2] < b[2]: a[1] < b[1]);
    });
    
    vi F(2000005, 0);
    int l = 0, r = 0;
    F[0]++;
    vi Ans(m, 0);
    ll L = 0, R = A[0], curr = F[A[0] ^ k]; F[A[0]]++;
    for(auto& e: E) {
        while(l > e[1]) l--, L = L ^ A[l], curr += F[k ^ L], F[L]++;
        while(r < e[2]) r++, R = R ^ A[r], curr += F[k ^ R], F[R]++;
        while(r > e[2]) F[R]--, curr -= F[k ^ R], R = R ^ A[r], r--;
        while(l < e[1]) F[L]--, curr -=  F[k ^ L], L = L ^ A[l], l++;
        Ans[e[3]] = curr;
    }
    rep(i, m) cout<<Ans[i]<<'\n';
 
 
    return 0;
}