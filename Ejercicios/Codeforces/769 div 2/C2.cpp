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
    ll cont = 0;
    while(t--) {
        ll a, b; cin>>a>>b;
        vi A(21, 0), B(21, 0); 
        rep(i, 21) if(a & (1 << i)) A[i] = 1;
        rep(i, 21) if(b & (1 << i)) B[i] = 1;

        ll ans = 0;
        rep(i, 21) {
            if(A[i] and !B[i]) {
                ll aux = 0;
                for(int j = i - 1; j >= 0 and !A[j]; j--) {
                    if(B[j]) aux += (1 << j), B[j] = 0;
                }
                ans += (1 << i) - aux;
                B[i] = 1;
            }
        }
        bool _op = 0;
        rep(i, 21) {
            if(A[i] and !B[i]) ans += (1 << i);
            if(B[i] and !A[i] and (i == 1? !A[0] or (b & 1): 1)) _op = 1;
        }
        ans += _op;
        // cout<<_op<<'\n';
        // rep(i, 21) cout<<A[i]<<' '; cout<<'\n';
        // rep(i, 21) cout<<B[i]<<' '; cout<<'\n';
        ll maxi = -1, auxb = b;
        bool op_or = 0;
        for(int i = 20; i >= 0 and !A[i]; i--) if(B[i] and !A[i]) maxi = i;
        int cont = 0;
        rep(i, 21) if(b & (1 << i)) cont++, op_or = cont >= 2;
        ans = min(ans, b - a);
        if((1 << maxi) > a and (1 << maxi) - a + op_or < ans) cout<<((1 << maxi) - a) + op_or<<'\n';
        else cout<<ans<<'\n';
    }



    return 0;
}