#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<ll, ll> ii;
typedef pair<ii, ll> iii;
typedef double db;
#define ff first
#define ss second

struct Event{
    ll a, b, d;
    Event(ll a, ll b, ll d): a(a), b(b), d(d) {}
    bool operator<(const Event &e) const{
        return a < e.a or (a == e.a and b < e.b);
    }
};



int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m, k; cin>>n>>m>>k;
    vector<ll> A(n); rep(i, n) cin>>A[i];
    vector<Event> M;
    rep(i, m){
        ll a, b, c; cin>>a>>b>>c;
        M.push_back(Event(a, b, c));
    } 
    
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    multiset<ii> S1;
    rep(i, k){
        ll a, b; cin>>a>>b;
        S1.insert(ii(a-1, 0)); S1.insert(ii(b, 1));
    }
    vector<ll> C(m, 0);
    ll aux = 0;
    ll ind = 0;
    int cont = 0;
    for(auto u : S1) {
        if(u.ff > ind) {
            repx(j, ind, u.ff) C[j] += aux;
            ind = u.ff;
        }
        if(u.ss == 0) aux++;
        else aux--;
    }
    rep(i, m) M[i].d *= C[i]; // Multiplico la cantidad de veces que sale
    sort(M.begin(), M.end());

    multiset<iii> S2;
    rep(i, m){
        S2.insert(iii(ii(M[i].a - 1, 0), M[i].d)); 
        S2.insert(iii(ii(M[i].b, 1), M[i].d)); 
    }
    cont = 0; 
    ind = 0, aux = 0;
    for(auto u : S2){
        // cerr<<(cont++)<<' '<<u.ff.ff<<' '<<u.ff.ss<<' '<<u.ss<<'\n';
        if(u.ff.ff > ind){
            repx(j, ind, u.ff.ff) A[j] += aux; 
            ind = u.ff.ff;
        }
        if(u.ff.ss == 0) aux += u.ss;
        else aux -= u.ss;
    }
    rep(i, n) cout<<A[i]<<' '; cout<<'\n';




    return 0;
}