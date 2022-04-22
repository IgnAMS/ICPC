#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef double db;
typedef pair<db, db> ii;
typedef vector<ll> vi;
#define ff first
#define ss second
// g++ -std=c++11 A.cpp -o a && a <input.txt> output.txt
//  g++ -O2 D.cpp && time ./a.out < input.txt > output.txt

ii A, B, C, D;
db f(db t){
    ii d1 = ii(B.ff - A.ff, B.ss - A.ss);
    ii d2 = ii(D.ff - C.ff, D.ss - C.ss);
    ii pa = ii(A.ff + d1.ff * t, A.ss + d1.ss * t);
    ii pc = ii(C.ff + d2.ff * t, C.ss + d2.ss * t);
    ii dif = ii(pa.ff - pc.ff, pa.ss - pc.ss);
    return sqrt(dif.ff * dif.ff + dif.ss * dif.ss);
}

double min_ternary_search(double l, double r, int times) {
    while (times--) {
        double d = (r - l) / 3.0;
        double m1 = l + d, m2 = r - d;
        double f1 = f(m1), f2 = f(m2);
        if (f1 <= f2) r = m2;
        if (f1 >= f2) l = m1;
    }
    return f((l+r)*.5);
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    repx(i, 1, t + 1) {
        cin>>A.ff>>A.ss>>B.ff>>B.ss>>C.ff>>C.ss>>D.ff>>D.ss;
        cout<<"Case "<<i<<": ";
        cout<<setprecision(8)<<fixed<<min_ternary_search(0, 1, 100)<<'\n';
    }

    return 0;
}