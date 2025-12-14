#pragma GCC optimize("Ofast")
#include<string.h>
#include<vector>
#include<map>
#include<deque>
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
// g++ -O2 D.cpp && time ./a.out <input.txt> output.txt

const int mxN = 1e3+5;
int n, m;
string S[mxN];
vector<array<int, 3>> P(mxN * mxN, {-1, -1, -1});
ll posible = true;
vector<pll> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
map<int, char> mp = {{0, 'U'}, {1, 'D'}, {2, 'L'}, {3, 'R'}};  

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;
    deque<array<int, 3>> dq; 
    pll A;
    rep(i, n) {
        cin>>S[i];
        rep(j, m) {
            if(S[i][j] == 'M') {
                dq.push_back({i, j, 0});
                P[i * m + j] = {-2, -2, 0};
            }
        }
    }

    rep(i, n) rep(j, m) {
        if(S[i][j] == 'A') {
            A = {i, j};
            dq.push_back({i, j, 1});
            P[i * m + j] = {-2, -2, 1}; 
        }
    }
    while(!dq.empty()) {
        auto [i, j, t] = dq.front(); dq.pop_front();
        for(auto [x, y]: dirs) {
            int di = i+x, dj = j+y;
            if(0 <= di and di < n and 0 <= dj and dj < m) {
                if(S[di][dj] != '#' and P[di * m + dj][0] == -1) {
                    // cout<<"P["<<di<<", "<<dj<<"]: "<<i<<", "<<j<<", "<<t<<"\n";
                    P[di * m + dj] = {i, j, t};
                    dq.push_back({di, dj, t});
                }
            }
        }
    }

    pll ans = {-1, -1};
    rep(i, n) {
        if(P[i * m + m-1][2] == 1) ans = {i, m-1};
        if(P[i * m + 0][2] == 1) ans = {i, 0};
    }
    rep(i, m) {
        if(P[0 * m + i][2] == 1) ans = {0, i};
        if(P[(n-1)*m + i][2] == 1) ans = {n-1, i};
    }

    if(A.ff == n-1 or A.ff == 0 or A.ss == m-1 or A.ss == 0) {
        ans = A;
        cout<<"YES\n";
        cout<<"0\n";
        return 0;
    }
    if(ans.ff == -1) {
        cout<<"NO\n";
        return 0;
    }

    int i = ans.ff, j = ans.ss;
    string Ans = "";
    while(i != -2) {
        rep(k, 4) {
            if(P[i * m + j][0] + dirs[k].ff == i and P[i * m + j][1] + dirs[k].ss == j) {
                Ans += mp[k];
            }
        }
        // cout<<i<<" "<<j<<"\n";
        int aux;
        int next_i = P[i * m + j][0], next_j = P[i * m + j][1];
        i = next_i, j = next_j;
    }
    reverse(Ans.begin(), Ans.end());
    cout<<"YES\n";
    cout<<Ans.size()<<"\n";
    cout<<Ans<<"\n";
    
    return 0;
}