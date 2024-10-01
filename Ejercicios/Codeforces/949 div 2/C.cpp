#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<ll, ll> pll;
typedef double db;
typedef vector<ll> vl;
#define ff first
#define ss second
#define pb push_back
// g++ -std=c++11 A.cpp -o a && a <input.txt> output.txt
// ulimit -s 1000000
// g++ -O2 D.cpp && time ./a.out <input.txt> output.txt


vl Path;
ll get_dist(ll x, ll y) {
    ll cont = 0;
    ll dx = 0, dy = 0;
    rep(j, 31) {
        if((x>>j) & 1) dx = j;
    }
    rep(j, 31) {
        if((y>>j) & 1) dy = j;
    }
    cont += abs(dx - dy);

    vl X, Y; Path.clear();
    X.pb(x); Y.pb(y);
    while(dx > dy) {
        x /= 2;
        X.pb(x);
        dx--;
    }
    while(dy > dx) {
        y /= 2;
        Y.pb(y);
        dy--;
    }
    if(x == y) {
        if(X.size() == 1) {
            reverse(Y.begin(), Y.end());
            for(auto u: Y) Path.pb(u);
        }
        else {
            for(auto u: X) Path.pb(u);
        }
        return cont;
    }

    for(int l = 31; l >= 0; l--) {
        if(x >= (1LL<<l) and y >= (1LL<<l) and (x / (1LL<<l)) != (y / (1LL<<l))) {
            rep(j, l) {
                x /= 2, y /= 2;
                X.pb(x);
                Y.pb(y);
                cont += 2;
            }
        }
    }
    if(x != y) {
        cont += 2;
        x /= 2, y /= 2;
        X.pb(x);
    }
    for(auto u: X) Path.pb(u);
    reverse(Y.begin(), Y.end());
    for(auto u: Y) Path.pb(u);

    return cont;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--) {
        ll n; cin>>n;
        vl A(n);
        ll cont = 0;
        rep(i, n) {
            cin>>A[i];
            if(A[i] != -1) cont++; 
        }
        if(cont == 0) {
            rep(i, n) cout<<((i & 1)? 1:2)<<' '; cout<<'\n';
            continue;
        }

        bool pos = 1;
        int last = -1;
        rep(i, n) {
            if(A[i] != -1 and last == -1) {
                last = i;
                ll aux = A[i];
                for(int j = i - 1; j >= 0; j--) {
                    aux = (aux == A[i]? 2 * aux: A[i]);
                    A[j] = aux; 
                }
            }
            else if(A[i] != -1) {
                // tengo last y A[i]
                ll x = A[last], y = A[i];
                ll l = get_dist(x, y);
                l = Path.size();
                if(((i - last + 1) % 2) != (l % 2)) {
                    pos = 0;
                    last = i;
                    continue;
                }
                if(i - last + 1 < ll(Path.size())) {
                    pos = 0;
                    last = i;
                    continue;
                }

                if(x == y) {
                    ll aux = x;
                    repx(j, last + 1, i) {
                        aux = (aux == x? 2 * aux: x);
                        A[j] = aux;
                    }
                    last = i;
                    continue;
                }

                ll d = i - last + 1 - ll(Path.size());
                repx(j, last + 1, last + 1 + d) {
                    if((j - last - 1) % 2 == 0) A[j] = Path[1];
                    else A[j] = Path[0];
                }
                repx(j, last + 1 + d, i) {
                    A[j] = Path[j - (last + d + 1) + 1];
                }
                // cout<<"reviso el camino "<<A[last]<<' '<<A[i]<<'\n';
                // for(auto u: Path) cout<<u<<' '; cout<<'\n';
                last = i;
            }  
        }

    
        if(!pos) {
            cout<<"-1\n";
            continue;
        }

        ll aux = A[last];
        repx(j, last + 1, n) {
            aux = (aux == A[last]? 2 * aux: A[last]);
            A[j] = aux;
        }
        rep(i, n) cout<<A[i]<<' '; cout<<'\n';


    }




    return 0;
}