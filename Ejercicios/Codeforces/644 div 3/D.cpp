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
        int ans = 1;
        repx(i, 1, sqrt(n) + 1) {
            if(n % i == 0) {
                if(i <= k) ans = max(ans, i);
                if(n / i <= k) ans = max(ans, n / i);
            }
        }
        cout<<n / ans<<'\n';
    }





    return 0;
}