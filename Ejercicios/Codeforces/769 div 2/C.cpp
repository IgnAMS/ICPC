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
        ll a, b; cin>>a>>b;
        vi A(21, 0), B(21, 0);
        rep(i, 21) {
            if(a & (1 << i)) A[i] = 1;
            if(b & (1 << i)) B[i] = 1;
        }
        ll auxA = 0, lastA = -1, auxB = 0, lastB = -1;
        ll ans = 0;
        bool op_aux = 0, op_or = 0;
        rep(i, 21) {
            if(A[i] and !B[i]) { // este siempre conviene
                ans += (1 << i) - auxB;
                if(auxB != 0) auxA = 0;
                else auxA += (1 << i);
                auxB = 0;
            }
            else if(B[i] and !A[i]) {
                if(auxA == 0) op_aux = 1, auxB += (1 << i);
                else op_aux = 0, auxB = 0, ans += (1 << i) - auxA;
                auxA = 0;
            }
        }

        cout<<ans + op_or<<'\n';
    }



    return 0;
}