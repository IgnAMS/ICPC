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

struct Event{
    ll ind, t, aux, c; 
    // aux sera el indice de la respuesta para querys y el offset para los A[i]
    // ind es donde ocurre el evento y t es el type = { 0: agrego, 1: entra, 2: sale }
    Event(ll ind, ll t, ll aux): ind(ind), t(t), aux(aux), c(0LL) {}
    Event(ll ind, ll t, ll aux, ll c): ind(ind), t(t), aux(aux), c(c) {}
    bool operator<(const Event& e) const { 
        return ind < e.ind or (ind == e.ind and t < e.t);
    }
};

struct DSU{
    vi p; DSU(int N) : p(N, -1) {}
    int get(int x) { return p[x] < 0 ? x : p[x] = get(p[x]); } 
    bool sameSet(int a, int b) { return get(a) == get(b); }
    int size(int x) { return -p[get(x)]; }
    void unite(int x, int y)
    {
        if ((x = get(x)) == (y = get(y))) return;
        if (p[x] > p[y]) swap(x,y);
        p[x] += p[y], p[y] = x;
    }
};

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll n, l, u; cin>>n>>l>>u;
    
    set<Event> E;
    ll A[n]; rep(i, n) { cin>>A[i]; E.insert(Event(i, 0, A[i])); } 
    int m; cin>>m;
    rep(i, m){
        ll a, b, c; cin>>a>>b>>c;
        E.insert(Event(a, 1, i, c));
        E.insert(Event(b, 2, i, c));
    }

    ll ans[m];
    ll last = 0, off = 0;
    DSU uf(m + 2);
    ll low = m+1, up = m;
    set<ii> S; // valor, indice
    for(auto& u: E){
        if(u.t == 0){
            last = u.aux;
            off += u.aux;
            auto it = S.begin();
            while(it != S.end() and it->first + off <= l) { 
                uf.unite(it->second, S.begin()->second);
                it++; // hasta que la suma sea mayor a l
            }
            if(it != S.end() and it != S.begin()) {
                S.begin()->fisrt = l - off; 
                S.erase(next(S.begin()), prev(it));
            }

            auto rit = S.rbegin();
            while(rit != S.rend() and rit->first + off >= u) { 
                uf.unite(rit->second, S.rbegin()->second);
                rit++; // hasta que la suma sea mayor a l
            }
            if(rit != S.rend() and rit != S.rbegin()) {
                S.rbegin()->first = u - off;
                S.erase(next(S.rbegin()), prev(rit));
            }
        }
        if(u.t == 1){
            ll a = max(min(u.c, u), l) - off + last;
            S.insert(ii(a, u.aux));
        }
        if(u.t == 2){
            ans[u.aux] = lower_bound(S.begin(), S.end(), ii());
        }
    }




    return 0;
}