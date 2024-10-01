#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m; cin>>n>>m;
    string s; cin>>s;
    int A[6][n+1]; memset(A, 0, sizeof A);
    vector<string> S = { "abc", "acb", "bac", "bca", "cab", "cba" };
    rep(i, n){
        rep(j, 6) A[j][i+1] = A[j][i] + (s[i] != S[j][i%3]);
    }
    rep(i, m){
        int l, r; cin>>l>>r;
        int ans = 1000000;
        rep(j, 6) ans = min(ans, A[j][r] - A[j][l-1]);
        cout<<ans<<'\n';
    }



    return 0;
}