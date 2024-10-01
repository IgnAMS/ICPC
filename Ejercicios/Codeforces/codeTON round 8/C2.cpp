#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef int ll;
typedef pair<int, int> pll;
typedef double db;
typedef vector<int> vl;
#define ff first
#define ss second
#define pb push_back
// g++ -std=c++11 A.cpp -o a && a <input.txt> output.txt
// ulimit -s 1000000
// g++ -O2 D.cpp && time ./a.out <input.txt> output.txt


struct Event {
    int m, d, i;
    Event(int m, int d, int i): m(m), d(d), i(i) {}
    bool operator<(const Event& e) const { return m < e.m or (m == e.m and d < e.d); }
};

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--) {
        int n, x, y; cin>>n>>x>>y;

        vl X(x);
        rep(i, x) cin>>X[i];
        sort(X.begin(), X.end());
        int mn = X[0];
        rep(i, x) X[i] -= mn;
        
        X.pb(X[0]);
        int ans = x - 2;
        rep(i, x) {
            int dist = (X[i + 1] - X[i]);
            if(dist >= n) dist -= n;
            if(dist < 0) dist += n;

            if(dist == 2) ans++;
        }
       
        vector<Event> E;
        rep(i, x) {
            int dist = (X[i + 1] - X[i]);
            if(dist < 0) dist += n;
            if(dist >= n) dist -= n;
            if(dist >= 3) E.pb(Event(dist % 2, dist, i));
        }
        sort(E.begin(), E.end());
        
        for(auto& e: E) {
            if(y < (e.d - 1) / 2) {
                ans += y * 2;
                y = 0;
            }
            else {
                ans += e.d - 1;
                y -= (e.d - 1) / 2;
            }
        }
        cout<<ans<<'\n';
    }

    return 0;
}