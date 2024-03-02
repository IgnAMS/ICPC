#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double db;
typedef vector<ll> vl;
#define rep(i, n) for(int i = 0; i < n; i++)
#define EPS 1e-7



bool inRange(db x, db x1, db x2)
{
    return (x <= x2 + EPS && x1 <= x + EPS);
}

int main() {
    
    set<int> s;
    ll x1, y1, x2, y2;
    db ans = -1;
    int n;
    cin >> n >> x1 >> y1 >> x2 >> y2;

    vector<vl> mice;
    vector<vl> q;

    rep(i, n)
    {
        ll x, y, vx, vy;
        cin >> x >> y >> vx >> vy;
        if(x >= x1 and x <= x2 and y >= y1 and y2 >= y){
            s.insert(i);
        }
        mice.push_back({x, y, vx, vy});
    
    }

    rep(i, n)
    {
        ll x, y, vx, vy;
        // tie(x, y, vx, vy) = mice[i];
        x = mice[i][0], y = mice[i][1], vx = mice[i][2], vy = mice[i][3];

        if(y <= y1 and vy != 0)
        {
            db t = db(y1 - y) / db(vy);
            db nx = x + vx * t;
            
            if(inRange(nx, x1, x2) && (y1 - y) * vy >= 0)
                q.push_back({y1 - y, vy, -1, i});
        }
        if (y >= y1 and vy != 0){
            db t = db(y1 - y) / db(vy);
            db nx = x + vx * t;
            if(inRange(nx, x1, x2) && (y1 - y) * vy >= 0)
                q.push_back({y1 - y, vy, 1, i});
        }

        if(y2 <= y and vy != 0)
        {
            db t = db(y2 - y) / db(vy);
            db nx = x + vx * t;
            if(inRange(nx, x1, x2) && (y2 - y) * vy >= 0)
                q.push_back({y2 - y, vy, -1, i});
        }
        if(y2 >= y and vy != 0){
            db t = db(y2 - y) / db(vy);
            db nx = x + vx * t;
            if(inRange(nx, x1, x2) && (y2 - y) * vy >= 0)
                q.push_back({y2 - y, vy, 1, i});
        }

        if(x <= x1 and vx != 0)
        {
            db t = db(x1 - x) / db(vx);
            db ny = y + vy * t;
            if(inRange(ny, y1, y2) && (x1 - x) * vx >= 0)
                q.push_back({x1 - x, vx, -1, i});
        }
        if(x >= x1 and vx != 0){
            db t = db(x1 - x) / db(vx);
            db ny = y + vy * t;
            //cout << i << " " << t<<" "<<x << " " << ny << endl;
            if(inRange(ny, y1, y2) && (x1 - x) * vx >= 0)
                q.push_back({x1-x, vx, 1, i});
        }

        if(x2 <= x and vx != 0)
        {
            db t = db(x2 - x) / db(vx);
            db ny = y + vy * t;
            if(inRange(ny, y1, y2) && (x2 - x) * vx >= 0)
                q.push_back({x2-x, vx, -1, i});
        }
        if(x2 >= x and vx != 0 and x2-x != 0){
            db t = db(x2 - x) / db(vx);
            db ny = y + vy * t;
            if(inRange(ny, y1, y2) && (x2-x) * vx >= 0)
                q.push_back({x2-x, vx, 1, i});
        }
    }

    // for(auto u: q) {
    //     cout<<db(u[0]) / db(u[1]) <<' '<<u[2]<<' '<<u[3]<<'\n';
    // }
    sort(q.begin(), q.end(), [&](const vl a, const vl b) {
        if(a[0] * b[1] == a[1] * b[0])  {
            if(a[2] == b[2]) return a[3] < b[3];
            return a[2] < b[2];
        }
        return a[0] * b[1] < a[1] * b[0];
    });

    if(s.size() == n)
    {
        ans = 0;
    }
    else{

        for(auto vec : q)
        {   
            ll dist = vec[0], vel = vec[1], tipe = vec[2], i = vec[3]; 
            db t = db(dist) / db(vel); 
            // cout<<t<<' '<<tipe<<' '<<i<<'\n';
            //cout << t<<" " << tipe<<" " << i << endl;

            if(tipe == -1)
                s.insert(i);
            else
                if(s.count(i))
                    s.erase(i);

            if(s.size() == n)
            {
                ans = t;
                break;
            }
        }
    }

    cout <<fixed <<setprecision(11)<< ans << "\n";


}