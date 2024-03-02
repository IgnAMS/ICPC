#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long 
#define ar array
#define rep(i, n) for(int i = 0; i<(int)n; ++i)
#define vl vector<ll> 
typedef long double db;

const int mxN = 1005, M = 1e9+7, inf = 1e9;

int sweep_line_x = -1e8;
const long double EPS = 1e-16, PI = acos(-1);

struct Circle {
    ll x, y, r;

    long double get_y(bool up_side) const {
        ll b = -2 * y;
        ll c = (ll) y * y + (sweep_line_x - x) * (ll)(sweep_line_x - x) - (ll) r * r;
        ll delta = b * (ll) b - 4 * c;
        return (-b + (up_side ? sqrt(delta) : -sqrt(delta))) / 2;
    }
};

struct Curve {
    bool up_side;
    Circle circle;

    bool operator<(const Curve &rhs) const {
        return circle.get_y(up_side) + EPS < rhs.circle.get_y(rhs.up_side);
    }
};

struct Interval {
    int owner_id;
    Curve up, down;

    bool operator<(const Interval &rhs) const {
        return down < rhs.down || up < rhs.up;
    }

    bool operator==(const Interval &rhs) const {
        return !(*this < rhs) && !(rhs < *this);
    }
};

int n;
Circle circle[mxN];
vector<int> adj[mxN];
int p[mxN];
long double ans = 0;

// DP[u][lastdia][lastnoche] = max(DP[v][!lastdia][lastnoche], DP[v][lastdia][lastdia][!lastnoche]) 

db DP[mxN][2][2];
db INF = 1e14;

// lastdia = 1 -> decidi que el siguiente que venga sera positivo
// lastdia = 0 -> decidi que el siguiente que venga sera negativo
db dfs(int u, int lastdia, int lastnoche, int p = -1) {
    if(DP[u][lastdia][lastnoche] != INF) return DP[u][lastdia][lastnoche];
    
    DP[u][lastdia][lastnoche] = 0;
    for(auto v: adj[u]) if(v != p) {
        db costdia = (lastdia? 1: -1) * PI * (circle[v].r) * (circle[v].r);
        db costnoche = (lastnoche? 1: -1) * PI * (circle[v].r) * (circle[v].r);
        DP[u][lastdia][lastnoche] += max(
            dfs(v, !lastdia, lastnoche, u) + costdia,
            dfs(v, lastdia, !lastnoche, u) + costnoche
        );
    }
    return DP[u][lastdia][lastnoche];
}

bool circle_contains(int i, int j){
    return ((ll)circle[i].x - (ll)circle[j].x) * ((ll)circle[i].x - (ll)circle[j].x) + ((ll)circle[i].y - (ll)circle[j].y) * ((ll)circle[i].y - (ll)circle[j].y) <= ((ll)circle[i].r - circle[j].r) * ((ll)circle[i].r - (ll)circle[j].r);
}

int main(){
#ifdef _DEBUG
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", " w", stdout);
#endif
    std::ios_base::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);
    
    cout << fixed << setprecision(12);

    cin >> n;
    vector<pair<int, int>> events;
    for(int i = 1; i <= n; i++) {
        cin >> circle[i].x >> circle[i].y >> circle[i].r;
    }

    circle[0] = {0, 0, inf};
    for(int i = 0; i <= n; ++i){
        p[i] = -1;
        for(int j = 0; j <= n; ++j) {
            if(circle[j].r > circle[i].r && circle_contains(i, j)){
                if(p[i] == -1 || circle[p[i]].r > circle[j].r) p[i] = j;
            }
        }
        adj[p[i]].push_back(i);
    }

    // rep(u, n + 1) {
    //     cout<<"Vecinos de "<<u<<'\n';
    //     for(auto v: adj[u]) cout<<v<<' '<<'\n';
    // }
    rep(i, mxN) rep(dia, 2) rep(noche, 2) DP[i][dia][noche] = INF;
    cout << dfs(0, 1, 1) << "\n";
    return 0;
}