#pragma GCC optimize("Ofast")
#include<string.h>
#include<vector>
#include<map>
#include<deque>
#include<queue>
#include<iostream>
#include<algorithm>
#include<numeric>
#include <unordered_map>
#include <cmath>
#include<set>
#include<array>
using namespace std;
// g++ -std=c++17 A.cpp -o a && ./a <input.txt> output.txt   
// ulimit -s 1000000
// g++ -std=c++17 -O2 B.cpp && time ./a.out <input.txt> output.txt

#define ll long long
#define rep(i, n) for(int i = 0; i < (int)n; ++i)
#define repx(i, a, b) for(int i = (int)a; i < (int)b; ++i)
typedef pair<ll, ll> pll; 

const int mxN = 2e5+5;
vector<ll> A, B;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin>>n;
    A.resize(n), B.resize(n);
    rep(i, n) cin>>A[i];
    rep(i, n) cin>>B[i];

    ll mx_suffix = 0;
    rep(i, n) {
        if(B[i] == mx_suffix + 1) mx_suffix++;
        else mx_suffix = 0;
    }
    cout<<mx_suffix<<'\n';

    set<ll> S;
    rep(i, n) S.insert(A[i]);

    rep(i, n * n + 1) {
        repx(j, i, B.size()) cout<<B[j]<<' '; cout<<'\n';

        if(mx_suffix == n) {
            cout<<i<<'\n';
            return 0;
        }
        if(S.count(mx_suffix + 1)) {
            S.erase(mx_suffix + 1);
            B.push_back(mx_suffix + 1);
            mx_suffix += 1;
        }
        else {
            mx_suffix = 0;
            B.push_back(0);
        }

        S.insert(B[i]);
    }




    
    return 0;
}