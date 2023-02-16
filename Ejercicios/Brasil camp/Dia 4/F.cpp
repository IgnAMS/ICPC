#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
typedef long long ll;


ll DP[1000005];
ll V[1000005];
ll Leaves[1000005];
vector<vector<ll>> G(400005, vector<ll>());


ll dp(ll u, ll x) {
    if(V[u]) return DP[u];
    if(x != -1) V[u] = 1;
    if(x == -1 and G[u].size() == 0) return -1; // no se puede determinar
    if(x != -1 and Leaves[u] > x) return DP[u] = -1;
    if(DP[u] != -1 and x != -1 and DP[u] != x) return DP[u] = -1;
    
    ll notsolve = (x == -1);
    ll indnot = -1;
    ll l1 = 0, l2 = 0;
    for(auto v: G[u]) {
        if(DP[v] != -1 and dp(v, DP[v]) != -1) l1 += DP[v];
        else if(DP[v] != -1 and dp(v, DP[v]) == -1) { 
            V[u] = 1;
            return DP[u] = -1;
        }
        else if(DP[v] == -1 and V[v] == 1) {
            V[u] = 1;
            return DP[u] = -1;
        }
        else if(DP[v] == -1) {
            ll val = dp(v, -1);
            indnot = v;
            if(val == -1) notsolve++;
            l2 += Leaves[v];
        }
    }
    if(x != -1 and x - l1 == l2) {
        for(auto v: G[u]) if(DP[v] == -1) if(dp(v, Leaves[v]) == -1) {
            V[u] = 1;
            return DP[u] = -1;
        }
        return DP[u] = x;
    }
    else if(notsolve > 1) return -1;
    else if(x != -1 and notsolve == 1) {
        ll suma = 0;
        for(auto v: G[u]) if(DP[v] != -1) suma += DP[v];
        if(x - suma <= 0) {
            V[u] = 1;
            return DP[u] = -1;
        }
        ll val = dp(indnot, x - suma);
        if(val == -1) {
            V[u] = 1;
            return DP[u] = -1;
        }
    }
    else if(x == -1 and notsolve == 1) {
        ll suma = 0; 
        for(auto v: G[u]) suma += DP[v];
        return DP[u] = suma;
    }
    else if(notsolve == 0) { 
        if(G[u].size() == 0) {
            V[u] = 1;
            return DP[u] = x;
        }
        ll suma = 0;
        for(auto v: G[u]) suma += DP[v];
        if(DP[u] != suma) {
            V[u] = 1;
            return DP[u] = -1;
        }
    } 
    return DP[u] = x;
}



ll leaves(ll u) {
    if(G[u].size() == 0) return Leaves[u] = 1;
    if(Leaves[u] != 0) return Leaves[u];
    ll suma = 0;
    for(auto v: G[u]) suma += leaves(v);
    return Leaves[u] = suma; 
}



int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    for(int i = 1; i < n; i++) {
        int p; cin>>p; p--;
        G[p].push_back(i);
    }
    for(int i = 0; i < n; i++) {
        cin>>DP[i];
        V[i] = 0, Leaves[i] = 0;
        if(DP[i] == 0) DP[i] = -1;
    }

    leaves(0);
    ll val = dp(0, DP[0]);
    if(val == -1) cout<<"impossible\n";
    else {
        for(int i = 0; i < n; i++) cout<<DP[i]<<'\n';
    }
    

    return 0;
}

// ulimit -s 1000000 
// g++ -O2 F.cpp && time ./a.out <input.txt> output.txt
