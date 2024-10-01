#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(ll i=a; i<b; i++)
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
    int n, m; cin>>n>>m;
    string mat[n]; 
    rep(i, n) cin>>mat[i];
    
    int Closed[m + 1][m + 1];
    int Open[m + 1];
    
    rep(i, m) {
        rep(j, m + 1) Closed[i][j] = 0;
        Open[i] = 0;
    }
    
    rep(i, n) {
        ll curr = 0, left;
        rep(j, m) {
            if(mat[i][j] == '0') {
                rep(k, curr) Closed[left + k][curr - k]++, Open[left + k]++;
                curr = 0;
            }
            else {
                if(curr == 0) left = j;
                curr++;
            }
        }
        rep(k, curr) Closed[left + k][curr - k]++, Open[left + k]++;
    }

    ll ans = 0;
    rep(i, m) {
        ll curr = Open[i];
        rep(j, m + 1) {
            ans = max(ans, curr * j);
            curr -= Closed[i][j];
        }
    }
    cout<<ans<<'\n';

    
    return 0;
}