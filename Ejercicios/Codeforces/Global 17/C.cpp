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
        int n; cin>>n;
        vi A(n), B(n); rep(i, n) cin>>A[i]>>B[i];
        ll l = 0, r = n + 1;
        while(l < r) {
            ll m = (l + r) / 2;
            ll cont = 0;
            rep(i, n) {
                if(m - 1 - A[i] <= cont and cont <= B[i]) cont++;
            }
            if(cont < m) r = m;
            else l = m + 1;
        }
        cout<<l - 1<<'\n';
    }


    return 0;
}