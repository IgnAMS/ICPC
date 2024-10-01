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
    ll n, r, avg; cin>>n>>r>>avg;
    vi A(n), B(n);
    rep(i, n) cin>>A[i]>>B[i];
    ll suma = 0; rep(i, n) suma += A[i];
    vector<ii> P(n);
    rep(i, n) P[i] = ii(B[i], A[i]);
    sort(P.begin(), P.end());
    int i = 0;
    ll cost = 0;
    // cout<<suma<<' '<<avg * n<<'\n';
    while(suma < avg * n){
        ll add = min(r - P[i].ss, avg * n - suma);
        cost += P[i].ff * add, suma += add;
        i++;
    }
    cout<<cost<<'\n';


    return 0;
}