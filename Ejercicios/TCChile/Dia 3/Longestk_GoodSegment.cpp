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

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, k; cin>>n>>k;
    vl A(n); rep(i, n) cin>>A[i];
    map<ll, ll> mp;
    ll i = 0;
    pll ans = {0, 0};
    ll mxans = 0;
    ll elements = 0;
    rep(j, n) {
        if(!mp.count(A[j])) mp[A[j]] = 0;
        if(mp[A[j]] == 0) elements++;
        mp[A[j]]++;
        while(elements > k) {
            mp[A[i]]--;
            if(mp[A[i]] == 0) elements--;
            i++;
        }
        if(mxans < j - i + 1) {
            mxans = j - i + 1;
            ans = {i, j};
        }
    }
    cout<<ans.ff + 1<<' '<<ans.ss + 1<<'\n';





    return 0;
}