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
    int t; cin>>t;
    while(t--) {
        int n; cin>>n;
        ll imppos = 0, parpos = 0;
        vi A(n); rep(i, n) {
            cin>>A[i];
            imppos += A[i] % 2;
            parpos += A[i] % 2 == 0;
        }
        int m; cin>>m;
        ll impneg = 0, parneg = 0;
        vi B(m); rep(i, m) {
            cin>>B[i];
            impneg += B[i] % 2;
            parneg += B[i] % 2 == 0;
        }
        cout<<impneg * imppos + parneg * parpos<<'\n';
    }





    return 0;
}