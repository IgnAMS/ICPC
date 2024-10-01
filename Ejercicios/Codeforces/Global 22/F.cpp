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
// g++ -O2 D.cpp && time ./a.out <input.txt> output.txt

struct DSU
{
    vi p, D;
    DSU(int N, vi& A) : p(N, -1) {
        D.resize(N);
        rep(i, N) D[i] = A[i];
    }
    int get(int x) { return p[x] < 0 ? x : p[x] = get(p[x]); } 
    bool sameSet(int a, int b) { return get(a) == get(b); }
    int size(int x) { return -p[get(x)]; }
    void unite(int x, int y)
    {
        if ((x = get(x)) == (y = get(y))) return;
        if (p[x] > p[y]) swap(x,y);
        p[x] += p[y], p[y] = x;
        D[x] += D[y]; 
    }
};


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--) {
        int n; cin>>n;
        vi D(n); rep(i, n) cin>>D[i];
        DSU dsu(n, D);
        vi V(n, 0);
        vi C(n, 0);
        int q = 0;
        rep(i, n) if(V[i] == 0) {
            V[i] = 1;
            rep(_, D[i]) {
                cout<<"? "<<i + 1<<endl;
                C[i]++;
                q++;
                int v; cin>>v; v -= 1;
                if(V[v] == 1) {
                    dsu.unite(i, v);
                    break;
                }
                V[v] = 1;
                dsu.unite(i, v);
            }
        }
        rep(i, n) {
            while(q < n) {
                // cerr<<i<<' '<<q<<'\n';
                ll nc = -dsu.p[dsu.get(i)];
                ll sc = dsu.D[dsu.get(i)];
                if(nc * nc < sc and C[i] < D[i]) {
                    cout<<"? "<<i + 1<<endl;
                    int v; cin>>v; v -= 1;
                    dsu.unite(i, v);
                    q++;
                    C[i]++;
                }
                else break;
            }
        }
        // rep(i, n) cout<<dsu.get(i)<<' '; cout<<'\n';
        cout<<"! ";
        rep(i, n) cout<<dsu.get(i) + 1<<' '; cout<<endl;
    }


    return 0;
}