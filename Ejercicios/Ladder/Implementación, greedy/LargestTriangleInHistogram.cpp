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
    int n; 
    while(cin>>n and n){
        vi A(n); rep(i, n) cin>>A[i];
        vi L(n), R(n); rep(i, n) L[i] = i, R[i] = i;
        vi S;
        rep(i, n){
            while(!S.empty() and A[S.back()] >= A[i]) { L[i] = L[S.back()]; S.pop_back(); }
            S.push_back(i);
        }
        S.clear();
        rep(i, n){
            while(!S.empty() and A[S.back()] >= A[n-i-1]) { R[n-i-1] = R[S.back()]; S.pop_back(); }
            S.push_back(n-i-1);
        }
        ll ans = 0;
        rep(i, n) ans = max(ans, A[i] * (R[i] - L[i] + 1));
        cout<<ans<<'\n';
        
    }

    return 0;
}