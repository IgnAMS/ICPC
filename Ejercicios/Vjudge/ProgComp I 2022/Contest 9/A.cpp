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

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, k; cin>>n>>k;
    if(k % 2 == 0 or k > 2 * n - 1) {
        cout<<"-1\n";
        return 0;
    }
    vi A(n); rep(i, n) A[i] = i + 1;
    vector<ii> S = {{0, n - 1}};
    rep(_, k / 2) {
        auto [a, b] = S.back(); S.pop_back();
        // cerr<<a<<' '<<b<<'\n';
        // cout<<"swapeo "<<(b + a - 1) / 2<<' '<<(b + a) / 2<<'\n';
        if(a + 1 == b) {
            swap(A[a], A[b]);
            continue;
        }
        swap(A[(b + a - 1) / 2], A[(b + a + 1) / 2]);

        if(a != (b + a - 1) / 2) S.push_back({a, (b + a - 1) / 2});
        if(b != (b + a + 1) / 2) S.push_back({(b + a + 1) / 2, b});
    }
    rep(i, n) cout<<A[i]<<' '; cout<<'\n';




    return 0;
}