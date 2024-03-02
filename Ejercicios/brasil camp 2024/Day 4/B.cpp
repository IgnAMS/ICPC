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



const int mxiter = 60;
vector<vector<db>> X;
int n;

db dist(vector<db>& A, vector<db>& B) {
    db ans = 0;
    rep(i, 3) ans += (A[i] - B[i]) * (A[i] - B[i]);
    return ans;
}

db maxdist(vector<db> x) {
    db mx = 0;
    rep(i, n) mx = max(mx, dist(x, X[i]));
    return mx;
}

vector<db> ternz(db x, db y) {
    db l = -1e4, r = 1e4;
    rep(_, mxiter) {
        db ml = l + (r - l) / 3., mr = r - (r - l) / 3.;
        vector<db> auxl = {x, y, ml};
        vector<db> auxr = {x, y, mr};
        if(maxdist(auxl) > maxdist(auxr)) l = ml;
        else r = mr;
    }
    db mid = (l + r) * 0.5;
    vector<db> aux = {x, y, mid};
    return {x, y, mid, maxdist(aux)};
}

vector<db> terny(db x) {
    db l = -1e4, r = 1e4;
    rep(_, mxiter) {
        db ml = l + (r - l) / 3., mr = r - (r - l) / 3.;
        if(ternz(x, ml)[3] > ternz(x, mr)[3]) l = ml;
        else r = mr;
    }
    db mid = (l + r) * 0.5;
    return ternz(x, mid);
}

vector<db> ternx() {
    db l = -1e4, r = 1e4;
    rep(_, mxiter) {
        db ml = l + (r - l) / 3., mr = r - (r - l) / 3.;
        auto auxl = terny(ml);
        auto auxr = terny(mr);
        if(terny(ml)[3] > terny(mr)[3]) l = ml;
        else r = mr;
    }
    db mid = (l + r) * 0.5;
    return terny(mid);
}


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    X.assign(n, vector<db>(3));
    rep(i, n) cin>>X[i][0]>>X[i][1]>>X[i][2];

    vector<db> ans = ternx();
    cout<<setprecision(12)<<fixed<<ans[0]<<' '<<ans[1]<<' '<<ans[2]<<'\n';

    return 0;
}