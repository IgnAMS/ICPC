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
// ulimit -s 1000000
// g++ -O2 D.cpp && time ./a.out <input.txt> output.txt

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--) {
        ll n; cin>>n;
        vi A(11, 0);
        ll aux = 1;
        ll sumA = 0, sumB = 0;
        rep(i, 11) {
            A[i] = (n / aux) % 10;
            sumA += A[i];
            aux *= 10;
        }
        // rep(i, 11) cout<<A[i]<<' '; cout<<'\n';
        vi B(11, 0);
        ll i = 0;
        while(abs(sumA - sumB) > 1) {
            while(A[i] == 0) i++;
            A[i]--;
            B[i]++;
            sumA--, sumB++;
        }
        bool oc = 0;
        rep(i, 11) {
            if(A[10 - i] != 0) oc = 1;
            if(oc) cout<<A[10 - i];
        }
        if(!oc) cout<<0;
        cout<<' ';
        oc = 0;
        rep(i, 11) {
            if(B[10 - i] != 0) oc = 1;
            if(oc) cout<<B[10 - i];
        }
        if(!oc) cout<<0;
        cout<<'\n';
    }


    return 0;
}