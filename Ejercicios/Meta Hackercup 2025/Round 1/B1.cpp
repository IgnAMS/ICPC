#pragma GCC optimize("Ofast")
#include<vector>
#include<iostream>
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
// g++ -O2 D.cpp && time ./a.out <input.txt> output.txtß

const int mxN = 5e5+5;
ll n, A, B;

ll DP[202][102];
pll P[202][102];

ll dp(int i, int curr) {
    if(i == 2 * n and curr == B) return B;
    if(i == 2 * n) return 0;

    if(DP[i][curr] != -1) return DP[i][curr];

    ll right = i < n? min(B, A): B;
    DP[i][curr] = 0;
    repx(j, 1, right + 1) {
        if(j * curr <= right and dp(i+1, curr*j) > DP[i][curr]) {
            DP[i][curr] = dp(i + 1, curr * j);
            P[i][curr] = {i+1, curr*j};
        }
    }
    return DP[i][curr];
}



void solve(int caso) {
    cin>>n>>A>>B;
    rep(i, 2 * n) rep(j, max(A, B) +1) DP[i][j] = -1;
    dp(0, 1);

    int ind = 0, curr = 1;
    cout<<"Case #"<<caso+1<<": ";
    rep(i, 2*n) {
        pll p = P[ind][curr];
        ll new_curr = p.ss;
        ind++;
        cout<<new_curr / curr<<" ";
        curr = new_curr;
    }
    cout<<"\n";
    

}


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t; 
    rep(i, t) solve(i);
    return 0;
}