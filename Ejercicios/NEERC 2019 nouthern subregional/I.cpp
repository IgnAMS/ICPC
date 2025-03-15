#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>

using namespace std;
#define repx(i, a, b) for(int i = a; i < b; i++)
#define rep(i, n) repx(i, 0, n)
typedef long long ll;
typedef pair<ll, ll> pll;

// g++ -O2 A.cpp && time ./a.out <input.txt> output.txt

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    ll n;
    cin >> n;

    ll left, right, up, down;
    left = down = 10000000000;
    right = up = -10000000000;

    rep(i, n) {
        ll x, y, h;
        cin >> x >> y >> h; 
        left = min(left, x - h);
        down = min(down, y - h);
        right = max(right, x + h);
        up = max(up, y + h);
    }

    ll ansx = right - (right - left)/2;
    ll ansy = up - (up - down)/2;
    // ll ansh = max(up - ansy, right - ansx);

    ll dx = right - left;
    ll dy = up - down;
    ll ansh;
    if (dy < dx) {
        ansh = (dx + 1)/2;
    }
    else {
        ansh = (dy + 1)/2;
    }

    cout << ansx << " " << ansy << " " << ansh << endl;

    return 0;
}


