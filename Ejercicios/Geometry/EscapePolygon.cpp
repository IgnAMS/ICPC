#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define repx(i, a, b) for(int i=a; i<b; i++)
typedef long long ll;




int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll n; cin>>n;
    vector<ll> X(n), Y(n); rep(i,n) cin>>X[i]>>Y[i];
    ll j=1, ans=0;
    rep(i, n){
        ll dx = X[i] - X[(i+1)%n], dy = Y[i] - Y[(i+1)%n];
        ll dxj = X[(j)%n] - X[(j+1)%n], dyj = Y[(j)%n] - Y[(j+1)%n];
        while(dx * dyj - dy * dxj >= 0){
            j++; 
            dxj = X[(j)%n] - X[(j+1)%n], dyj = Y[(j)%n] - Y[(j+1)%n];
        }
        j%=n;
        ans += ((j - i - 1 + n)%n) * ((j - i - 2 + n)%n) / 2;
        // cout<<i<<" "<<j<<" "<<(j - i - 1 + n)%n<<" "<<(j - i - 2 + n)%n<<" "<<((j - i - 1 + n)%n) * ((j - i - 2 + n)%n)<<"\n";
        // cout<<"Para el vertice "<<i<<" encontré "<< ((j - i - 1 + n)%n) * ((j - i - 2 + n)%n) / 2 <<" escapados\n";
    }
    cout<< n * (n-1) * (n-2) / 6 - ans << "\n";






    return 0;
}