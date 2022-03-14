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
//  g++ -O2 D.cpp && time ./a.out < input.txt > output.txt

struct FT
{
    vi t;
    FT(int N) { t.resize(N + 1, 0); }
    ll query(int i)
    {
        ll ans = 0;
        for (; i; i -= i & (-i)) ans += t[i];
        return ans;
    }
    ll query(int i, int j) { return query(j) - query(i - 1); }
    void update(int i, ll v)
    {
        ll s = query(i, i); // Sets
        for (; i < t.size(); i += i & (-i)) t[i] += v;
    }
    void update(int i, int j, ll v) { update(i, v); update(j + 1, -v); }
};


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll n, m, c; cin>>n>>m>>c;
    FT ft(n);
    ft.update(1, n, c);
    while(m--) {
        char x; cin>>x;
        if(x == 'S') {
            ll u, v, k; cin>>u>>v>>k;
            ft.update(u, v, k);
        }
        if(x == 'Q') {
            ll p; cin>>p;
            cout<<ft.query(p)<<'\n';
        }
    }




    return 0;
}