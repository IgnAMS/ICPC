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
    while(t-- ) {
        int n; cin>>n;
        ll mat[n][n]; rep(i, n) rep(j, n) cin>>mat[i][j];
        ll ans = 0;
        // cout<<"\n\nnuevo caso: \n";
        // cout<<"hor-up\n";
        // hor - up
        rep(i, n / 2) rep(j, (n + 2) / 4 - i)  {
            // cout<<mat[2 * i][4 * j + 2 * i]<<' '<<mat[2 * i][4 * j + 2 * i + 1]<<'\n';
            ans ^= mat[2 * i][4 * j + 2 * i] ^ mat[2 * i][4 * j + 2 * i + 1];
        }
        // cout<<"\nhor-down\n";
        // hor - down
        rep(i, n / 2 - ((n / 2) % 2)) rep(j, n / 4 - i) {
            ll aux = ((n / 2) % 2? 2: 0);
            // cout<<mat[n - 1 - 2 * i][4 * j + 2 * i + aux]<<' '<<mat[n - 1 - 2 * i][4 * j + 2 * i + aux + 1]<<'\n';
            ans ^= mat[n - 1 - 2 * i][4 * j + 2 * i + aux] ^ mat[n - 1 - 2 * i][4 * j + 2 * i + aux + 1];
        }

        // cout<<"\nvert-right\n";
        // vert - right
        rep(i, n / 4) rep(j, n / 4 - i) {
            ll aux = (n / 2) % 2? 3: 1;
            // cout<<mat[aux + 2 * i + 4 * j][n - 1 - 2 * i]<<' '<<mat[aux + 2 * i + 4 * j + 1][n - 1 - 2 * i]<<'\n';
            ans ^= mat[aux + 2 * i + 4 * j][n - 1 - 2 * i] ^ mat[aux + 2 * i + 4 * j + 1][n - 1 - 2 * i];
        }

        // cout<<"\nvertleft\n";
        // vert-left
        repx(i, (n % 4 == 0), n / 4) rep(j, n / 4 - i) {
            ll aux = (n / 2) % 2? 3 : 1;
            // cout<<mat[aux + 2 * i + 4 * j][2 * (i - (n % 4 == 0))]<<' '<<mat[aux + 2 * i + 4 * j + 1][2 * (i - (n % 4 == 0))]<<'\n';
            ans ^= mat[aux + 2 * i + 4 * j][2 * (i - (n % 4 == 0))] ^ mat[aux + 2 * i + 4 * j + 1][2 * (i - (n % 4 == 0))];
        } 

        cout<<ans<<'\n';


    }


    return 0;
}