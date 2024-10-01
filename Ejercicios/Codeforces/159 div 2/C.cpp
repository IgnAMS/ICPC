#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<ll, ll> ii;
typedef double db;
typedef vector<ll> vi;
#define ff first
#define ss second
// g++ -std=c++11 A.cpp -o a && a <input.txt> output.txt
//  g++ -O2 D.cpp && time ./a.out < input.txt > output.txt

const db PI = acos(-1.0L);
const db EPS = 1e-12;

struct P {
    ll x, y;
    P() {}
    P(ll x, ll y): x(x), y(y) {}
    P operator-(const P& p) const { return P(x - p.x, y - p.y); }
    ll operator^(const P& p) const { return x * p.y - y * p.x; }
};

bool half(P& p) { return p.y > 0 or (p.y == 0 and p.x > 0); }


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    vector<P> A(n); rep(i, n) cin>>A[i].x>>A[i].y;
    sort(A.begin(), A.end(), [](auto& p1, auto& p2){
        int h1 = half(p1), h2 = half(p2);
        return h1 != h2? h1 > h2 : (p1 ^ p2) > 0;
    });
    // rep(i, n) cout<<A[i].x<<' '<<A[i].y<<'\n';
    db ans = 10000;
    rep(i, n) {
        db a = atan2(A[i].y, A[i].x);
        db b = atan2(A[(i + 1) % n].y, A[(i + 1) % n].x);
        if(a < 0) a += 2. * PI;
        if(b < 0) b += 2. * PI;
        if(b + 1e-12 < a) b += 2. * PI;
        // cout<<a<<' '<<b<<'\n';
        // cout<<(2. * PI - abs(a - b)) * 180. / PI <<'\n';
        ans = min(ans, 2. * PI - abs(a - b));
    }
    bool col = 1;
    rep(i, n - 1) if((A[i] ^ A[i + 1]) != 0) col = 0;
    if(col) cout<<0<<'\n';
    else cout<<setprecision(7)<<fixed<<ans * 180. / PI<<'\n';


    return 0;
}