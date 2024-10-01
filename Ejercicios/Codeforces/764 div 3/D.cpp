#pragma GCC optimize("Ofast")
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
    while(t--) {
        int n, k; cin>>n>>k;
        ll suma = 0, imps = 0;
        string s; cin>>s;
        vi F(26, 0);
        for(auto u: s) F[u - 'a']++;
        rep(i, 26) suma += F[i] / 2 * 2, imps += F[i] - F[i] / 2 * 2;
        ll ans = suma / k;
        if(ans % 2 == 0 and suma % k + imps >= k) ans++;
        cout<<ans<<'\n';
    }


    return 0;
}