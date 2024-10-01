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
        int n; cin>>n;
        map<int, vector<int>> mapa;
        rep(i, n){
            int x; cin>>x;
            if(!mapa.count(x)) mapa[x] = {};
            mapa[x].push_back(i);
        }
        ll ans = -1;
        for(auto u: mapa){
            rep(i, u.ss.size() - 1) {
                int x1 = u.ss[i], x2 = u.ss[i+1];
                ll dist = x1 + (n - x2);
                ans = max(ans, dist);
            }
        }
        cout<<ans<<'\n';


    }





    return 0;
}