#pragma GCC optimize("Ofast")
#include<string.h>
#include<vector>
#include<map>
#include<deque>
#include<iostream>
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
int n, m;
vl G[mxN];
vl P(mxN, -1);

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;
    rep(i, m) {
        int u, v; cin>>u>>v; u--, v--;
        G[u].pb(v); G[v].pb(u);
    }
    P[0] = -2;
    deque<int> dq = {0};
    while(!dq.empty()) {
        auto u = dq.front(); dq.pop_front();
        for(auto v: G[u]) if(P[v] == -1) {
            P[v] = u;
            dq.push_back(v);
        }
    }
    if(P[n-1] == -1) {
        cout<<"IMPOSSIBLE\n";
        return 0;
    }
    vl Ans;
    int u = n-1;
    while(u != -2) {
        Ans.pb(u);
        u = P[u];
    }
    reverse(Ans.begin(), Ans.end());
    cout<<Ans.size()<<"\n";
    for(auto u: Ans) cout<<u+1<<" "; cout<<"\n";


    
    return 0;
}