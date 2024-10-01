#include<bits/stdc++.h>
using namespace std;
#define repx(i, a, b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;

ll check(ll dist, ll maxdist) { return dist > maxdist ? INT64_MAX : dist; }

int main(){
    int t; cin>>t;
    while(t--){
        ll W, H; cin>>W>>H;
        ll x1, y1, x2, y2; cin>>x1>>y1>>x2>>y2;
        ll w, h; cin>>w>>h;
        ll mindist = min({
            check(h - y1, H - y2), check(y2 - H + h, y1), 
            check(w - x1, W - x2), check(x2 - W + w, x1)
        });
        mindist = max(0LL, mindist);
        if(mindist == INT64_MAX) { cout<<-1<<'\n'; continue; }
        cout<<setprecision(8)<<fixed<<double(mindist)<<'\n';
    }



    return 0; 
}