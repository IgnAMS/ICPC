#pragma GCC optimize("Ofast")
#include<iostream>
#include<vector>
#include<string.h>
#include<set>
#include<map>
#include<algorithm>
#include<array>
#include<unordered_map>
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
// g++ -O2 SumOfThreeValues.cpp && time ./a.out <input.txt> output.txt


const int INF = 1e9+1;
const ll MOD = 1e9+7;
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    ll n, x; cin>>n>>x;
    ll A[n]; rep(i, n) cin>>A[i];
    
    set<pll> S;
    rep(i, n) S.insert({A[i], i});
    rep(i, n-2) {
        S.erase({A[i], i});
        repx(j, i+1, n-1) {
            auto it = S.lower_bound({x - A[i] - A[j], j+1});
            if(it == S.end() or it->ff != x - A[i] - A[j]) continue;
            cout<<i + 1<<" "<<j + 1<<" "<<it->ss + 1<<"\n";
            return 0;
        }
    }
    cout<<"IMPOSSIBLE\n";
    
    return 0;
}