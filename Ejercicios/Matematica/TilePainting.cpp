#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(long long  i=a; i<b; i++)
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
    ll n; cin>>n;
    ll aux = -1, ans;
    repx(i, 2, sqrt(n)+1){
        if(n % i == 0){
            ans = i;
            aux = n / ll(i);
            while(aux % i == 0) aux /= i;
            break;
        }
    }
    if(aux == -1) cout<<n<<'\n';
    else if(aux != 1) cout<<1<<'\n';
    else cout<<ans<<'\n';
    
    
    return 0;
}