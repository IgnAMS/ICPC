#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<ll, ll> ii;
typedef double db;
typedef vector<ll> vi;
#define ff first
#define ss second
// g++ -std=c++11 A.cpp -o a && a <input.txt> output.txt
// g++ -O2 D.cpp && time ./a.out <input.txt> output.txt

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    vi P;
    rep(i, 1000) P.push_back(i * i); 
    while(t--) {
        int n; cin>>n;
        vi Ans(n + 1);
        int curr = n - 1;
        while(curr != 0) {
            ll x = *lower_bound(P.begin(), P.end(), curr);
            int j = 0;
            repx(i, x - curr, curr + 1) {
                Ans[i] = curr - j;
                j++;
            }
            curr = x - curr - 1;
        }
        rep(i, n) cout<<Ans[i]<<' '; cout<<'\n';
    }





    return 0;
}