#pragma GCC optimize("Ofast")
#include<iostream>
#include<vector>
#include<string.h>
#include<set>
#include<map>
#include<algorithm>
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
// g++ -O2 SumOfTwoValues.cpp && time ./a.out <input.txt> output.txt

const int INF = 1e9+1;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, x; cin>>n>>x;
    vl A(n);
    set<pll> S;
    rep(i, n) {
        cin>>A[i];
        S.insert({A[i], i});
    }
    rep(i, n) {
        auto it = S.lower_bound({x - A[i], 0});
        if(it == S.end() or it->first != x - A[i]) continue;
        if(it->second != i) {
            cout<<i + 1<<" "<<it->second + 1<<"\n"; 
            return 0;
        }
        if(next(it)->ff == A[i] - x) {
            cout<<i + 1<<" "<<next(it)->second + 1<<"\n";
        }
    }
    cout<<"IMPOSSIBLE\n";

    
    return 0;
}