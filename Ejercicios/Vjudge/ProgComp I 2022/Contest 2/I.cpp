#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<ll, ll> ii;
typedef double db;
typedef vector<ll> vi;
#define ff first
#define ss second
// g++ -std=c++11 A.cpp -o a && a <input.txt> output.txt
//  g++ -O2 D.cpp && time ./a.out < input.txt > output.txt

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll w, m, k; cin>>w>>m>>k;
    ll aux = m, up = 1, exp = 0;
    while(aux) up *= 10, aux /= 10, exp++;
    ll ans = 0; aux = m;
    // aux sera el elemento que no he añadido, 
    while(w / (exp * k) >= up - aux) {
        // cout<<w<<' '<<aux<<' '<<up<<' '<<exp<<'\n';
        w -= (up - aux) * k * exp;
        ans += up - aux;
        aux = up;
        up *= 10;
        exp++;
    }
    // cout<<w<<' '<<k * exp<<'\n';
    ans += w / (k * exp); 
    cout<<ans<<'\n';
    





    return 0;
}