#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
#define repx(i, a, b) for(int i = (int)a; i < (int)b; i++)
#define rep(i, n) repx(i, 0, n)
#define ff first
#define ss second
typedef pair<ll, ll> pll;


int main() {
    cout << fixed << setprecision(10);
    double h, r, a, b;
    cin >> h >> r >> a >> b;
    cout << h*((sqrt(a))/(sqrt(a)+sqrt(b))) << "\n";
    return 0;
}