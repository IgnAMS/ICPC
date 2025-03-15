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

bool DP[1001][1001];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, k, e; cin>>n>>k>>e;
    int left = e, right = n - k - e;

    DP[left][right] = 1;
    int ans = left + right;
    repx(i, 1, max(left, right) + 1) if(i != k) {
        for(int a = 0; a <= left; a++) {
            for(int b = 0; b <= right; b++)  {
                if(a + i <= left) DP[a][b] |= DP[a + i][b];
                if(b + i <= right) DP[a][b] |= DP[a][b + i];
                if(DP[a][b]) ans = min(ans, a + b);
            }
        }
    }
    cout<<ans<<'\n';

    return 0;
}