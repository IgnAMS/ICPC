#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;

#define INF (int)1e9
#define pb push_back
#define OJ                            \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);


int main(){
    OJ;
    int t;
    cin>>t;
    while(t--){
        ll mult=1;
        ll n;
        ll sum=0;
        while((n+mult)/(2*mult)>0){
            sum+=(n+mult)/2;
            mult*=2;
        }
        cout<<sum<<endl;
    }


    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}