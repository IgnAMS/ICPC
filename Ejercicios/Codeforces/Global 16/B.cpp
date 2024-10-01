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
        string line; cin>>line;
        int n = line.length();
        int cont = 0;
        if(line[0] == '0') cont++;
        repx(i, 1, n) if(line[i] == '0' and line[i-1] != '0') cont++;
        if(cont == 0) cout<<0<<'\n';
        else if(cont == 1) cout<<1<<'\n';
        else cout<<2<<'\n';


    }





    return 0;
}