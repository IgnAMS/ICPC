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
    int n, a, b; cin>>n>>a>>b;
    if(n == 1) {
        // a, b <= n = 1 -> max(a, b) = 1
        cout<<"YES\n";
        cout<<"0\n";
    }
    else if(n == 2 and max(a, b) == 2 and min(a, b) == 2) {
        cout<<"NO\n";
    }
    else if(n == 2 and max(a, b) == 1) {
        // No es posible, ya que min(a, b) = 1 -> a = b = 1 
        cout<<"NO\n";
    }
    else if(n == 3 and max(a, b) == 1) {
        cout<<"NO\n";
    } 
    else {
        if(max(a, b) == 1) {
            // Este caso es posible, basta hacer una linea
            cout<<"YES\n";
            rep(i, n) {
                rep(j, n) cout<<bool(j == i + 1 or j == i - 1);
                cout<<'\n';
            }
        }
        else { // max(a, b) > 1 -> min(a, b) = 1 
            if(min(a, b) != 1) {
                cout<<"NO\n";
            }
            else {
                // min(a, b) = 1 
                cout<<"YES\n";
                vector<vl> mat(n, vl(n, 0));
                rep(i, n - max(a, b)) {
                    rep(j, n) mat[i][j] = bool(j == i + 1 or j == i - 1);
                }
                rep(j, n) mat[n - max(a, b)][j] = mat[j][n - max(a, b)];

                if(a == 1) {
                    // a = 1 -> b > 1
                    rep(i, n) {
                        rep(j, n) cout<<bool(!mat[i][j] and i != j); cout<<'\n';
                    }
                }
                else {
                    rep(i, n) {
                        rep(j, n) cout<<mat[i][j]; cout<<'\n';
                    }
                }
            }

        }
    }





    return 0;
}