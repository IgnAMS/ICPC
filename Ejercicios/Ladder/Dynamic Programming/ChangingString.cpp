#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma") // could make sigill runtime error
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

const int mxN = 1e3+5;
ll DP[mxN][mxN];
pll P[mxN][mxN];

string a, b;
int n, m; 

ll dp(int i, int j) {
    if(i == n) return m - j;
    if(j == m) return n - i;

    if(DP[i][j] != -1) return DP[i][j];

    DP[i][j] = 0;
    ll cost1 = dp(i + 1, j + 1) + (a[i] != b[j]),
        cost2 = dp(i + 1, j) + 1,
        cost3 = dp(i, j + 1) + 1;


    if(cost1 <= cost2 and cost1 <= cost3) {
        DP[i][j] = cost1;
        P[i][j] = {1, 1};
    }
    else if(cost2 <= cost1 and cost2 <= cost3) {
        DP[i][j] = cost2;
        P[i][j] = {1, 0};
    }
    else {
        DP[i][j] = cost3;
        P[i][j] = {0, 1};
    }

    // cerr<<i<<' '<<j<<' '<<DP[i][j]<<'\n';
    return DP[i][j];
}



int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>a>>b;
    n = a.length(), m = b.length();

    rep(i, n) rep(j, m) DP[i][j] = -1;

    cout<<dp(0, 0)<<'\n';

    int i = 0, j = 0;
    ll posi = 0;
    while(i < n and j < m) {
        ll cost1 = dp(i + 1, j + 1) + (a[i] != b[j]),
            cost2 = dp(i + 1, j) + 1,
            cost3 = dp(i, j + 1) + 1;

        if(DP[i][j] == cost1) {
            if(a[i] != b[j]) {
                cout<<"REPLACE "<<posi + 1<<' '<<b[j]<<'\n';
            }
            posi += 1;
            i += 1;
            j += 1;
        }
        else if(DP[i][j] == cost2) {
            cout<<"DELETE "<<posi + 1<<'\n';
            i += 1;
        }
        else {
            cout<<"INSERT "<<posi + 1<<' '<<b[j]<<'\n';
            posi += 1;
            j += 1;
        }
    }
    while(i < n) {
        cout<<"DELETE "<<posi + 1<<'\n';
        i++;
    }
    while(j < m) {
        cout<<"INSERT "<<posi + 1<<' '<<b[j]<<'\n';
        posi++;
        j++;
    }


    return 0;
}