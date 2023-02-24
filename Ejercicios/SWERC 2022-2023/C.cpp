#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
#define ff first
#define ss second
#define repx(i, a, b) for(int i = a; i < b; i++)
#define rep(i, n) repx(i, 0, n)


// g++ -std=c++11 C.cpp -o a && a <input.txt> output.txt
// ulimit -s 1000000
// g++ -O2 C.cpp && time ./a.out <input.txt> output.txt

void Bob(int indice, int n, int m) {
    cout<<"Bernardo\n";
    set<int> S, Tot;
    for(int i = 1; i <= m; i++) Tot.insert(i);
    for(int i = indice; i <= m; i += indice) S.insert(i);
    // for(auto u: S) cerr<<u<<' '; cerr<<endl;
    for(int i = 0; i < n; i++) {
        int y, l; cin>>y>>l;
        int low;
        if(S.lower_bound(l) == S.end()) low = *Tot.lower_bound(l);
        else low = *S.lower_bound(l);
        if(low > l + y - 1) low = *Tot.lower_bound(l);
        cout<<low<<endl;
    }
}

void Alice(int n, int m, vector<int> &X) {
    cout<<"Alessia\n";
    set<vector<int>> S; // {size, l, r}
    S.insert({-m, 1, m});
    reverse(X.begin(), X.end());
    for(int i = 0; i < n; i++) {
        auto it = S.begin(); 
        auto u = *it; S.erase(it);
        int l = u[1], r = u[2];
        // cout<<u[0]<<' '<<u[1]<<' '<<u[2]<<endl;
        cout<<X[i]<<' '<<l<<endl;
        int x; cin>>x;
        if(x == l) S.insert({-(r - x), x + 1, r});
        else if(x == r) S.insert({-(x - l), l, x - 1});
        else {
            S.insert({-(r - x), x + 1, r});
            S.insert({-(x - l), l, x - 1});
        }
    }
}


int main() {
    int n, m; cin>>n>>m;
    vector<int> X(n);
    rep(i, n) cin>>X[i];
    sort(X.begin(), X.end());
    int BWins = 0;
    for(int i = 0; i < n; i++) if(n - i > m / X[i]) BWins = X[i]; 
    if(BWins) Bob(BWins, n, m);
    else Alice(n, m, X);

    return 0;
}
