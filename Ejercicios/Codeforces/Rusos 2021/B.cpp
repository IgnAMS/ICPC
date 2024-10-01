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
        bool eq = 1;
        bool crec = 1, decrec = 1;
        rep(i, n-1) {
            if(A[i] != A[i+1]) eq = 0;
            if(A[i] < A[i+1]) decrec = 0;
            if(A[i] > A[i+1]) crec = 0;
        }
        bool cconst = 1;
        rep(i, n-2) if(A[i] - A[i+1] != A[i+1] - A[i+2]) cconst = 0;
        if((crec or decrec) and !cconst) { cout<<"-1\n"; continue; }
        if((crec or decrec) and cconst) { cout<<"0\n"; continue; }
        // Existe un segmento creciente! por ende se puede calcular c.
        // Tambien existe un segmento decreciente, por ende se puede calcular m
        ll c, m; 
        rep(i, n-1) if(A[i] < A[i+1]) c = A[i+1] - A[i];
        rep(i, n-1) if(A[i] > A[i+1]) m = A[i] + (c - A[i+1]);
        // cout<<c<<" "<<m<<'\n';
        // verifico que este todo bien
        ll a = A[0];
        ll maxi = 0; rep(i, n) maxi = max(maxi, A[i]);
        bool oc = m > maxi;
        repx(i, 1, n){
            a = (a + c) % m;
            if(A[i] != a) oc = 0;
        }
        if(oc) cout<<m<<' '<<c<<"\n";
        else cout<<"-1\n";
        

    }



    return 0;
}