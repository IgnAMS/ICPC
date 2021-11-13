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



struct DSU
{
    vi p; DSU(int N) : p(N, -1) {}
    void reset(){ rep(i, p.size()) p[i] = -1; }
    int get(int x) { return p[x] < 0 ? x : p[x] = get(p[x]); } 
    bool sameSet(int a, int b) { return get(a) == get(b); }
    int size(int x) { return -p[get(x)]; }
    void unite(int x, int y)
    {
        if ((x = get(x)) == (y = get(y))) return;
        if (p[x] > p[y]) swap(x,y);
        p[x] += p[y], p[y] = x;
    }
};

double EPS = 1e-10;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); 
    cout.setf(ios::fixed); cout.precision(3);

    ll n, w, h; 
    ll dr[] = {0, 0, 1, 2};
    ll dc[] = {1, 2, 3, 3};
    vi X, Y;

    while(cin>>n>>w>>h and n != -1){
        X.resize(n); Y.resize(n);
        rep(i, n) cin>>X[i]>>Y[i];
        double l = 0, r = min(w, h);

        DSU dsu(n + 4); // 0: left, 1: right, 2: down, 3: up
        rep(_, 38){
            dsu.reset();
            double mid = (l + r) * 0.5;
            bool oc = 0;
            // left, right, down, up
            rep(i, n){
                if(X[i] <= mid) dsu.unite(i+4, 0);
                if(X[i] + mid>= w) dsu.unite(i+4, 1);
                if(Y[i] <= mid) dsu.unite(i+4, 2);
                if(Y[i] + mid >= h) dsu.unite(i+4, 3);
            }

            rep(i, n) rep(j, i) {
                ll dx = (X[i] - X[j]), dy = (Y[i] - Y[j]);
                if(sqrt(dx * dx + dy * dy) * 0.5 <= mid) dsu.unite(i+4, j+4);
            }
            
            if(dsu.sameSet(0, 1) or dsu.sameSet(0, 2) or dsu.sameSet(1, 3) or dsu.sameSet(2, 3))
                r = mid;
            else l = mid;
        }
        cout<<(l + r)/2.0<<'\n';
    }





    return 0;
}