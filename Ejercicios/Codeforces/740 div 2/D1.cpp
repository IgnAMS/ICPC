#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<int,int> ii;
typedef double db;
#define ff first
#define ss second



int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll n, mod; cin>>n>>mod;
    ll A[n+1]; memset(A, 0, sizeof A);
    vector<ll> D(n+1, 0);
    ll acc = 0, suma = 0;
    A[1] = 1;
    repx(i, 1, n+1){
        acc = (acc + D[i]) % mod;
        A[i] = (A[i] + acc + suma) % mod;
        suma = (suma + A[i]) % mod;
        repx(k, 2, n+1){
            if(i * k > n) break;
            D[i * k] = (D[i * k] + A[i] - A[i-1] + mod) % mod;
        }
    }
    // rep(i, n+1) cout<<D[i]<<' '; cout<<'\n'; 
    // rep(i, n+1) cout<<A[i]<<' '; cout<<'\n';
    cout<<A[n]<<'\n';





    return 0;
}