#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<ll, ll> pll;
typedef double db;
typedef vector<ll> vl;
#define ff first
#define ss second
#define pb push_back
// g++ -std=c++11 A.cpp -o a && a <input.txt> output.txt
// ulimit -s 1000000
// g++ -O2 D.cpp && time ./a.out <input.txt> output.txt

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--) {
        int n; cin>>n;
        ll A[n], Acc[n + 1];
        Acc[0] = 0; 
        rep(i, n) {
            cin>>A[i];
            Acc[i + 1] = Acc[i] + A[i];
        }
        string s;
        cin>>s;

        ll left = n, right = -1;
        ll L[n], R[n];
        for(int i = n - 1; i >= 0; i--) {
            L[i] = left;
            if(s[i] == 'L') left = i; 
        }
        
        rep(i, n) {
            R[i] = right;
            if(s[i] == 'R') right = i;
        }
        
        ll suma = 0;
        while(left <= right) {
            suma += Acc[right + 1] - Acc[left];
            left = L[left];
            right = R[right];
        }

        cout<<suma<<'\n';
    }

    return 0;
}