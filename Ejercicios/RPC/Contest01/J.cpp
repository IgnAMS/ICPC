#include <bits/stdc++.h>
using namespace std;
 
#define ll long long 
#define ar array
#define rep(i, n) for(int i = 0; i<(int)n; ++i)
#define mat vector<vector<ll>>

const int mxN = 305, M = 1e9+7;
const ll M2 = (ll)M*M;

ll k, n;


mat cn(int n, int m){
    return vector<vector<ll>>(n, vector<ll>(m));
}
 
mat mult(mat &a, mat &b){
    mat c = cn(a.size(), b[0].size());
    for(int i=0; i<a.size(); ++i){
        for(int k = 0; k<b.size(); ++k){
            for(int j = 0; j<b[0].size(); ++j){
                c[i][j]+=a[i][k]*b[k][j];
                if(c[i][j]>=M2){
                    c[i][j] -= M2;
                }
            }
        }
    }
    for(int i = 0; i<a.size(); ++i){
        for(int j=0; j<b[0].size(); ++j){
            c[i][j] %= M;
        }
    }
    return c;
}
 

int main(){
#ifdef _DEBUG
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    std::ios_base::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);
    
    cin >> k >> n;
    if(n == 1){
        cout << k << "\n";
        return 0;
    }
    mat r(k, vector<ll>(k, 0)), b(k, vector<ll>(k, 0));
    for(int i = 1; i<=k; ++i){
        for(int j = 1; j<=k; ++j){
            if(__gcd(i, j) == 1){
                r[i-1][j-1] = 1;
            }
        }
    }
    b = r;
   
    n-=2;
    while(n){
        if(n&1){
            r = mult(r, b);
        }
        b = mult(b, b);
        n /= 2;
    }
    ll ans = 0;
    for(int i = 1; i<=k; ++i){
        for(int j = 1; j<=k; ++j){
            ans += r[i-1][j-1];
            ans %= M;
        }
    }
    cout << ans << '\n';
}