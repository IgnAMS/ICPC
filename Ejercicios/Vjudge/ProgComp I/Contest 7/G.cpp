#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define repx(i,a,b) for(int i=a;i<b;i++)
typedef long long ll;


int n; 
ll T[1005], A[1005], W[1005];
ll DP[1005][25][85]; // indice, t, a

ll dp(int ind, int t, int a){
    t = max(t, 0), a = max(a, 0);
    if(t <= 0 && a <= 0) return 0; // es factible
    if(ind == n) return 800 * 1000; // devuelvo inf si es que no me quedan por sumar
    if(DP[ind][t][a] != -1) return DP[ind][t][a];

    // minimo entre tomarlo y no tomarlo
    return DP[ind][t][a] = min(W[ind] + dp(ind+1, t-T[ind], a-A[ind]), dp(ind+1, t, a));
}




int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int c; cin>>c;
    while(c--){
        memset(DP, -1, sizeof DP);
        int t, a;
        cin>>t>>a>>n;
        rep(i,n) cin>>T[i]>>A[i]>>W[i];
        cout<<dp(0, t, a)<<"\n";
    }




    return 0;
}