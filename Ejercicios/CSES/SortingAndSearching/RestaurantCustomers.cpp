#pragma GCC optimize("Ofast")
#include<iostream>
#include<vector>
#include<string.h>
#include<set>
#include<map>
#include <algorithm>
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
// g++ -std=c++17 MissingCoinSum.cpp -o a && ./a <input.txt> output.txt
// ulimit -s 1000000
// g++ -O2 RestaurantCustomers.cpp && time ./a.out <input.txt> output.txt
 
 
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    pll A[n];
    vector<pll> E;
    rep(i, n) {
        cin>>A[i].ff>>A[i].ss;
        E.pb({A[i].ff, 1});
        E.pb({A[i].ss, -1});
    }
    sort(E.begin(), E.end());
 
    int curr = 0, ans = 0;
    for(auto [ind, t] : E) {
        if(t == 1) curr++;
        else curr--;
        ans = max(ans, curr);
    }
    cout<<ans<<"\n";
 
    
    return 0;