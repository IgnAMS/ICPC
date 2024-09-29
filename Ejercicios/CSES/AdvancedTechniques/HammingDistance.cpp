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
    int n, k; cin>>n>>k;
    int A[n];
    rep(i, n) {
        string s; cin>>s;
        A[i] = 0;
        rep(j, k) A[i] += int(s[j] == '1') * (1<<j);
    }
    int ans = 31;
    rep(i, n) {
        repx(j, i + 1, n) {
            // cout<<A[i]<<' '<<A[j]<<' '<<__builtin_popcount(A[i] ^ A[j])<<'\n';
            ans = min(ans, (int)__builtin_popcount(A[i] ^ A[j]));
        }
    }
    cout<<ans<<'\n';


    return 0;
}