#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<int,int> ii;
typedef double db;
typedef vector<ll> vi;
#define ff first
#define ss second
// g++ -std=c++11 A.cpp -o a && a <input.txt> output.txt


struct DSU{
    vi p; DSU(int N) : p(N, -1) {}
    int get(int x) { return p[x] < 0 ? x : p[x] = get(p[x]); } 
    bool sameSet(int a, int b) { return get(a) == get(b); }
    int size(int x) { return -p[get(x)]; }
    void unite(int x, int y)
    {
        // cout<<"uno el "<<x<<" con el "<<y<<'\n';
        if ((x = get(x)) == (y = get(y))) return;
        if (p[x] > p[y]) swap(x,y);
        p[x] += p[y], p[y] = x;
    }
};

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    vector<vector<int>> C(n, vector<int>(3));
    rep(i, n) cin>>C[i][0]>>C[i][1]>>C[i][2];
    
    int ans = 0; 
    DSU dsu(n + 2);
    int l = n, r = n+1;
    rep(i, n){
        if(C[i][0] - C[i][2] < 0) dsu.unite(i, l);
        if(C[i][0] + C[i][2] > 200) dsu.unite(i, r);
        rep(j, i){
            int dx = abs(C[i][0] - C[j][0]), dy = abs(C[i][1] - C[j][1]);
            int R = C[i][2] + C[j][2];
            if(dx * dx + dy * dy <= R * R) dsu.unite(i, j);
        }
        ans = i;
        if(dsu.sameSet(l, r)) break;
    }
    cout<<ans<<'\n';





    return 0;
}