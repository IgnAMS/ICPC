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
// g++ -O2 D.cpp && time ./a.out <input.txt> output.txt

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--) {
        int n; cin>>n;
        vi A(n), Neg, Pos;
        ll sum1 = 0, sum2 = 0;
        rep(i, n) {
            cin>>A[i];
            if(A[i] < 0) {
                Neg.push_back(A[i]);
                sum1 -= A[i];
            }
            else {
                Pos.push_back(A[i]);
                sum2 += A[i];
            }
        }
        cout<<max(sum1 - sum2, sum2 - sum1)<<'\n';


    }


    return 0;
}