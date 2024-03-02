#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<ll, ll> pll;
typedef long double db;
typedef vector<ll> vl;
#define ff first
#define ss second
#define pb push_back
// g++ -std=c++11 A.cpp -o a && a <input.txt> output.txt
// ulimit -s 1000000
// g++ -O2 D.cpp && time ./a.out <input.txt> output.txt

const ll iter = 10000;
db Num[iter][2];
db Den[iter][2];


db poly(vl &P, db x) {
    db ans = 0;
    rep(i, P.size()) ans += P[i] * pow(x, i);
    return ans;
}

db integrate(ll ind, db d, ll W) {
    db ans = 0;
    rep(i, iter) {
        db num = Num[i][ind];
        db den = Den[i][ind];
        db dy = max(d, num / den);
        ans += dy;
    }
    ans = ans * W / db(iter);
    return ans;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    ll W, D, A, K; 
    while(cin>>W>>D>>A>>K) {
        vector<vl> P(2, vl(K + 1)), Q(2, vl(K + 1));
        rep(i, 2) {
            rep(j, K + 1) cin>>P[i][j];
            rep(j, K + 1) cin>>Q[i][j];
        }

        rep(ind, 2) rep(i, iter) {
            db x = ((db(i) + 0.5)   * W) / db(iter);
            Num[i][ind] = poly(P[ind], x);
            Den[i][ind] = poly(Q[ind], x);
        }

        db l = -D, r = 0;
        rep(i, 25) {    
            db m = (l + r) * 0.5;
            db area1 = integrate(0, m, W);
            db area2 = integrate(1, m, W);
            if(area1 - area2 >= A) l = m;
            else r = m;
        }
        // cout<<setprecision(8)<<fixed<<l<<' '<<r<<'\n';
        cout<<setprecision(5)<<fixed<<-(l + r) * 0.5<<'\n';
    }

    return 0;
}