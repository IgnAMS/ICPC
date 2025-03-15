#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>

using namespace std;
#define repx(i, a, b) for(int i = a; i < b; i++)
#define rep(i, n) rep(i, 0, n)
typedef long long ll;
typedef pair<ll, ll> pll;

// g++ -O2 A.cpp && time ./a.out <input.txt> output.txt

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int a, b, n;
    cin >> a >> b >> n;

    int d = b - a;
    int c = ((n - a)/d)*d != (n - a);
    cout << 2*((n - a)/d + c) - 1 << endl;

    return 0;
}


