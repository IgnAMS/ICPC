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
        int n; cin>>n;
        vi A(n); rep(i, n) cin>>A[i];
        string S; cin>>S;
        vi B, C;
        rep(i, n){
            if(S[i] == '1') B.push_back(A[i]);
            else C.push_back(A[i]);
        }
        map<int, int> mapa;
        sort(C.begin(), C.end());
        sort(B.begin(), B.end());
        int cont = 0;
        rep(i, C.size()) mapa[C[i]] = ++cont;
        rep(i, B.size()) mapa[B[i]] = ++cont; 
        rep(i, n) cout<<mapa[A[i]]<<' '; cout<<'\n';
    }





    return 0;
}