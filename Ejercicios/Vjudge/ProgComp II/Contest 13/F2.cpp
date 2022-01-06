#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;
struct e{
    int w,b1,b2;
    e(int w, int b1, int b2): w(w), b1(b1),b2(b2) {};
};


int d,p;
vector<vector<int>> g;
vector<int> W; // de 0 a d-1 son D, de d a d+p-1 es P
vector<bool> vis;
int id;
vector<e> G;

void dfs(int u){
    vis[u]=1;
    u<d? G.back().b1++:G.back().b2++;
    G.back().w+=W[u];
    for(auto& v: g[u]) if(!vis[v]){
        dfs(v);
    }
    return;
}

int dp[200+3][(int)1e4+4][2];
int DP(int i, int b, int sign){
    int& ans= dp[i][b][(sign+1)/2];
    if(ans!=-1) return  ans;
    if(i==id) return 0;
    ans=DP(i+1,b,sign);
    if(b>=G[i].w) ans=max(ans, DP(i+1,b-G[i].w,sign) + sign*(G[i].b2-G[i].b1));
    //cout<<"DP "<<i<<" "<<b<<": "<<ans<<"\n";
    return ans;
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int r,b;
    while(cin>>d>>p>>r>>b){
        G.clear(); id=0;
        W.resize(d+p);
        g.assign(d+p,{});
        vis.assign(d+p,0);
        rep(u,d) cin>>W[u];
        rep(u,p) cin>>W[u+d];
        
        rep(i,r){
            int x, y; cin>>x>>y; x--,y--;
            g[x].push_back(y+d);
            g[y+d].push_back(x);
        }

        rep(u,d+p){ if(!vis[u]) {
            G.push_back(e(0,0,0)); id++;
            dfs(u);
        } }
        rep(i,id+2) rep(j,b+2) { dp[i][j][0]=-1; dp[i][j][1]=-1; }
        //for(auto& u:G) cout<<u.w<<" "<<u.b1<<" "<<u.b2<<"\n";
        //cout<<"\n";
        cout<<d+DP(0,b,1)<<" "<<p+DP(0,b,-1)<<"\n";
    
    }




    return 0;
}