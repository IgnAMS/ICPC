#pragma GCC optimize("Ofast")
#include<string.h>
#include<vector>
#include<map>
#include<deque>
#include<queue>
#include<iostream>
#include<algorithm>
#include<numeric>
#include<unordered_map>
#include<cmath>
#include<set>
#include<array>
using namespace std;
// g++ -std=c++17 A.cpp -o a && ./a <input.txt> output.txt   
// ulimit -s 1000000
// g++ -std=c++17 -O2 D.cpp && time ./a.out <input.txt> output.txt

#define ll long long
#define rep(i, n) for(int i = 0; i < (int)n; ++i)
#define repx(i, a, b) for(int i = (int)a; i < (int)b; ++i)
typedef pair<ll, ll> pll; 
typedef vector<int> vi;

const int mxN = 501;
int n, m;
int A[mxN], B[mxN];



int main() {
    cin>>n;
    rep(i, n) cin>>A[i];
    cin>>m;
    rep(i, m) cin>>B[i];

    map<int, vector<int>> mpB;
    rep(i, m) {
        if(!mpB.count(B[i])) mpB[B[i]] = {};
        mpB[B[i]].push_back(i);
    }

    vector<pair<int, int>> Ans(n + 2, {800, -1});
    Ans[0] = {0, -1};
    rep(i, n) {
        if(!mpB.count(A[i])) continue;
        auto it = lower_bound(Ans.begin(), Ans.end(), make_pair(A[i]+1, -1));
        auto index = it - Ans.begin();
        auto [ans, prev_b] = *it;
        
        cout<<'\n';
        cout<<A[i]<<'\n';
        for(auto [a, b]: Ans) cout<<a<<", "<<b<<'\n';
        cout<<'\n';

        auto indb = lower_bound(mpB[A[i]].begin(), mpB[A[i]].end(), prev_b);
        if(indb == mpB[A[i]].end()) continue;

        cout<<A[i]<<' '<<i<<' '<<*indb<<' '<<index+1<<'\n';
        Ans[index] = {A[i], *indb};
    }



}