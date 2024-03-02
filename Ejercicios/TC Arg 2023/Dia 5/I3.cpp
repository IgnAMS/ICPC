#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double db;
typedef vector<ll> vl;
#define rep(i, n) for(int i = 0; i < n; i++)
#define EPS 1e-6



bool inRange(db x, db x1, db x2)
{
    return (x < x2 + EPS && x1 < x + EPS);
}
 
bool comp (tuple<db, int, int> a, tuple<db, int, int> b)
{
    db t1, t2;
    int tipe1, tipe2, i1, i2;
    
    tie(t1, tipe1, i1) = a;
    tie(t2, tipe2, i2) = b;

    if(abs(t1 - t2) < EPS)
    {
        return (i1 == i2? tipe1 < tipe2 : i1 < i2);
    }
    else{
        return (t1 < t2 + EPS);
    }

}

int main() {
    
    set<int>s;
    db x1, y1, x2, y2, ans = -1;
    int n;
    cin >> n >> x1 >> y1 >> x2 >> y2;

    vector<tuple<db, db, db, db>> mice;
    vector<tuple<db, int, int>> q;

    rep(i, n)
    {
        db x, y, vx, vy;
        cin >> x >> y >> vx >> vy;
        if(inRange(x, x1, x2) and inRange(y, y1, y2)){
            s.insert(i);
        }
        mice.push_back({x, y, vx, vy});
    }

    rep(i, n)
    {
        db x, y, vx, vy;
        tie(x, y, vx, vy) = mice[i];

        if(vy != 0) {
            if(y <= y1)
            {
                db t = (y1 - y) / vy;
                db nx = x + vx * t;
                
                if(inRange(nx, x1, x2) && t >= -EPS)
                    q.push_back({t, -1, i});
            }
            else{
                db t = (y1 - y) / vy;
                db nx = x + vx * t;
                if(inRange(nx, x1, x2) && t >= -EPS)
                    q.push_back({t, 1, i});
            }
            
            if(y2 <= y)
            {
                db t = (y2 - y) / vy;
                db nx = x + vx * t;
                if(inRange(nx, x1, x2) && t >= -EPS)
                    q.push_back({t, -1, i});
            }
            else{
                db t = (y2 - y) / vy;
                db nx = x + vx * t;
                if(inRange(nx, x1, x2) && t >= -EPS)
                    q.push_back({t, 1, i});
            }
        }

        if(vx != 0) {
            if(x <= x1)
            {
                db t = (x1 - x) / vx;
                db ny = y + vy * t;
                if(inRange(ny, y1, y2) && t >= -EPS)
                    q.push_back({t, -1, i});
            }
            else{
                db t = (x1 - x) / vx;
                db ny = y + vy * t;
                //cout << i << " " << t<<" "<<x << " " << ny << endl;
                if(inRange(ny, y1, y2) && t >= -EPS)
                    q.push_back({t, 1, i});
            }

            if(x2 <= x)
            {
                db t = (x2 - x) / vx;
                db ny = y + vy * t;
                if(inRange(ny, y1, y2) && t >= -EPS)
                    q.push_back({t, -1, i});
            }
            else{
                db t = (x2 - x) / vx;
                db ny = y + vy * t;
                if(inRange(ny, y1, y2) && t >= -EPS)
                    q.push_back({t, 1, i});
            }
        }
    }

    sort(q.begin(), q.end(), comp);

    if(s.size() == n)
    {
        ans = 0;
    }
    else{

        for(auto it : q)
        {
            db t;
            int tipe, i;
            
            tie(t, tipe, i) = it;
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