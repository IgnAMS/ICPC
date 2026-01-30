#pragma GCC optimize("Ofast")
#include<iostream>
#include<vector>
#include<string.h>
#include<set>
#include<map>
#include<algorithm>
#include<array>
#include<unordered_map>
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
// g++ -std=c++17 MissingCoinSum.cpp -o a && ./a <input.txt> output.txt
// ulimit -s 1000000
// g++ -O2 RoomAllocation.cpp && time ./a.out <input.txt> output.txt


const int INF = 1e9+1;
const ll MOD = 1e9+7;
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    ll n; cin>>n;
    vector<array<ll, 3>> X(n);
    rep(i, n) {
        cin>>X[i][0]>>X[i][1];
        X[i][2] = i;
    }
    sort(X.begin(), X.end());
    ll Ans[n];
    multiset<pll> S = {{-1, 0}};
    for(auto [a, b, ind]: X) {
        // debo si o si crear un nuevo set
        if(S.begin()->ff >= a) {
            Ans[ind] = S.size();
            S.insert({b, Ans[ind]});
            continue;
        }

        // Saco el primer cuarto qeu se que es menor que yo
        int room = S.begin()->ss;
        Ans[ind] = room;
        S.erase(S.begin());
        S.insert({b, room});
    }
    cout<<S.size()<<"\n";
    rep(i, n) cout<<Ans[i] + 1<<" "; cout<<"\n";

    return 0;
}