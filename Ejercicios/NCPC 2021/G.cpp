#include <bits/stdc++.h>

using namespace std;
 
#define ll long long 
#define ar array
#define rep(i, n) for(int i = 0; i<(int)n; ++i)
#define db long double

const int mxN = 2e5+5, M = 1e9+7;

struct point{ db x, y;
    point() {x = y = 0.0 ;}
    point(db _x, db _y) : x(_x), y(_y) {}
    //point operator + (const point& p) const {return point(x + p.x, y + p.y);}
    //db operator*(const point &p) const {return x * p.x + y * p.y;}
};

db dist(point p1, point p2){
    return sqrt((p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y));
}

void solve(){
    int n;
    cin >> n;
    vector<pair<point, db>> cr;
    rep(i, n){
        db a, b, r;
        cin >> a >> b >> r;
        point ff(a, b);
        cr.push_back({ff, r});
    }
    //srand(time(NULL));
    db ans = 0;
    for(db i = 0; i < 3000; ++i){
        for(db j = 0; j < 3000; ++j){
            db fi = i / 100.0 + (0.005);
            db fj = j / 100.0 + (0.005);
            int can = 0;
            fi -= 10, fj -= 10;
            // cerr<<fi<<' '<<fj<<'\n';
            point st(fi, fj);
            rep(k, n){
                if(-1 <= fi and fi <= 1 and 0 <= fj and fj <= 1) cerr<<fi<<' '<<fj<<' '<<dist(st, cr[k].first)<<'\n';
                
                if(dist(st, cr[k].first) <= cr[k].second) {
                    cerr<<fi<<' '<<fj<<'\n';
                    can = 1;
                }
            }
            ans += can;
        }
    }
    cout << ans <<' '<<3000 * 3000<< "\n";
}
 
signed main(){
#ifdef _DEBUG
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", " w", stdout);
#endif
    std::ios_base::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);
 
    cout << fixed << setprecision(6);
    int t = 1;
    while(t--){
        solve();
    }
}