#include <bits/stdc++.h>

using namespace std;
 
#define ll long long 
#define ar array
#define rep(i, n) for(int i = 0; i<(int)n; ++i)
#define db long double

const int mxN = 2e5+5, M = 1e9+7, INF = 2;
const double EPS = 1e-9;
int n, k;
double p;

int gauss (vector < vector<double> > a, vector<double> & ans){
    int l1 = a.size();
    int l2 = a[0].size(); 
    //pivotea la matriz
    for(int i = 0; i<l2; ++i){
        for(int j = i+1; j<l1 && abs(a[i][i]) < EPS; ++j){
            if(abs(a[j][i]) > EPS) swap(a[i], a[j]), swap(ans[i], ans[j]);
        }
        if(abs(a[i][i]) < EPS) assert(0), exit(0);
        for(int j = i+1; j<l1; ++j){
            long double rate = a[j][i] / a[i][i];
            ans[j] -= rate*ans[i];
            for(int k = i; k<l2; ++k) a[j][k] -= rate*a[i][k];
        }
    }

    // recoge las variables, las calcula y las lleva hacia arriba
    // consigue el valor de todas las ecuaciones
    for(int i = l2-1; i>=0; --i){
        ans[i] /= a[i][i];
        a[i][i] = 1;
        for(int j = i-1; j>=0; --j){
            ans[j] -= a[j][i] * ans[i];
        }
    }
}

void solve(){
    cin >> n >> k >> p;
    vector<vector<double>> a(1<<n, vector<double>(1<<n, 0));
    vector<double> ans(1<<n);
    rep(i, 1<<n){
        a[i][i] = 1;
        if(__builtin_popcount(i) >= k){
            ans[i] = 0;
            continue;
        }
        ans[i] = 1;
        int le = (i<<1) + 1, ri = (i<<1);
        if(le >= (1<<n)) le -= (1<<n);
        if(ri >= (1<<n)) ri -= (1<<n);
        a[i][le] += -p;
        a[i][ri] += -(1.0-p);
    }
    
    gauss(a, ans);

    cout << ans[0] << "\n";
}
 
signed main(){
#ifdef _DEBUG
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", " w", stdout);
#endif
    std::ios_base::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);
 
    cout << fixed << setprecision(9);
    int t = 1;
    while(t--){
        solve();
    }
}