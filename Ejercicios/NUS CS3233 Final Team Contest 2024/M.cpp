#pragma GCC optimize("Ofast")
#include<string.h>
#include<vector>
#include<map>
#include<deque>
#include<queue>
#include<iostream>
#include<algorithm>
#include<numeric>
#include <cmath>
#include<set>
#include<array>
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
// g++ -std=c++17 A.cpp -o a && ./a <input.txt> output.txt   
// ulimit -s 1000000
// g++ -std=c++17 -O2 M.cpp && time ./a.out <input.txt> output.txt

deque<int> S;
const int mxN = 1e6+5;
ll inDeg[mxN], A[mxN], possible[mxN], V[mxN];
int ans = 0;


int DP[mxN][2][2];
int dp(int u, int last, int first, int target) {
    V[u] = 1;
    // cout<<u<<" "<<last<<" "<<target<<"\n";
    if(A[u] == target and !first and !last and possible[u]) return 1;
    if(A[u] == target) return 0;
    if(DP[u][last][first] != -1) return DP[u][last][first];
    
    // no es posible asignar el primero como 1
    if(u == target and first and !possible[u]) return 0;
    
    if(u == target and first) {
        // obligo a que lo tome
        DP[u][last][first] = dp(A[u], 1, first, target) + 1;
    }
    else if(u == target and !first) {
        DP[u][last][first] = dp(A[u], 0, first, target);
    }
    else if(!last and possible[u]) {
        DP[u][last][first] = max(
            dp(A[u], 1, first, target) + 1, 
            dp(A[u], 0, first, target)
        );
    }
    else DP[u][last][first] = dp(A[u], 0, first, target);

    return DP[u][last][first];
}   
    

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    rep(i, n) rep(a, 2) rep(b, 2) DP[i][a][b] = -1;
    rep(i, n) {
        cin>>A[i]; A[i]--;
        possible[i] = 1;
        inDeg[A[i]]++;
    }
    rep(i, n) {
        if(inDeg[i] == 0) S.push_back(i);
    }
    while(!S.empty()) {
        int u = S.front(); S.pop_front();
        V[u] = 1;

        if(possible[u]) {
            ans++;
            possible[A[u]] = 0;
        }
        inDeg[A[u]]--;
        if(inDeg[A[u]] == 0) S.push_back(A[u]);
    }
    
    rep(u, n) if(!V[u]) {
        // cout<<"entre acá con "<<u<<"\n";
        // cout<<"aumento en "<<dp(u, 0, u)<<" en el nodo "<<u<<"\n";
        ans += max(dp(u, 0, 1, u), dp(u, 0, 0, u));
    }

    cout<<ans<<"\n";
    return 0;
}
