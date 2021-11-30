#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<int,int> ii;
typedef double db;
typedef vector<ll> vi;
#define ff first
#define ss second
// g++ -std=c++11 A.cpp -o a && a <input.txt> output.txt
//  g++ -O2 D.cpp && time ./a.out < input.txt > output.txt

struct FT
{
    vi t;
    FT(int N) { t.resize(N + 1, 0); }
    int query(int i)
    {
        int ans = 0;
        for (; i; i -= i & (-i)) ans += t[i];
        return ans;
    }
    int query(int i, int j) { return query(j) - query(i - 1); }
    void update(int i, int v)
    {
        int s = query(i, i); // Sets
        // cout<<"partire de "<<i<<" con "<<s<<'\n';
        for (; i < t.size(); i += i & (-i)) {
            // cout<<"actualizo a "<<i<<" con "<<v<<'\n';
            t[i] += v;
        }
    }
    void update(int i, int j, int v) { update(i, v); update(j + 1, -v); }
};

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int p, v; cin>>p>>v;
    map<int, int> high;
    set<int> H;
    vector<ii> P(p), V(v);
    vector<vector<ll>> Events; // 0: x, 1: type, 2: y1, 3: y2
    rep(i, p){
        cin>>P[i].ff>>P[i].ss;
        H.insert(P[i].ss);
    }
    rep(i, v){
        cin>>V[i].ff>>V[i].ss;
        H.insert(V[i].ss);
    }
    for(auto u: H) high[u] = high.size() + 1;
    // for(auto u: H) cout<<"("<<u<<", "<<high[u]<<"), "; cout<<'\n';

    rep(i, p) Events.push_back({P[i].ff, 2, high[P[i].ss], i+1});
    rep(i, v+1) {
        if(V[i].ff == V[(i+1)%v].ff and V[i].ss < V[(i+1)%v].ss) // abrir
            Events.push_back({V[i].ff, 0, high[V[i].ss], high[V[(i+1)%v].ss]});
        
        if(V[i].ff == V[(i+1)%v].ff and V[i].ss > V[(i+1)%v].ss) // cerrar
            Events.push_back({V[i].ff, 1, high[V[(i+1)%v].ss], high[V[i].ss]});
    }

    sort(Events.begin(), Events.end());
    FT ft(H.size() + 2);
    ll ans = 0;
    for(auto e: Events){
        if(e[1] == 0) {
            int l = e[2], r = e[3];
            ft.update(e[2], e[3] - 1, 1);
        }
        else if(e[1] == 1) {
            int l = e[2], r = e[3];
            ft.update(e[2], e[3] - 1, 1);
        }
        else{
            if(ft.query(e[2]) % 2 == 0) {
                ans += e[3];
            }
        }
    }
    cout<<ans<<'\n';

    return 0;
}