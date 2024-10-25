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


const int mxN = 3e5;
vector<int> Divs[mxN];
vl Pos(mxN, 1);

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    // Practical Numbers: [1, 2, 4, 6, 8, 12, 16, 20, 24, 28, 30, 32]

    unordered_set<ll> S; 
    S.reserve(1e5);
    for(int i = 1; i < mxN; i++) {
        for(int j = i; j < mxN; j += i) {
            Divs[j].pb(i);
        }
    }

    vl Prim = {1};
    for(int i = 2; i < mxN; i += 2) {
        ll acc = 0;
        bool pos = Pos[i];
        if(pos) {
            for(int j = 0; j < Divs[i].size(); j++) {
                ll d = Divs[i][j];
                acc += d;
                if(j + 1 < Divs[i].size() and acc + 1 < Divs[i][j + 1]) {
                    pos = 0;
                    break;
                }
            }
        }

        if(pos) {
            // cout<<"inserto a "<<i<<'\n';
            Prim.pb(i);
            S.insert(i);
        }
        if(S.count(i)) {
            for(auto d: Divs[i]) if(i < mxN / d) {
                S.insert(i * d);
                Pos[i * d] = 0;
            }
        }
    }
    int n; cin>>n;
    cout<<Prim[n - 1]<<'\n';


    return 0;
}