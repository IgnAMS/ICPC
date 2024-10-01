#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define repx(i,a,b) for(int i=a; i<b; i++)
typedef long long ll;
typedef pair<ll,ll> ii;
#define ff first
#define ss second

int main(){
    int n, k; cin>>n>>k;
    string s; cin>>s;
    string ans = "";
    rep(i,k) ans += s[i % s.size()];
    rep(i, n) {
        string aux = "";
        rep(j, k){
            aux += s[j % s.size()];
        }
        // cout<<aux<<" "<<ans<<"\n";
        ans = min(ans, aux);
        s.pop_back();
    }
    cout<<ans<<"\n";


    return 0;
}