#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
#define ff first
#define ss second

const int mxN = 55;
vector<int> G[mxN];
pll E[mxN * mxN];


int main() {
    int t; cin>>t;
    while(t--) {
        int n, m; cin>>n>>m;
        for(int i = 0; i < m; i++) {
            int u, v; cin>>u>>v; u--, v--;
            G[u].push_back(v);
            G[v].push_back(u);
            E[i] = {u, v};
        }
        if(m < (n - 1) * n / 2) {
            int indmin = -1;
            for(int i = 0; i < n; i++) {
                if(G[i].size() < n - 1) indmin = i;
            }
            cout<<"2\n";
            for(int i = 0; i < m; i++) {
                if(E[i].ff != indmin and E[i].ss != indmin) cout<<1<<' ';
                else cout<<"2 ";        
            }
            cout<<'\n';
            
        }
        else {
            cout<<"3\n";
            cout<<"1 ";
            for(int i = 1; i < m; i++) {
                if(E[i].ff != E[0].ff and E[i].ss != E[0].ff) cout<<"2 ";
                else cout<<"3 ";
            }
            cout<<'\n';
        }
        
        for(int i = 0; i < n; i++) G[i].clear();
    }

    return 0;
}