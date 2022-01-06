#include<bits/stdc++.h>
using namespace std; 
#define rep(i,n) for(int i=0; i<n; i++)
#define repx(i,a,b) for(int i=a; i<b;i++)
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
#define ff first
#define ss second.first
#define tt second.second

int dr[] = {0, 0, 1, -1};
int dc[] = {-1, 1, 0, 0};


int main(){
    int n, m, p; cin>>n>>m>>p;
    int mat[n][m];
    vector<int> s(p); rep(i,p) cin>>s[i];
    vector<queue<iii>> Q(p, queue<iii>());
    vector<int> cont(p, 0);
    char inp;
    rep(i,n) rep(j,m) {
        cin>>inp;
        if(inp == '.') mat[i][j] = -1;
        else if(inp == '#') mat[i][j] = -2; 
        else {
            Q[inp - '1'].push({0, {i, j}});
            mat[i][j] = inp - '1';
            cont[inp - '1']++;
        }
    }
    // rep(i,n) { rep(j,m) cout<<mat[i][j]<<" "; cout<<'\n'; }
    bool cond = true;
    int turn = 0;
    while(cond) {
        turn++;
        cond = false;
        rep(ind, p)
        while(!Q[ind].empty() and Q[ind].front().ff < s[ind] * turn){
            iii q_f = Q[ind].front();
            int d = q_f.ff, x = q_f.ss, y = q_f.tt; Q[ind].pop();
            // cerr<<x<<' '<<y<<'\n';
            rep(h, 4){
                int dx = x + dc[h], dy = y + dr[h];
                // cerr<<dx<<' '<<dy<<'\n';
                if(0 <= dx and dx < n and 0 <= dy and dy < m and mat[dx][dy] == -1){
                    // cerr<<"ire a visitar a "<<dx<<' '<<dy<<'\n';
                    Q[ind].push({d+1, {dx, dy}});
                    mat[dx][dy] = ind;
                    cont[ind]++;
                    cond = true;
                }
            }
        }
    }
    rep(i,p) cout<<cont[i]<<" "; cout<<'\n';



    return 0;
}