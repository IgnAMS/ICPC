#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<ll> vl;
#define rep(i, n) for(int i = 0; i < n; i++)
#define repx(i, a, b) for(int i = a; i < b; i++)
#define pb push_back

#define ar array

struct pt{
    ll x, t, id, type, right;
    pt(ll x, ll t, ll id, ll type, ll right): x(x), t(t), id(id), type(type), right(right) {}
    bool operator < (const &pt other){
        return x < other.x;
    }
};

int main() {
    int n; 
    cin >> n;
    vector<pt> pts;
    rep(i, n){
        ll a, b, t;
        cin >> a >> b >> t;
        pt pt1(a, t, i, 0, b);
        
        pt pt2;
        pt2(b, t, i, 1, b);
        pts.push_back(pt1);
        pts.push_back(pt2);
    }
    sort(pts.begin(), pts.end());

    ll ans = 0;
    multiset<pt> ts;
    ll pos = pts[0].x;
    ll topt = pts[0].t;
    ll idopt = pts[0].id;


    for(int i = 0; i < pts.size(); ++i){
        if(pts[i].type == 0) {
            ts.insert(pts[i]);
            ll right = pos + ((pts[i].x - pos) / topt + 1) * topt;

            if(pts[i].t < topt) {
                // Tengo una mejor velocidad, evaluo si me conviene cambiar al tiro
                
                // Me conviene cambiar al tiro
                if(pts[i].x + pts[i].t <= right or pts[idtop].right < right) {
                    ans += (pts[i].x - pos) / topt;
                    
                    pos = pts[i].x;
                    topt = pts[i].t;
                    idopt = pts[i].id;
                }
                // Alcanzo a cambiar despues
                else if(right + pts[i].t <= pts[i].right) {
                    // puedo cambiar despues :)
                    ans += (pts[i].x - pos) / topt;

                    pos = right;
                    topt = pts[i].t;
                    idopt = pts[i].id;
                }
                // En caso contrario no alcanzo a cambiar despues por lo que no cambio
            }
            else { // Tengo una peor velocidad
                // si se morira el optimo, entonces lo cambio
                ll right = pos + ((pts[i].x - pos) / topt + 1) * topt;
                if(pts[idtop].right < right) {

                }
            }
            
        } else {
            if(pts[i].id == idopt)
            ts.erase(ts.find(pts[i].t));
        }
    }

}