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

const int mxN = 2e5+5;
ll cnt[mxN], C[mxN], A[mxN], invG[mxN];

void dfs(int u) {
    int v = A[u];
    cnt[v]++;
    if(C[u] == 0) C[v] = 1;
    if(cnt[v] == invG[v]) dfs(v);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    rep(u, n) {
        int v; cin>>v; v--;
        A[u] = v; 
        invG[v]++;
    }
    rep(u, n) if(invG[u] == 0) dfs(u);

    // detecto ciclos
    bool pos = 1; 
    rep(u, n) if(cnt[u] != invG[u] and C[u] == 1) {
        int p = u, v = A[u];
        cnt[u]++;
        while(v != u) {
            if(C[v] != 1) C[v] = !C[p];
            if(C[v] == 0 and C[p] == 0) pos = 0;
            cnt[v]++;
            p = v, v = A[v];
        }
        if(C[u] == 0 and C[p] == 0) pos = 0;
    }

    rep(u, n) if(cnt[u] != invG[u]) {
        int p = u, v = A[u];
        cnt[u]++;
        while(v != u) {
            if(C[v] != 1) C[v] = !C[p];
            if(C[v] == 0 and C[p] == 0) pos = 0;
            cnt[v]++;
            p = v, v = A[v];
        }
        if(C[u] == 0 and C[p] == 0) pos = 0;
    }


    if(!pos) {
        cout<<"-1\n";
    }
    else {
        ll cnt = 0;
        rep(u, n) if(C[u] == 0) cnt++;
        cout<<cnt<<'\n';
        rep(u, n) if(C[u] == 0) cout<<A[u] + 1<<' '; cout<<'\n';
    }



    return 0;
}