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


const int mxN = 2e5 + 5;
ll n, k;
ll P[mxN], L[mxN], R[mxN], Pos[mxN], nxt[mxN];
string S, s;

bool good(ll u) {
    if(nxt[Pos[u]] == -1) return false;
    if(S[Pos[u]] < S[nxt[Pos[u]]]) return true;
    return false;
}


void dfs(int u, ll cost) {
    if(u == -1) return;
    if(cost > k) return;
    dfs(L[u], cost + 1);

    if(L[u] != -1 and P[L[u]]) P[u] = 1;
    else if(good(u) and cost <= k) {
        // cout<<"YEY pinte el "<<u<<'\n';
        k -= cost;
        P[u] = 1;
    }
    if(P[u]) dfs(R[u], 1);
}

void get_string(int u) {
    if(u == -1) return;
    get_string(L[u]);
    Pos[u] = S.length();
    S += s[u];
    get_string(R[u]);
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>k;
    cin>>s;
    rep(i, n) cin>>L[i]>>R[i];
    rep(i, n) L[i]--, R[i]--;


    get_string(0);
    vl Aux;
    rep(i, n) {
        while(!Aux.empty() and S[i] != S[Aux.back()]) {
            nxt[Aux.back()] = i; 
            Aux.pop_back();
        } 
        Aux.pb(i);
    }
    while(!Aux.empty()) {
        nxt[Aux.back()] = -1;
        Aux.pop_back();
    }


    // cout<<S<<'\n';
    dfs(0, 1);
    
    // rep(i, n) cout<<Pos[i]<<' '; cout<<'\n';
    // rep(i, n) cout<<good(i)<<' '; cout<<'\n';
    // rep(i, n) cout<<P[i]<<' '; cout<<'\n';
    vl invPos(n);
    rep(i, n) invPos[Pos[i]] = i;
    string ans = "";
    rep(i, n) {
        ans += S[i];
        if(P[invPos[i]]) ans += S[i];
    }
    cout<<ans<<'\n';


    return 0;
}