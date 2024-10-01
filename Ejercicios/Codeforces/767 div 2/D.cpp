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
        vector<string> A(n); rep(i, n) cin>>A[i];
        multiset<string> S; rep(i, n) S.insert(A[i]);
        bool ans = 0;
        rep(i, n) {
            string aux1 = "", aux2 = ""; 
            for(int j = A[i].size() - 1; j >= 0; j--) aux1 += A[i][j];
            for(int j = A[i].size() - 2; j >= 0; j--) aux2 += A[i][j];
            if(S.count(aux1) or S.count(aux2)) ans = 1;
            S.erase(S.find(A[i]));
        }
        
        rep(i, n) S.insert(A[i]);
        for(int i = n - 1; i >= 0; i--) {
            string aux = "";
            for(int j = A[i].size() - 1; j >= 1; j--) aux += A[i][j];
            if(S.count(aux)) ans = 1;
            S.erase(S.find(A[i]));
        }
        
        if(ans) cout<<"YES\n";
        else cout<<"NO\n";
    }





    return 0;
}