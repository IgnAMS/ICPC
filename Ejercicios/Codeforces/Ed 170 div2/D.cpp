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

int R[5005], L[5005];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m; cin>>n>>m;
    int right = 0, left = 0, curr = 0;
    vl DP(m + 2, 0);
    vl A(n + 1); rep(i, n) cin>>A[i];
    A[n + 1] = 0;
    rep(i, n + 1) {
        int x = A[i];
        // cout<<"proceso "<<x<<'\n';
        if(x == 0) {
            curr++;
            // rep(j, curr + 1) cout<<DP[j]<<' '; cout<<'\n';
            for(int j = curr; j >= 0; j--) {
                left += L[j];
                if(j > 0) {
                    DP[j] = max(
                        DP[j] + right + left, 
                        DP[j - 1] + (right - R[j]) + (left + L[j - 1])
                    );
                }
                else {
                    DP[j] = DP[j] + right + left;
                }
                right -= R[j];
                R[j] = 0, L[j] = 0;
            }
            right = 0, left = 0;
        }
        else if(x > 0) {
            if(x > curr) continue;
            R[x]++;
            right++;
        }
        else { // x < 0
            x *= -1;
            if(curr - x < 0) continue;
            L[curr - x]++;
        }
    }

    ll ans = 0;
    rep(i, m + 1) ans = max(ans, DP[i]);
    cout<<ans<<'\n';

    return 0;
}