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

bool V[1001][1001];
vector<vector<pll>> P(1001, vector<pll>(1001, pll(-1, -1)));
string S[1001];
vector<pll> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
map<int, char> mp = {{0, 'U'}, {1, 'D'}, {2, 'L'}, {3, 'R'}};  
int n, m; 


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;
    deque<pll> dq;
    pll B;
    rep(i, n) {
        cin>>S[i];
        rep(j, m) {
            if(S[i][j] == 'A') {
                dq.push_back({i, j});
                P[i][j] = {-2, -2};
            }
            if(S[i][j] == 'B') B = {i, j};
        }
    }


    while(!dq.empty()) {
        auto [i, j] = dq.front(); dq.pop_front();
        for(auto [x, y]: dirs) {
            int di = i+x, dj = j+y;
            if(0 <= di and di < n and 0 <= dj and dj < m) {
                if(P[di][dj].ff == -1 and S[di][dj] != '#') {
                    dq.push_back({di, dj});
                    P[di][dj] = {i, j};
                }
            } 
        }
    }
    if(P[B.ff][B.ss].ff == -1) {
        cout<<"NO\n";
        return 0;
    }
    int i = B.ff, j = B.ss;
    string Ans;
    ll cont = 0;
    while(P[i][j].ff != -2) {
        rep(k, 4) {
            if(P[i][j].ff + dirs[k].ff == i and P[i][j].ss + dirs[k].ss == j) {
                Ans += mp[k];
            }
        }
        tie(i, j) = P[i][j];
    }
    reverse(Ans.begin(), Ans.end());
    cout<<"YES\n";
    cout<<Ans.size()<<"\n";
    cout<<Ans<<"\n";
    


    
    
    return 0;
}