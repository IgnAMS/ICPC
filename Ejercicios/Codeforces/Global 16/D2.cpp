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


struct FT
{
    vi t;
    FT(int N) { t.resize(N + 1, 0); }
    int query(int i){
        int ans = 0;
        for (; i; i -= i & (-i)) { 
            ans += t[i]; 
            // cout<<"agrego "<<t[i]<<'\n'; 
        }
        return ans;
    }
    int query(int i, int j) { return query(j) - query(i - 1); }
    void update(int i, int v){
        for (; i < t.size(); i += i & (-i)) { 
            t[i] += v;
            // cout<<"actualizo en "<<v<<" a "<<i<<"\n";
        }
    }
    void update(int i, int j, int v) { update(i, v); update(j + 1, -v); }
};

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--){
        int n, m; cin>>n>>m;
        vector<ii> A; rep(i, m * n) { int h; cin>>h; A.push_back(ii(h, i + 1)); }
        sort(A.begin(), A.end());
        FT ft(m * n); // nota mental, indexa desde 1
        vector<int> aux(n * m + 3, -1);
        int cont = 0;
        rep(i, n * m){
            ii u = A[i];
            int next_row = (cont / m + 1) * m;
            int ind = min(lower_bound(A.begin(), A.end(), ii(u.ff+1, 0)) - A.begin(), next_row); // indice del primer mayor
            for(int j = ind - 1; j >= i; j--){
                aux[A[j].ss] = ++cont;
            }
            i = ind - 1;
            if(cont > n * m) break;
        }
        // repx(i, 1, n * m + 1) cout<<aux[i]<<' '; cout<<'\n';
        ll ans = 0;
        repx(i, 1,  n * m + 1){
            ans += ft.query(aux[i]);
            int r = (aux[i] - 1) / m, c = aux[i] - r * m;
            ft.update(aux[i], (r + 1) * m, 1);
        }
        cout<<ans<<'\n';
        // return 0;
        
    }


    return 0;
}