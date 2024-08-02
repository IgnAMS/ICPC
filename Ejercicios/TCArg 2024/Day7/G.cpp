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


struct P {
    db x, y;
    P(): x(0), y(0) {}
};

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll n, R; cin>>n>>R;
    P X[n];
    rep(i, n) {
        cin>>X[i].x;
    }

    rep(i, n) {
        db l = R, r = 3000 * R;
        rep(_, 62) {
            db m = (l + r) * 0.5;
            bool pos = 1;
            rep(j, i) {
                db dx = abs(X[i].x - X[j].x), dy = abs(m - X[j].y);
                if(dx <= 2 * R and m <= X[j].y) {
                    pos = 0;
                }
                else if(dx <= 2 * R and dy * dy + dx * dx <= 4 * R * R) {
                    pos = 0;
                }
            }
            if(pos) r = m;
            else l = m;
        }
        X[i].y = (l + r) * 0.5;
    }
    rep(i, n) {
        cout<<setprecision(7)<<X[i].y<<' '; 
    }
    cout<<'\n';


    return 0;
}