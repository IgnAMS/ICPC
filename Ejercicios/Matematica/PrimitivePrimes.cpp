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


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m, p; cin>>n>>m>>p;
    int A[n], B[m]; 
    rep(i, n) cin>>A[i]; 
    rep(i, m) cin>>B[i];
    ll mini = -1, minj = -1;
    rep(i, n) if(__gcd(A[i], p) == 1) { mini = i; break; }
    rep(j, m) if(__gcd(B[j], p) == 1) { minj = j; break; }
    // cout<<mini<<' '<<minj<<'\n';
    cout<<mini + minj<<'\n';

    return 0;
}