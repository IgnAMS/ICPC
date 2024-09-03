#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef double db; 
#define repx(i, a, b) for(int i = a; i < b; i++)
#define rep(i, n) repx(i, 0, n)



int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int a, b, c;
    cin >> a >> b >> c;

    if (a >= b + c || b >= a + c || c >= a + b) {
        cout << "S\n";
    }
    else {
        cout << "N\n";
    }



    return 0;
}

