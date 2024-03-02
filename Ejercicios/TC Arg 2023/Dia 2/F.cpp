#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef vector<ll> vl;

#define rep(i, n) for(int i = 0; i<(int)n; ++i)

int main() {
    db r, d;
    cin >> r >> d;
    int n, ans = 0;
    cin >> n;

    rep(i, n)
    {
        db x, y, ri;
        cin >> x >> y >> ri;

        db dx = sqrt(x*x + y*y);

        if(dx - ri >= r-d && dx + ri <= r) ans++;
    }

    cout << ans << "\n";
}


// g++ -std=c++11 A.cpp -o a && a <input.txt> output.txt
// ulimit -s 1000000
// g++ -O2 D.cpp && time ./a.out <input.txt> output.txt
