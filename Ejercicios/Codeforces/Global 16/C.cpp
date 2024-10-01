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
        string a, b; cin>>a>>b;
        ll ans = 0;
        int cont0 = 0, cont1 = 0;
        rep(i, n){
            int prev = ans;
            if(a[i] != b[i]) ans += 2 + cont0, cont0 = 0, cont1 = 0;
            else if(a[i] == '0' and cont1 != 0) ans += 2, cont0 = 0, cont1 = 0;
            else if(a[i] == '0') cont0++;
            else if(a[i] == '1' and cont0 != 0) ans += 2 + cont0 - 1, cont0 = 0, cont1 = 0;
            else if(a[i] == '1') cont1++; 
            // cout<<"varie en "<<ans - prev<<'\n';
        }
        ans += cont0;
        cout<<ans<<'\n';


    }





    return 0;
}