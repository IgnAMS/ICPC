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


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--){
        int n; char c; cin>>n>>c;
        string linea; cin>>linea;
        int ind = -1;
        bool triv = 1;
        repx(i, n/2, n){
            if(linea[i] == c) ind = i;
        }
        rep(i, n) if(linea[i] != c) triv = 0;
        if(triv) cout<<0<<'\n';
        else if(ind != -1) cout<<1<<'\n'<<ind + 1<<'\n';
        else{
            cout<<2<<'\n'<<n-1<<' '<<n<<'\n';
        }
    }





    return 0;
}