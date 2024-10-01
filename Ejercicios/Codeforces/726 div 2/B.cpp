#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define repx(i,a,b) for(int i=a; i<b; i++)
typedef long long ll;
typedef pair<ll,ll> ii;
#define ff first
#define ss second

int main(){
    int t; cin>>t;
    while(t--){
        ll n, m, x, y; cin>>n>>m>>x>>y; x--, y--;
        ii list[] = {{0, 0}, {n-1, m-1}, {0, m-1}, {n-1, 0}};
        ll ans = 0;
        ii p1 = {0,0}, p2 = {0,0};
        rep(i, 4) rep(j, 4) {
            ll d1 = abs(x - list[i].ff) + abs(y - list[i].ss);
            ll d2 = abs(list[i].ff - list[j].ff) + abs(list[i].ss - list[j].ss);
            ll d3 = abs(list[j].ff - x) + abs(list[j].ss - y);
            //cout<<d1 + d2 + d3<<'\n';
            if(ans < d1 + d2 + d3){
                ans = d1 + d2 + d3;
                p1 = list[i], p2 = list[j];
            }
        }
        //cout<<ans<<"\n";
        cout<<p1.ff + 1<<" "<<p1.ss + 1<<" "<<p2.ff + 1<<" "<<p2.ss + 1<<"\n";
    }



    return 0;
}