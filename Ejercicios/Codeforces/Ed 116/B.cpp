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
    int t; cin>>t;
    while(t--){
        ll n, k; cin>>n>>k;
        ll maxpot2 = 0;
        ll pcs = 1;
        int ans = 0;
        rep(i, 62){
            if(k & (1LL<<i)) maxpot2 = i;
            if(k >= (1LL<<i) and pcs < n){ // puedo usarlo
                // cout<<"tengo "<<(1LL<<(i+1))<<" computadores en este turno\n";
                pcs = 1LL<<(i+1);
                ans = i+1;
            }
        }
        if(pcs >= n) {
            // cout<<"primer ans\n";
            // cout<<"obtuve "<<pcs<<" computadores en "<<ans<<" turno\n";
            cout<<ans<<'\n';
        }
        else {
            // cout<<"segundo ans\n";
            // cout<<"obtuve "<<pcs<<" computadores en "<<ans<<" turno\n";
            cout<<(n - pcs + k - 1) / k + ans<<'\n';
        }
        // cout<<maxpot2<<'\n';
        



    }


    return 0;
}