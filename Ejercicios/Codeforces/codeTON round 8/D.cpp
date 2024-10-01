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

map<ll, ll> mp[1005][1005];
bool V[1005][1005];
ll X[1005][1005];
int n, k;

struct P {
    ll i, j, v;
    bool operator<(const P& p) const { return v < p.v; }
};


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--) {
        cin>>n>>k;
        rep(i, n) repx(j, i, n) {
            cin>>X[i][j];
            mp[i][j].clear();
            V[i][j] = 0;
        }

        P mx[n][n];
        for(int i = n - 1; i >= 0; i--) for(int j = n - 1; j >= i; j--) {
            mx[i][j] = {i, j, X[i][j]};
            if(i + 1 < n and j + 1 < n and mx[i + 1][j + 1].v > mx[i][j].v) {
                mx[i][j] = mx[i + 1][j + 1];
            }
            if(j + 1 < n and mx[i][j + 1].v > mx[i][j].v) {
                mx[i][j] = mx[i][j + 1];
            }
            if(j > i and i + 1 < n and mx[i + 1][j].v > mx[i][j].v) {
                mx[i][j] = mx[i + 1][j];
            }

            cout<<i<<' '<<j<<' '<<mx[i][j].v<<'\n';
        }

        vl Ans;
        priority_queue<P, vector<P>> pq;
        

        cout<<'\n';
    }





    return 0;
}