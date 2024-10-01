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
    while(t--){
        ll n, k; cin>>n>>k;
        vi A(n); rep(i, n) cin>>A[i];
        vi B(n); rep(i, n) cin>>B[i];
        vector<vi> D(n);
        rep(i, n) D[i] = {A[i], B[i]};
        sort(D.begin(), D.end());
        ll ans = k;
        cerr<<"donde muero?\n";
        rep(i, n) {
            cerr<<"voy a procesar\n";
            cerr<<D[i][0]<<' '<<D[i][1]<<'\n';
            if(D[i][0] <= k) k += D[i][1];
        }
        cout<<k<<'\n';

    }


    return 0;
}