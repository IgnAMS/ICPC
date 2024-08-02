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

// REFERENCES: https://github.com/BenjaminRubio/CompetitiveProgramming/blob/master/Material/Structures/DSU.cpp
struct DSU {
    vl p; DSU(int N) : p(N, -1) {}

    int get(int x) { return p[x] < 0 ? x : p[x] = get(p[x]); } 
    bool sameSet(int a, int b) { return get(a) == get(b); }
    int size(int x) { return -p[get(x)]; }
    void unite(int x, int y) {
        if((x = get(x)) == (y = get(y))) return;
        if(p[x] > p[y]) swap(x,y);
        p[x] += p[y], p[y] = x;
    }
};


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--) {
        int n, m; cin>>n>>m;
        DSU dsu(n);

        ll A[n][3];
        rep(i, m) {
            rep(j, 3) {
                cin>>A[i][j];
                A[i][j]--;
            }
            dsu.unite(A[i][0], A[i][1]);   
            dsu.unite(A[i][0], A[i][2]);
            dsu.unite(A[i][1], A[i][2]);   
        }

        set<ll> S[n];
        rep(i, m) {
            rep(j, 3) S[dsu.get(A[i][0])].insert(i);
        }

        vl Ans(n, 0);
        bool yey = 0;
        rep(i, n) {
            if(S[i].size() % 2 == 1) {
                for(auto u: S[i]) Ans[A[u][0]] = Ans[A[u][1]] = Ans[A[u][2]] = 1;
                yey = 1;
                break;
            }
        }

        if(yey) {
            cout<<"YES\n";
            for(auto u: Ans) cout<<u<<' '; cout<<'\n';
        }
        else cout<<"NO\n";

    }    






    return 0;
}