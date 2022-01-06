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
    int t; cin>>t;
    while(t--){
        ll a, b, c, n; cin>>a>>b>>c>>n;
        priority_queue<ll, vector<ll>, greater<ll>> R;
        priority_queue<ll> L;
        ll F[n]; F[0] = 1; R.push(1);
        ll mod = 1000000007;
        repx(i, 1, n){ 
            ll M;
            if(L.size() >= R.size()) M = L.top();
            else M = R.top(); 
            F[i] = ((a * M + b * (i+1) + c) % mod + mod) % mod;
            if(R.top() <= F[i]){ // si es un numero grande lo tiro a la derecha
                R.push(F[i]);
                if(R.size() > L.size()) { 
                    L.push(R.top());
                    R.pop();
                }
            }
            else{   
                L.push(F[i]);
                if(L.size() > R.size()){
                    R.push(L.top());
                    L.pop();
                }
            }

        }
        ll ans = 0; rep(i, n) ans += F[i];
        cout<<ans<<'\n';

    }


    return 0;
}