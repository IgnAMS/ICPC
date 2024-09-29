#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vl;
typedef pair<ll, ll> pll;
#define repx(i, a, b) for(int i = a; i < b; i++)
#define rep(i, n) repx(i, 0, n)



int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    ll N[41];
    N[0] = N[1] = 1;
    repx(i, 2, 41) N[i] = N[i - 2] + N[i - 1];
    int n; cin>>n;
    cout<<N[n]<<'\n';
    return 0;
}