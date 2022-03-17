#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<ll, ll> ii;
typedef double db;
typedef vector<ll> vi;
#define ff first
#define ss second
// g++ -std=c++11 A.cpp -o a && a <input.txt> output.txt
//  g++ -O2 D.cpp && time ./a.out < input.txt > output.txt

int t[400005]; 
void update(ll l, ll r, ll u, ll pos, ll x) {
    if(l == r) {
        // cerr<<"updapteo el nodo "<<l<<' '<<r<<" a "<<x<<'\n';
        t[u] = x;
    }
    else {
        ll m = (l + r) / 2;
        if(pos <= m) update(l, m, 2 * u, pos, x);
        else update(m + 1, r, 2 * u + 1, pos, x);
        t[u] = min(t[2 * u], t[2 * u + 1]);
        // cerr<<"updapteo el nodo "<<l<<' '<<r<<" a "<<t[u]<<'\n';
    }
}


ll query(int l, int r, int u, int x) {
    // cerr<<"estoy en "<<l<<' '<<r<<", t[2 * u]: "<<t[2 * u]<<' '<<x<<'\n';
    if(l == r) return l;
    if(t[2 * u] < x) return query(l, (l + r) / 2, 2 * u, x);
    return query((l + r) / 2 + 1, r, 2 * u + 1, x);
}




int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    vi A(n); rep(i, n) cin>>A[i];
    vi last(n + 1, -1);
    set<int> S;
    memset(t, -1, sizeof t);
    rep(i, n) {
        ll x = A[i];
        // cerr<<"voy en el indice "<<i<<'\n';
        if(last[x] + 1 < i) {
            // cerr<<"entre aca?\n";
            ll y = query(1, n + 1, 1, last[x] + 1);
            // cerr<<"la query me devuelve "<<y<<'\n';
            S.insert(y);
        }
        last[x] = i;
        update(1, n + 1, 1, A[i], i);
    }
    // cerr<<"sobrevivi a esto\n";
    repx(i, 1, n + 1) if(last[i] != -1 and last[i] != n - 1) {
        // cerr<<"preguntare por "<<last[i] + 1<<'\n';
        ll y = query(1, n + 1, 1, last[i] + 1);
        // cerr<<"obtengo de respuesta "<<y<<'\n';
        S.insert(y);
    } 
    S.insert(query(1, n + 1, 1, 0));
    repx(i, 1, n + 3) if(!S.count(i)) {
        cout<<i<<'\n';
        break;
    }


    return 0;
}