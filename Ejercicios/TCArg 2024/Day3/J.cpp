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
    ll n, k; cin>>n>>k;
    vl A(n);
    rep(i, n) cin>>A[i];
    string s; cin>>s;
    map<char, vector<ll>> mp;
    char active = 'A';
    ll cont = 0;
    ll ans = 0;
    multiset<ll> S;
    rep(i, n) {
        // cout<<i<<' '<<s[i]<<' '<<cont<<' '<<A[i]<<'\n';
        if(active != s[i]) active = s[i], cont = 0, S.clear();
        if(cont == k and *S.begin() < A[i]) {
            ans += A[i] - *S.begin();
            S.insert(A[i]);
            S.erase(S.find(*S.begin()));
        }
        if(cont < k) {
            cont++;
            ans += A[i];
            S.insert(A[i]);
        }
    }
    

    cout<<ans<<'\n';


    return 0;
}