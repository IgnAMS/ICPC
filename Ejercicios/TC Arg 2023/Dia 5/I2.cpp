#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double db;
typedef vector<ll> vl;
typedef pair<ll, ll> pll;
#define rep(i, n) for(int i = 0; i < n; i++)
#define EPS 1e-7
#define ff first
#define ss second



bool inRange(db x, db x1, db x2)
{
    return (x <= x2 + EPS && x1 <= x + EPS);
}

int main() {
    
    set<ll>s;
    ll x1, y1, x2, y2;
    db ans = -1;
    ll n;
    cin >> n >> x1 >> y1 >> x2 >> y2;

    vector<tuple<ll, ll, ll, ll>> mice;
    vector<tuple<db, ll, ll>> q;

    rep(i, n)
    {
        ll x, y, vx, vy;
        cin >> x >> y >> vx >> vy;
        if(x >= x1 and x <= x2 and y >= y1 and y2 >= y){
            s.insert(i);
        }
        if((x == x1 or x == x2) and vx == 0) {
            cout<<"-1\n";
            return 0;
        }
        if((y == y1 or y == y2) and vy == 0) {
            cout<<"-1\n";
            return 0;
        }
        mice.push_back({x, y, vx, vy});
    }

    rep(i, n)
    {
        // cout<<"aloha\n";
        ll x, y, vx, vy;
        tie(x, y, vx, vy) = mice[i];
        pll entrada = {1e9, 1}, salida = {1e9, 1};

        if(y <= y1 and vy != 0)
        {
            db t = db(y1 - y) / db(vy);
            db nx = x + vx * t;
            
            if(inRange(nx, x1, x2) && (y1 - y) * vy >= 0) {
                q.push_back({t, i, -1});
                entrada = {y1 - y, vy};
            }
                
        }
        if (y >= y1 and vy != 0){
            db t = db(y1 - y) / db(vy);
            db nx = x + vx * t;
            if(inRange(nx, x1, x2) && (y1 - y) * vy >= 0) {
                q.push_back({t, i, 1});
                salida = {y1 - y, vy};
            }
                
        }

        if(y2 <= y and vy != 0)
        {
            db t = db(y2 - y) / db(vy);
            db nx = x + vx * t;
            if(inRange(nx, x1, x2) && (y2 - y) * vy >= 0) {
                q.push_back({t, i, -1});
                pll curr = {y2 - y, vy};
                if(entrada.ff * curr.ss > entrada.ss * curr.ff) 
                    entrada = curr;
            }
                
        }
        if(y2 >= y and vy != 0){
            db t = db(y2 - y) / db(vy);
            db nx = x + vx * t;
            if(inRange(nx, x1, x2) && (y2 - y) * vy >= 0) {
                q.push_back({t, i, 1});
                pll curr = {y2 - y, vy};
                if(salida.ff * curr.ss > salida.ss * curr.ff) 
                    salida = curr;
            }
        }

        if(x <= x1 and vx != 0)
        {
            db t = db(x1 - x) / db(vx);
            db ny = y + vy * t;
            if(inRange(ny, y1, y2) && (x1 - x) * vx >= 0) {
                q.push_back({t, i, -1});
                pll curr = {x1 - x, vx};
                // cout<<entrada.ff<<' '<<curr.ss<<' '<<entrada.ss<<' '<<curr.ff<<'\n';
                if(entrada.ff * curr.ss > entrada.ss * curr.ff) 
                    entrada = curr;
            }
        }
        if(x >= x1 and vx != 0){
            db t = db(x1 - x) / db(vx);
            db ny = y + vy * t;
            //cout << i << " " << t<<" "<<x << " " << ny << endl;
            if(inRange(ny, y1, y2) && (x1 - x) * vx >= 0) {
                q.push_back({t, i, 1});
                pll curr = {x1 - x, vx};
                if(salida.ff * curr.ss > salida.ss * curr.ff) 
                    salida = curr;
            }
        }

        if(x2 <= x and vx != 0)
        {
            db t = db(x2 - x) / db(vx);
            db ny = y + vy * t;
            if(inRange(ny, y1, y2) && (x2 - x) * vx >= 0) {
                q.push_back({t, i, -1});
                pll curr = {x2 - x, vx};
                if(entrada.ff * curr.ss > entrada.ss * curr.ff) 
                    entrada = curr;
            }
        }
        if(x2 >= x and vx != 0){
            db t = db(x2 - x) / db(vx);
            db ny = y + vy * t;
            if(inRange(ny, y1, y2) && (x2 - x) * vx >= 0) {
                q.push_back({t, i, 1});
                pll curr = {x2 - x, vx};
                if(salida.ff * curr.ss > salida.ss * curr.ff) 
                    salida = curr;
            }
        }
        if(entrada.ff * salida.ss == entrada.ss * salida.ff) {
            // cout<<entrada.ff<<' '<<entrada.ss<<' '<<salida.ff<<' '<<salida.ss<<'\n';
            cout<<"-1\n";
            return 0;
        }
    }

    sort(q.begin(), q.end());

    if(s.size() == n)
    {
        ans = 0;
    }
    else{

        for(auto [t, i, tipe]: q)
        {
            //cout << t<<" " << tipe<<" " << i << endl;

            if(tipe == -1)
                s.insert(i);
            else {
                if(s.count(i))
                    s.erase(i);
            }
            if(s.size() == n)
            {
                ans = t;
                break;
            }
        }
    }

    cout <<fixed <<setprecision(11)<< ans << "\n";


}