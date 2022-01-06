#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<int,int> ii;
typedef double db;
#define ff first
#define ss second

ll AnsL[200005], AnsR[200005], L[200005], R[200005];
ll ans(int x, bool o){
    if(o){
        if(R[x] == -1) return x;
        if(AnsR[x] != -1) return AnsR[x];
        return AnsR[x] = ans(R[x], !o);
    }
    else{
        if(L[x] == -1) return x;
        if(AnsL[x] != -1) return AnsL[x]; 
        return AnsL[x] = ans(L[x], !o);
    }
    
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    // Inicializo variables globales
    memset(AnsL, -1, sizeof AnsL); memset(AnsR, -1, sizeof AnsR); 
    memset(R, -1, sizeof R); memset(L, -1, sizeof L);
    int n, m; cin>>n>>m;
    ll H[n]; rep(i, n) cin>>H[i];
    
    // Inicializo los L y los R hacia ambos sentidos
    stack<ii> qL; qL.push(ii(2000000, -1));
    rep(i, n){
        while(!qL.empty() and qL.top().ff < H[i]) qL.pop();
        L[i] = qL.top().ss;
        qL.push(ii(H[i], i));
    }
    stack<ii> qR; qR.push(ii(2000000, -1));
    for(int i = n-1; i>=0; i--){
        while(!qR.empty() and qR.top().ff < H[i]) qR.pop();
        R[i] = qR.top().ss; 
        qR.push(ii(H[i], i));
    }

    // Precomputo las respuestas
    rep(i, n) AnsL[i] = ans(i, 0), AnsR[i] = ans(i, 1); 
    // rep(i, n) cout<<AnsL[i]<<' '; cout<<'\n';
    // rep(i, n) cout<<AnsR[i]<<' '; cout<<'\n';

    rep(_, m){
        string line; cin>>line;
        if(line == "L") {
            int i; cin>>i; i--;
            if(AnsL[i] != i and AnsR[AnsL[i]] != AnsL[i]) AnsL[i] = AnsR[AnsL[i]]; 
            cout<<AnsL[i] + 1<<'\n';
        }
        else if(line == "R") { 
            int i; cin>>i;  i--;
            if(AnsR[i] != i and AnsL[AnsR[i]] != AnsR[i]) AnsR[i] = AnsL[AnsR[i]];
            cout<<AnsR[i] + 1<<'\n';
        }
        else {
            int i, h; cin>>i>>h; i--;
            H[i] = h;
            // Lado derecho
            vector<int> vL; 
            while(R[i] >= 0 and H[i] > H[R[i]]) {
                vL.push_back(R[i]);
                L[R[i]] = i, R[i] = R[R[i]];
            }
            AnsR[i] = (R[i] == -1? i: AnsL[R[i]]);
            rep(j, vL.size()) AnsL[vL[j]] = AnsR[i];

            // Lado izquierdo
            vector<int> vR;
            while(L[i] >= 0 and H[i] > H[L[i]]) {
                vR.push_back(L[i]);
                R[L[i]] = i, L[i] = L[L[i]];
            }
            AnsL[i] = (L[i] == -1? i: AnsR[L[i]]);
            rep(j, vR.size()) {
                AnsR[vR[j]] = AnsL[i];
            }
        }
    }




    return 0;
}