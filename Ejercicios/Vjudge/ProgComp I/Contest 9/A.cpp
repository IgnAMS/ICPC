#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;
typedef pair<ll, ll> ii;
#define ff first
#define ss second


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll n,m,k,p; cin>>n>>m>>k>>p;
    ll mat[n][m]; rep(i,n) rep(j,m) cin>>mat[i][j];
    vector<ll> cols(m, 0), rows(n,0);
    rep(i,n) rep(j,m) cols[j] += mat[i][j], rows[i] += mat[i][j];
    
    priority_queue<ll, vector<ll>> pr, pc;
    rep(i,n) pr.push(rows[i]);
    rep(i,m) pc.push(cols[i]);
    
    ll ans = 0, dr = 0, dc = 0;
    ll u;
    rep(_, k){
        if(pr.top() - dr > pc.top() - dc){
            u = pr.top(); pr.pop();
            ans += u - dr; dc += p;
            pr.push(u - p*m);
        }
        else{
            u = pc.top(); pc.pop();
            ans += u - dc; dr += p; 
            pc.push(u - p*n);
        }
    }
    cout<<ans<<"\n";





    return 0;
}