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
    int t; cin>>t;
    while(t--){
        ll n, l; cin>>n>>l;
        vi X(l+1, 0);
        vi A(n); 
        rep(i, n) {
            cin>>A[i]; 
            rep(j, l+1) if(A[i] & (1<<j)) X[j]++; 
        }
        // rep(i, l+1) cout<<X[i]<<' '; cout<<'\n';
        ll ans = 0;
        rep(i, l+1) if(X[i] > n/2) ans += (1<<i);
        cout<<ans<<'\n';
    }



    return 0;
}