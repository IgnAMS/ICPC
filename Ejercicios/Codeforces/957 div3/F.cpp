#pragma GCC optimize("Ofast")
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

vl Div[100001];
vector<vl> Ans;
vector<vl> F;
vl X;
void get_divs(ll i, ll acc, ll x) {
    if(i == Div[x].size()) {
        if(acc == x) Ans.pb(X), F.pb(vl(X.size(), 0));
        return;
    }
    if(x % (acc * Div[x][i]) == 0) {
        X.pb(Div[x][i]);
        get_divs(i, acc * Div[x][i], x);
        X.pop_back();
    }
    get_divs(i + 1, acc, x);
}

void solve() {
    ll n, x; cin>>n>>x;
    Ans.clear();
    F.clear();
    get_divs(0, 1, x);
    // cout<<"get divs en "<<x<<'\n';
    // for(auto vec: Ans) {
    //     for(auto u: vec) cout<<u<<' '; cout<<'\n';
    // }
    ll A[n]; 
    ll ans = 0;
    rep(i, n) {
        cin>>A[i];
        // cout<<"entra "<<A[i]<<'\n';
        bool oc = 0;
        rep(j, Ans.size()) {
            auto& vec = Ans[j];
            int k = lower_bound(vec.begin(), vec.end(), A[i]) - vec.begin();
            while(k < vec.size() and vec[k] == A[i] and F[j][k] == 1) k++;
            if(k < vec.size() and vec[k] == A[i]) {
                // cout<<"rellene el "<<j<<" vector con un "<<A[i]<<'\n';
                F[j][k] = 1;
            }
            bool exists = 1;
            for(k = 0; k < vec.size(); k++) {
                if(F[j][k] == 0) {
                    exists = 0;
                    break;
                }
            }
            if(exists) oc = 1;
            if(oc) break;
        }
        if(oc == 1) {
            ans++;
            rep(j, Ans.size()) {
                F[j].assign(Ans[j].size(), 0);
            }
            rep(j, Ans.size()) {
                auto& vec = Ans[j];
                int k = lower_bound(vec.begin(), vec.end(), A[i]) - vec.begin();

                while(k < vec.size() and vec[k] == A[i] and F[j][k] == 1) k++;
                if(k < vec.size() and vec[k] == A[i]) {
                    F[j][k] = 1;
                }
            }
        }
    }
    cout<<ans + 1<<'\n';
}


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    for(int i = 2; i <= 100000; i++) {
        for(int j = i; j <= 100000; j += i) {
            Div[j].pb(i);
        }
    }
    int t; cin>>t;
    while(t--) {
        solve();
    }

    // get_divs(0, 1, 100000);
    // ll acc = 0;
    // for(auto vec: Ans) {
    //     acc += vec.size();
    //     for(auto u: vec) cout<<u<<' '; cout<<'\n';
    // }
    // cout<<acc<<'\n';

    



    return 0;
}