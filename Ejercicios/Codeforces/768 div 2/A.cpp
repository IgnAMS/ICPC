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
        ll A[n], B[n];
        rep(i, n) cin>>A[i]; 
        rep(i, n) cin>>B[i];
        ll a = 0;
        ll b = 0;
        rep(i, n) a = max(a, max(A[i], B[i])), b = max(b, min(A[i], B[i]));
        cout<<a * b<<'\n';


    }





    return 0;
}