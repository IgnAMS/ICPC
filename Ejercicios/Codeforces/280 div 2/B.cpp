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
    ll n, l; cin>>n>>l;
    vector<double> A(n); rep(i, n) cin>>A[i];
    sort(A.begin(), A.end());
    double ans = 0;
    ans = max({ans, A[0], l - A.back()});
    rep(i, n-1){
        ans = max(ans, (A[i+1] - A[i]) / 2.0);
    }
    cout<<setprecision(10)<<fixed<<ans<<'\n';



    return 0;
}