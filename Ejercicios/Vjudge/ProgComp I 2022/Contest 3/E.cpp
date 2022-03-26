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


db f(vector<ii>& P, int n, db c) {
    db t = 0;
    rep(i, n) t += db(P[i].ff) / db(c + P[i].ss);
    return t;
}

db bs(vector<ii>& P, int n, int t) {
    db l = 10000000., r = 10000000.;
    rep(i, n) l = min(l, 1.0 * P[i].ss); 
    l *= -1.;
    // cout<<l<<' '<<r<<'\n';
    rep(i, 1000) {
        db m = (l + r) / 2.0;
        if(f(P, n, m) < t) r = m; // la sumatoria es menor a t, debo disminuir 
        else l = m;
    }
    return (l + r) / 2.0;

}



int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, t; cin>>n>>t;
    vector<ii> P(n); rep(i, n) cin>>P[i].ff>>P[i].ss;
    // cout<<"con c = "<<4<<" me demoro "<<f(P, n, 4.)<<'\n';
    cout<<setprecision(11)<<fixed<<bs(P, n, t)<<'\n';



    return 0;
}