#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma") // could make sigill runtime error
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

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--) {
        ll a, b; cin>>a>>b;
        deque<vl> q;
        map<vl, ll> mp;
        q.push_back({0,0,1});
        mp[{0,0,1}] = 0;
        bool stop = 0;
        ll steps = 0;
        ll ans = 0;
        while(!q.empty() and !stop) {
            steps++;
            auto u = q.front(); q.pop_front();
            ll x = u[0], y = u[1], d = u[2];
            // cout<<"analizo "<<u[0]<<' '<<u[1]<<' '<<u[2]<<'\n';
            if(x + d <= a and !mp.count({x + d, y, d})) {
                q.push_back({x + d, y, d});
                mp[{x + d, y, d}] = mp[{x,y,d}] + 1;
                if(x + d == a and y == b) {
                    stop = 1;
                    ans = mp[{x, y, d}] + 1;
                }
            }
            if(y + d <= b and !mp.count({x, y + d, d})) {
                q.push_back({x, y + d, d});
                mp[{x, y + d, d}] = mp[{x,y,d}] + 1;
                if(x == a and y + d == b) {
                    stop = 1;
                    ans = mp[{x, y, d}] + 1;
                }
            }
            if(d < min(a - x, b - y)) {
                q.push_back({x, y, d + 1});
                mp[{x, y, d + 1}] = mp[{x, y, d}] + 1;
            }
        }
        cout<<steps<<' '<<ans<<'\n';
    }
    


    return 0;
}