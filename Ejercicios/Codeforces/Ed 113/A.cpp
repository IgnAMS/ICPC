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
        string linea; cin>>linea;
        int l = -1, r = -1;
        rep(i, n) repx(j, i+1, n){
            ll cont = 0;
            repx(k, i, j+1){
                if(linea[k] == 'a') cont++;
                else cont--;
            }
            // cout<<i<<" "<<j<<" "<<cont<<"\n";
            if(cont == 0) {
                l = i+1, r = j+1;
            }
        }
        cout<<l<<' '<<r<<'\n';
    }


    return 0;
}
