#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<ll, ll> ii;
typedef double db;
typedef vector<ll> vi;
#define ff first
#define ss second
// g++ -std=c++11 A.cpp -o a && a <input.txt> output.txt
//  g++ -O2 D.cpp && time ./a.out < input.txt > output.txt

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    vector<vi> E;
    rep(i, n) {
        char c;
        int a, b; 
        cin>>c>>a>>b; b--;
        E.push_back({0, a, b, c == 'D'});
        E.push_back({1, a, b, c == 'D'});
    }
    sort(E.begin(), E.end());
    // 1: Danielista
    multiset<ll> mxD, mxJ;
    ll ans = 0;
    for(auto& e: E) {
        if(e[0] == 0) {
            if(e[3]) mxD.insert(e[2]);
            else mxJ.insert(e[2]);
            if(!mxD.empty() and !mxJ.empty()) 
                ans = max(ans, min(*mxD.rbegin(), *mxJ.rbegin()) - e[1] + 1);
        }
        else {
            if(e[3]) mxD.erase(mxD.find(e[2]));
            else mxJ.erase(mxJ.find(e[2]));
        } 
    }
    cout<<ans<<'\n';

    return 0;
}