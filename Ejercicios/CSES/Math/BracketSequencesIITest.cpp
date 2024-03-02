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

ll mod = 1e9+7;
ll binpow(ll a, ll b) {
    ll res = 1;
    while(b) {
        if(b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    if(n & 1) {
        cout<<"0\n";
        return 0;
    }
    string s; cin>>s;
    int k = s.length();
    
    set<vl> S;
    vl A(n); 
    rep(i, n/2) A[i] = 0;
    rep(i, n/2) A[i] = 1;
    next_permutation(A.begin(), A.end());
    do {
        ll curr = 0, match = 1;
        rep(i, n) {
            curr += (A[i] == 1? 1: -1);
            if(curr < 0) break;
            if(i < k and (A[i] == 0 and s[i] == '(')) {
                match = 0;
                break;
            }
            if(i < k and (A[i] == 1 and s[i] == ')')) {
                match = 0;
                break;
            }
        }
        
        if(curr == 0 and match) S.insert(A);
    } while(next_permutation(A.begin(), A.end()));
    

    cout<<S.size()<<'\n';

    return 0;
}