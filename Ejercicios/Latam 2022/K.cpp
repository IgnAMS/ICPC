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

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int k; cin>>k;
    ll n;
    if(k == 1) {
        cout<<"0\n";
        return 0;
    }

    rep(i, 13) if((1<<i) >= k) {
        n = i;
        break;
    }
    set<pll> K1[n / 2], K2[(n + 1) / 2];

    set<ll> Types;

    ll Val[101][101] = {{0}};

    repx(i, 1, 101) {
        rep(j, n / 2) {
            K1[j].insert({1, i}); 
            K1[j].insert({i, 1});
            Val[1][i] |= (1<<j);
            Val[i][1] |= (1<<j);
        }
        rep(j, (n + 1) / 2) {
            K2[j].insert({1, i}); 
            K2[j].insert({i, 1});
            Val[1][i] |= (1<<(n/2 + j));
            Val[i][1] |= (1<<(n/2 + j));
        }
        Types.insert(Val[1][i]);
    }
    Types.insert(0);

    repx(i, 2, 100) {
        rep(j, n / 2) if(i & (1<<j)) {
            repx(a, 1, 100) {
                if(!Types.count(Val[i][a] | (1<<j)) and Types.size() < k) {
                    K1[j].insert({i, a});
                    Types.insert(Val[i][a] | (1<<j));
                    Val[i][a] |= (1<<j);
                    
                    if(Types.size() == k) break;
                }
                else if(Types.count(Val[i][a] | (1<<j))) {
                    K1[j].insert({i, a});
                    Val[i][a] |= (1<<j);
                }
            }
            if(Types.size() == k) break;
        }
        if(Types.size() == k) break;
    }
    rep(j, (n + 1) / 2) {
        if(Types.size() == k) break;
        repx(i, 2, 100) if(i & (1<<j)) {
            repx(a, 1, 100) {
                if(!Types.count(Val[a][i] | (1<<(n/2 + j))) and Types.size() < k) {
                    K2[j].insert({a, i});
                    Types.insert(Val[a][i] | (1<<(n/2 + j)));
                    Val[a][i] |= (1<<(n/2 + j));
                    if(Types.size() == k) break;
                }
                else if(Types.count(Val[a][i] | (1<<(n/2 + j)))) {
                    K2[j].insert({a, i});
                    Val[a][i] |= (1<<(n/2 + j));
                }
            }
            if(Types.size() == k) break;
        }
        if(Types.size() == k) break;
    }


//     set<ll> X;
//     repx(i, 1, 100) {
//         repx(j, 1, 100) cout<<Val[i][j]<<'\t'; cout<<'\n';
//     }
//     rep(i, 100) rep(j, 100) X.insert(Val[i][j]);
//     cout<<X.size()<<'\n';
//     for(auto u: X) cout<<u<<' '; cout<<'\n';
//     for(auto u: Types) cout<<u<<' '; cout<<'\n';

    cout<<n<<'\n';
    rep(i, n / 2) {
        cout<<K1[i].size()<<' ';
        for(auto [a, b]: K1[i]) cout<<a<<' '<<b<<' ';
        cout<<'\n';
    }
    rep(i, (n + 1) / 2) {
        cout<<K2[i].size()<<' ';
        for(auto [a, b]: K2[i]) cout<<a<<' '<<b<<' ';
        cout<<'\n';
    }



    return 0;
}