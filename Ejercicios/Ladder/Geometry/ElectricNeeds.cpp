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
ll n, m, p; 

ll horizontal(multiset<ii>& S, bool type){ // type: 0 -> vertical, 1 -> horizontal 
    ll res1 = 0;
    ll lx = 10000000000, rx = -10000000000;
    for(auto it = S.begin(); it != S.end(); it++) {
        if((*it).ff <= rx) rx = min(max(1LL, (*it).ss), m);
        else {
            if(rx != -10000000000) res1 += rx - lx + 1;
            lx = min(max(1LL, (*it).ff), m), rx = min(max(1LL, (*it).ss), m);
        }
    }
    if(rx != -10000000000) res1 += rx - lx + 1;
    return res1;
}

ll get_area(vector<ii>& P, ll mid){
    vector<vi> E; // [altura, tipo, xi, xf], tipo -> 0: abrir, 1 cerrar
    rep(i, p) {
        E.push_back({max(1LL, P[i].ff - mid), 0, P[i].ss - mid, P[i].ss + mid});
        E.push_back({min(P[i].ff + mid, n), 1, P[i].ss - mid, P[i].ss + mid});
    }
    sort(E.begin(), E.end());
    ll acc = -p, hor = 0, lasty = E[0][0];
    multiset<ii> S;
    rep(i, E.size()){
        hor = horizontal(S, 1);
        acc += hor * (E[i][0] - lasty - 1);
        lasty = E[i][0];
        ll x = E[i][0];
        int j = i;
        while(j < E.size() and E[j][0] == x){
            if(E[j][1] == 0) S.insert(ii(E[j][2], E[j][3]));
            j++;
        }
        acc += horizontal(S, 1);
        j = i;
        while(j < E.size() and E[j][0] == x){
            if(E[j][1] == 1) S.erase(S.find(ii(E[j][2], E[j][3])));
            j++;
        }
        i = j - 1;
    }
    return acc;
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int contador = 0;
    while(cin>>n>>m>>p and n){
        vector<ii> P(p);
        rep(i, p) cin>>P[i].ff>>P[i].ss;
        
        ll q; cin>>q;
        while(q--){
            contador++;
            ll x; cin>>x;
            // if(contador == 2864 - 70) cout<<"AAAAA: "<<n<<' '<<m<<' '<<p<<'\n';
            ll l = 0, r = max(n, m);
            while(l < r){
                ll acc = get_area(P, (l + r) / 2);
                if(acc < x) l = (l + r) / 2 + 1;
                else r = (l + r) / 2;
            }
            
            vector<vi> E; 
            rep(i, p) {
                E.push_back({P[i].ff - l, 0, P[i].ss - l, P[i].ss + l});
                E.push_back({P[i].ff + l, 1, P[i].ss - l, P[i].ss + l});
            }
            sort(E.begin(), E.end());
            ll acc = get_area(P, l-1), hor = 0, lasty = max(0LL, E[0][0]);
            multiset<pair<ii, int>> S;
            ii ans = {-1, -1};
            rep(i, E.size()){
                // primera parte
                set<ll> SS; ll lx = 10000000000, rx = -10000000000;
                for(auto u: S){
                    if(u.ff.ss == rx) continue;
                    if(u.ff.ff >= rx){
                        if(lx != 10000000000 and lx >= 1) SS.insert(lx);
                        if(rx != -10000000000 and rx <= m) SS.insert(rx);
                        lx = u.ff.ff, rx = u.ff.ss;
                    }
                    else if(u.ff.ff < rx) rx = u.ff.ss;
                }
                if(lx != 10000000000 and lx >= 1) SS.insert(lx);
                if(rx != -10000000000 and rx <= m) SS.insert(rx);
                vi X; for(auto u: SS) X.push_back(u);
                hor = X.size();
                if(E[i][0] > 1 and acc + hor * (min(E[i][0], n+1) - lasty - 1) >= x){
                    ll col = (x - acc - 1) / hor; // la cantidad de columnas
                    ll aux = acc + col * hor;
                    ans = ii(col + lasty + 1, X[x - acc - col * hor - 1]);
                    break;
                }

                if(E[i][0] > 1) acc += hor * (min(E[i][0], n+1) - lasty - 1);
                
                lasty = max(0LL, E[i][0]);

                // segunda parte
                ll h = E[i][0];
                vector<pair<ii, int>> El, In;
                while(i < E.size() and E[i][0] == h){
                    if(E[i][1] == 0) {
                        S.insert({{E[i][2], E[i][3]}, 1});
                        In.push_back({{E[i][2], E[i][3]}, 1});
                    }
                    else {
                        S.erase(S.find({{E[i][2], E[i][3]}, 0}));
                        El.push_back({{E[i][2], E[i][3]}, 1});
                        S.insert({{E[i][2], E[i][3]}, 1});
                    }
                    i++;
                }
                i--;

                if(h <= 0){
                    for(auto u: El) S.erase(S.find(u));
                    for(auto u: In){
                        S.erase(S.find(u));
                        S.insert({{u.ff.ff, u.ff.ss}, 0});
                    }
                    continue;
                }

                ll aux = 0;
                lx = 10000000000, rx = -10000000000;
                bool in = 1;
                vector<ii> X2;
                for(auto u: S){
                    if(u.ff.ff > rx){
                        if(in and lx != 10000000000 and lx <= m and lx <= rx) X2.push_back({max(1LL, lx), min(rx, m)});
                        if(!in and lx != 10000000000 and 1 <= lx and lx <= m) X2.push_back({lx, lx});
                        if(!in and rx != -10000000000 and rx <= m and lx != rx) X2.push_back({rx, rx});
                        lx = u.ff.ff, rx = u.ff.ss;
                        in = u.ss;
                    }
                    else{ // u.ff.ff <= rx
                        if(!in and u.ss) {
                            if(1 <= lx and lx <= m and lx != rx) X2.push_back({lx, lx});
                            lx = rx;
                            in = 1;
                        } 
                        else if(in and !u.ss) {
                            if(1 <= u.ff.ff and lx <= u.ff.ff) X2.push_back({max(1LL, lx), u.ff.ff});
                            lx = u.ff.ss;
                            in = 0;
                        }
                        else if(!in and !u.ss and rx == u.ff.ff){
                            if(1 <= lx and lx <= m) X2.push_back({lx, lx});
                            if(1 <= rx and rx <= m and lx != rx) X2.push_back({rx, rx});
                            lx = u.ff.ss;
                        }
                        else if(!in and !u.ss and lx == rx) lx = u.ff.ss;
                        rx = u.ff.ss;
                    }
                }
                if(in and lx <= m and lx <= rx) X2.push_back({max(1LL, lx), min(rx, m)});
                if(!in and lx != 10000000000 and 1 <= lx and lx <= m) X2.push_back({lx, lx});
                if(!in and rx != -10000000000 and rx <= m and lx != rx) X2.push_back({rx, rx});
                for(auto u: X2){
                    if(acc + (u.ss - u.ff + 1) >= x) {
                        ans = {h, u.ff + (x - acc) - 1};
                        acc += (u.ss - u.ff + 1);
                        break;
                    }
                    acc += (u.ss - u.ff + 1);
                }
                if(ans.ff != -1) break;
                for(auto u: El) S.erase(S.find(u));
                for(auto u: In){
                    S.erase(S.find(u));
                    S.insert({{u.ff.ff, u.ff.ss}, 0});
                }
            }
            cout<<ans.ff<<' '<<ans.ss<<'\n';
        }
        cout<<"-\n";
    }


    return 0;
}