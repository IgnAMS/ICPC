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

vector<vl> Ans = { 
{1 }, 
{2 }, 
{1, 2 }, 
{4 }, 
{2, 4 }, 
{8 }, 
{4, 8 }, 
{16 }, 
{8, 16 }, 
{32 }, 
{16, 32 }, 
{64 }, 
{32, 64 }, 
{128 }, 
{64, 128 }, 
{256 }, 
{128, 256 }, 
{512 }, 
{256, 512 }, 
{1024 }, 
{512, 1024 }, 
{2048 }, 
{1024, 2048 }, 
{4096, }, 
{2048, 4096 }, 
{8192, }, 
{4096, 8192 }, 
{16384 }, 
{8192, 16384 }, 
{32768, }, 
{16384, 32768 }, 
{65536, }, 
{32768, 65536 }, 
{131072 }, 
{65536, 131072 }, 
{262144 }, 
{131072, 262144 }, 
{524288 }, 
{262144, 524288 }, 
{1048576 }, 
{524288, 1048576 }, 
{2097152}, 
{1048576, 2097152 }, 
{4194304}, 
{2097152, 4194304 }, 
{8388608}, 
{4194304, 8388608 }, 
{16777216}, 
{8388608, 16777216 }, 
{33554432},
{16777216, 33554432},  
{67108864 }, 
{33554432, 67108864},
{134217728 },
};

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
//     set<ll> S2;
//     S2.insert(0);
//     rep(i, 30) S2.insert((1<<i));
// 
//     rep(mask, (1<<30)) {
//         vl X; 
//         rep(i, 30) if(mask & (1<<i)) X.pb((1<<i));
//         bool pos = 1;
//         for(auto u: X) {
//             for(auto v: X) if(!S2.count(abs(u - v))) {
//                 pos = 0; 
//                 break;
//             }
//             if(!pos) break;
//         }
//         if(pos) {
//             for(auto u: X) cout<<u<<' '; cout<<endl;
//         }
//     }
    ll n; cin>>n;
    vl A(n); rep(i, n) cin>>A[i];
    multiset<ll> S;
    rep(i, n) S.insert(A[i]);
    vl X = {A[0]};
    rep(i, n) {
        rep(j, 32) {
            ll x = A[i] + (1LL<<j);
            ll y = A[i] + (1LL<<(j + 1));
            // cout<<A[i]<<' '<<x<<' '<<y<<'\n';
            if(S.count(x) and X.size() <= 1) X = {A[i], x};
            if(S.count(x) and S.count(y)  and X.size() <= 2) X = {A[i], x, y};
        }
    }
    cout<<X.size()<<'\n';
    for(auto u: X) cout<<u<<' '; cout<<'\n';

    return 0;
}