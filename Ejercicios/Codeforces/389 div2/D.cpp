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

const int mxN = 1e5+5;
const ll MOD = 999727999;
string S[mxN];
ll A[mxN];
ll H[2][mxN];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int k, n; cin>>k>>n;

    map<string, vl> palindrome, not_palindrome;
    rep(i, k) {
        cin>>S[i]>>A[i];
        rep(b, 2) {
            ll pot = 1, base = 37;
            rep(j, n) {
                H[b][i] += pot * (S[i][j] - 'a' + 1); 
                H[b][i] %= MOD; 
                pot = pot * base % MOD;
            }
            reverse(S[i].begin(), S[i].end()); 
        }
        if(H[0][i] == H[1][i]) palindrome[S[i]].pb(A[i]);
        else not_palindrome[S[i]].pb(A[i]);
    }

    for(auto& [x, vec]: palindrome) {
        sort(vec.begin(), vec.end());
        reverse(vec.begin(), vec.end());
    }
    for(auto& [x, vec]: not_palindrome) sort(vec.begin(), vec.end());


    ll ans = 0;
    for(auto& [x, vec]: not_palindrome) {
        ll best = 0;
        ll aux = 0;
        while(vec.size() >= 2) {
            rep(b, 2) {
                aux += vec.back();
                vec.pop_back();
            }
            best = max(best, aux);
        }
        ans += best;
    }

    for(auto& [x, vec]: palindrome) {
        ll best_par = 0;
        ll best_impar = 0;
        ll aux = 0;
        rep(i, vec.size() / 2) {
            rep(b, 2) aux += vec[2 * i] + vec[2 * i + 1];
        }
    }




    return 0;
}