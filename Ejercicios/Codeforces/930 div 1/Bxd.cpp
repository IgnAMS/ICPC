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

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--) {
        ll x; cin>>x;
        ll last = 0;
        vl Ans(35, 0);
        rep(i, 31) {
            if(((1LL<<i) & x) and Ans[i] == 1) {
                Ans[i] = 0, Ans[i + 1] = 1;
                last = i + 1;
            }
            else if(i > 0 and ((1LL<<i) & x) and Ans[i - 1] == 1) {
                Ans[i - 1] = -1, Ans[i + 1] = 1;
                last = i + 1;
            }
            else if((1LL<<i) & x) {
                Ans[i] = 1;
                last = i;   
            }
            // cout<<((1LL<<i) & x)<<' ';
        }
        // cout<<'\n';
        cout<<last + 1<<'\n';
        rep(i, last + 1) cout<<Ans[i]<<' '; cout<<'\n';
    }


    return 0;
}