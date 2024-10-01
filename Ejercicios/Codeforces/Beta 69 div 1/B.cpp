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

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--) {
        ll a, b; cin>>a>>b;
        // ((a * a / 4) /  2) / (a * b)
        // (a / 8) / * b
        // a / (8 * b)

        // a/4 == b -> x = b * 4
        if(b == 0) {
            cout<<1<<'\n';
            continue;
        }

        db ans;
        if(a >= 4 * b) {
            db left = 4 * b;
            db right = a - left;
            ans = 0.5 + 0.5 * (db(left * b) / 2 + db(right * b)) / db(a * b);
        }
        else {
            ans = 0.5 + 0.5 * db(a) / db(b * 8);
        }
        cout<<setprecision(8)<<fixed<<ans<<'\n';
    }
    

    return 0;
}