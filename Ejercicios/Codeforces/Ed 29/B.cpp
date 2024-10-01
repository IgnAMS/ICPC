#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<int,int> ii;
#define ff first
#define ss second

struct Edge
{
    int u, v, w;
    Edge(int u, int v, int w) : u(u), v(v), w(w) {}
    bool operator<(const Edge &e) const { return w < e.w; }
};


int main(){
    int n; cin>>n;
    vector<int> A(2 * n); rep(i, 2 * n) cin>>A[i];
    sort(A.begin(), A.end());
    int ans = 1e8;
    rep(i, 2 * n) repx(j, i + 1, 2 * n){
        int aux = 0;
        vector<int> B;
        rep(k, 2*n) if(k != j and k != i) B.push_back(A[k]);
        //rep(i,2*n-2) cout<<B[i]<<' '; cout<<'\n';
        rep(k, n-1) aux += abs(B[2*k] - B[2*k+1]);
        ans = min(ans, aux);
    }
    cout<<ans<<'\n';
    





    return 0;
}