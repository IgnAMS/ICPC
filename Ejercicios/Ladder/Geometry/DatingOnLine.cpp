#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define repx(i, a, b) for(int i=a;i<b;i++)
typedef long long ll;

const double PI = acos(-1.0L);
const double EPS = 1e-12;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    vector<ll> A(n); rep(i,n) cin>>A[i];
    sort(A.begin(), A.end());
    ll ans = A[0] * (A[1] + A[2]);
    ll a=A[1], b=A[2]; 
    repx(i, 3, n){
        ans += a*A[i];
        a=b, b=A[i]; // actualizo
    }
    ans += A[n-1] * A[n-2];
    cout<<setprecision(3)<<fixed<< sin(2*PI/n)*ans/2.0+ EPS <<"\n";
    
    return 0;
}
