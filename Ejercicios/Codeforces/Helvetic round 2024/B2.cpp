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

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    vl A(n); rep(i, n) cin>>A[i];

    vl Ans(n, 0), Pos(n);
    cout<<"YES\n";
    rep(i, n) {
        if(i == 0) {
            cout<<"1 1\n";
            Pos[i] = 0;
            Ans[i] = 0;
        }
        // La query es grande
        else if(A[i] >= i) {
            cout<<i + 1<<' '<<A[i] - i + 1<<'\n';
            Pos[i] = A[i] - i;
            Ans[i] = 0;
        }
        // La query es chica A[i] < i
        else if(A[i] < i) {
            // A[i] < i
            // 0 <= i - A[i]
            cout<<i + 1<<' '<<Pos[i - A[i]] + 1<<'\n';
            Pos[i] = Pos[i - A[i]];
            Ans[i] = i - A[i];
        }
    }
    rep(i, n) cout<<Ans[i] + 1<<' '; cout<<'\n';


    return 0;
}