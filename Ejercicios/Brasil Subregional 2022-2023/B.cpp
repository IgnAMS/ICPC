#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define rep(i, n) for(int i = 0; i<(int)n; ++i)
typedef vector<ll> vl;
typedef pair<ll, ll> pll;
#define ff first
#define ss second

ll const mxN = 1e5 + 5, M = 1e9+7;
ll l1, l2, l3, r1, r2, r3;
ll dp[35][8][8];

ll binpow(ll a, ll b){
    ll res = 1;
    while(b){
        if(b&1){
            res = res*a%M;
        }
        a = a*a%M;
        b >>= 1;
    }
    return res;
}

ll f(ll a, ll b, ll c, int pos, int maskxor, int maskf, int num1=0, int num2=0, int num3=0){
    if(pos == 33){
        if(maskxor == 0 || maskxor == 3 || maskxor == 5 || maskxor == 6){
            // cout << num1 << " " << num2 << " " << num3 << "\n";
            return 1;
        }
        return 0;
    }
    if(dp[pos][maskxor][maskf] != -1) return dp[pos][maskxor][maskf];
    
    int l1, l2, l3;
    if(maskf & (1<<2)){
        l1 = 0;
    }else{
        l1 = bool(a&(1<<pos));
    }
    if(maskf & (1<<1)){
        l2 = 0;
    }else{
        l2 = bool(b&(1<<pos));
    }
    if(maskf & (1<<0)){
        l3 = 0;
    }else{
        l3 = bool(c&(1<<pos));
    }
    ll res = 0;
    
    rep(limit1, l1+1){
        rep(limit2, l2+1){
            rep(limit3, l3+1){
                int maskxor2 = 4*limit1+2*limit2+limit3; 
                if(maskxor2 != 0 && maskxor2 != 3 && maskxor2 != 5 && maskxor2 != 6) continue;
                int maskf2 = maskf;
                maskf2 |= (limit1<l1?(1<<2):0);
                maskf2 |= (limit2<l2?(1<<1):0);
                maskf2 |= (limit3<l3?(1<<0):0);
                res += f(a, b, c, pos+1, maskxor2, maskf2, num1|(limit1<<pos), num2|(limit2<<pos), num3|(limit3<<pos));
                res %= M;
            }
        }
    }

    return dp[pos][maskxor][maskf] = res;
}

ll solve(ll a, ll b, ll c){
    memset(dp, -1, sizeof(dp));
    rep(i, 35) rep(j, 8) rep(k, 8) dp[i][j][k] = -1;
    return f(a, b, c, 0, 0, 0);
}

int main(){
    cin >> l1 >> r1 >> l2 >> r2 >> l3 >> r3; 
    ll num = ((solve(r1, r2, r3)-solve(l1-1, l2-1, l3-1))%M+M)%M;
    ll aux = (solve(r1, r2, r3) - solve(l1-1, r2, r3) - solve(r1, l2-1, r3) - solve(r1, r2, l3-1) + solve(l1-1, l2-1, r3) + solve(l1-1, r2, l3-1) + solve(r1, l2-1, l3-1) + 10 * M) % M;
    aux = (aux - solve(l1-1, l2-1, l3-1) + M) % M;
    cout<<solve(r1, r2, r3)<<' '<<-solve(l1-1, r2, r3)<<" "<<-solve(r1, l2-1, r3)<<" "<<-solve(r1, r2, l3-1)<<" "<<solve(l1-1, l2-1, r3)<<" "<<solve(l1-1, r2, l3-1)<<" "<<solve(r1, l2-1, l3-1)<<' '<<-solve(l1-1,l2-1,l3-1)<<'\n';
    num = aux;
    // solve(r1, r2, r3), solve(l1 - 1, r2, r3), solve(r1, l2 - 1, r3), solve(r1, r2, l3 - 1) 
    ll dem = (((r1-l1+1)*(r2-l2+1)%M)*(r3-l3+1))%M;
    // cout << num << " " << dem << "\n";
    cout << num*binpow(dem, M-2)%M << "\n";
}