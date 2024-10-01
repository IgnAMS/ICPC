#pragma GCC optimize("Ofast")
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

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll n, k, x; cin>>n>>k>>x;
    vi A(n); rep(i, n) cin>>A[i];
    sort(A.begin(), A.end());
    multiset<ll> S;
    rep(i, n - 1) {
        if(A[i + 1] - A[i] > x) S.insert(A[i + 1] - A[i]);
    }
    ll ans = S.size() + 1;
    for(auto u: S) {
        // cout<<"la diferencia es de "<<u<<" necesito "<<(u - 1) / x<<" para reponer y tengo "<<k<<'\n';
        if((u - 1) / x <= k)  k -= (u - 1) / x, ans--;
    }
    cout<<ans<<'\n';



    return 0;
}