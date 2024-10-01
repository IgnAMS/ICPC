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
        int n; cin>>n;
        string line; cin>>line;
        char mat[n][n]; rep(i, n) rep(j, n) mat[i][j] = '=';
        rep(i, n) mat[i][i] = 'X';
        int uno = 0; 
        vector<int> dos;
        rep(i, n) {
            if(line[i] == '1') uno++;
            else dos.push_back(i);
        }
        if(dos.size() <= 2 and dos.size() != 0) { cout<<"NO\n"; continue; }
        bool pos = 1;
        rep(i, dos.size()){
            mat[dos[i]][dos[(i+1) % dos.size()]] = '+';
            mat[dos[(i+1) % dos.size()]][dos[i]] = '-';
        } 
        cout<<"YES\n";
        rep(i, n) { rep(j, n) cout<<mat[i][j]; cout<<"\n"; }
    }

    return 0;
}