#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<ll, ll> pll;
typedef double db;
typedef vector<ll> vl;
#define ff first
#define ss second
#define pb push_back
// g++ -std=c++11 A.cpp -o a && a <input.txt> output.txt
// ulimit -s 1000000
// g++ -O2 D.cpp && time ./a.out <input.txt> output.txt



int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, q; cin>>n>>q;
    ll M = 1, R = 0;
    ll p[n + 1];
    rep(i, n + 1) p[i] = i;
    rep(_, q) {
        string com; ll x; 
        cin>>com>>x;
        if(com == "?") {
            x--;
            cout<<p[((x + R) * inverse(M, n)) % n] + 1<<'\n';
        }
        if(com == "+") R += x;
        if(com == "*") {
            if(__gcd(x, n) > 1) {
                // Hay colisiones -> Manejarlas a mano!
                vl X2(n, -1);
                rep(i, n) { 
                    ll old_pos = ((x + R) * inverse(M, n)) % n;
                    ll new_pos = (old_pos * x) % n;
                    if(X2[new_pos] == -1) X2[new_pos] = old_pos;
                    else if(abs(old_pos, new_pos) < abs(X2[new_pos], new_pos)) X2[new_pos] = old_pos;
                }
                rep(i, n / __gcd(n, x)) p[i] = p[X2[i]];
                n = n / __gcd(n, x);
            }
            else {
                R *= x;
                M *= x;
            }
        }
    }





    return 0;
}