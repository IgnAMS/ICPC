#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vl;
typedef pair<ll, ll> pll;
#define repx(i, a, b) for(int i = a; i < b; i++)
#define rep(i, n) repx(i, 0, n)



int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    
    int n, k;
    cin >> n >> k;

    cout << (k + 1)/n - 1 << "\n";
    return 0;
}