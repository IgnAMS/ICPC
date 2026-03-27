#pragma GCC optimize("Ofast")
#include<string.h>
#include<vector>
#include<map>
#include<deque>
#include<queue>
#include<iostream>
#include <algorithm>
#include<set>
#include<array>
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
// g++ -std=c++17 A.cpp -o a && ./a <input.txt> output.txt   
// ulimit -s 1000000
// g++ -O2 E.cpp && time ./a.out <input.txt> output.txt

const int mxN = 2005;
ll n, m, d, x;
pll P[mxN];
vl L[mxN], LAcc[mxN], R[mxN], RAcc[mxN];


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m>>d>>x;
    P[0] = {-d, -d};
    P[n+1] = {m+d+1, m+d+1};
    repx(i, 1, n+1) {
        cin>>P[i].ff>>P[i].ss;
    }
    

    ll ans = 1e17;
    repx(i, 1, n+2) {
        // pongo a x entre i-1 e i
        ll dist = P[i].ff - P[i-1].ss - 2 * d - 1;
        ll cost = 0;
        ll espacio_faltante = max(x - dist, 0LL);
        
        int left = 1, right = 1;
        int cont = 0;
        while(cont++ < 2005 and espacio_faltante > 0 and left <= i and right <= n+2-i) {
            // cout<<"cont: "<<cont<<", left: "<<left<<", i: "<<i<<", right: "<<right<<", n+2-i: "<<n+2-i<<", espacio faltante: "<<espacio_faltante<<", costo: "<<cost<<"\n";
            if(left == i and right == n+2-i) break;
            if(left == i or (right < n+2-i and right <= left)) {
                // right < n+2-i -> right <= n+1-i -> right+i <= n+1
                ll right_dist = min(P[i+right].ff - P[i+right-1].ss - d - 1, espacio_faltante);
                espacio_faltante -= right_dist;
                cost += 1LL * right * right_dist;
                right++;
            }
            else if(right == n+2-i or (left < i and left <= right)) {
                // left < i -> left <= i -1 -> i - left - 1 >= 0
                ll left_dist = min(P[i-left].ff - P[i-left-1].ss - d - 1, espacio_faltante);
                espacio_faltante -= left_dist;
                cost += 1LL * left * left_dist;
                left++;
            }
        }

        if(espacio_faltante == 0) ans = min(ans, cost);
    }
    cout<<(ans == 1e17? -1: ans)<<"\n";
    



    return 0;
}