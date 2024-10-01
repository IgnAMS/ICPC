#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

#define INF (int)1e9
#define pb push_back
#define OJ                            \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);




int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cout.tie(0);
    //OJ;
    int t; cin>>t;  
    while(t--){
        int n,r;
        cin>>n>>r;
        ll mini=min(n,r);
        ll ans=(mini*(mini+1))/2;
        if(r>=n) ans+= -mini+1;
        cout<<ans<<endl;
        /*
        ans=1;
        for(int i=2;i<=r;i++){
            if(i>=n){
                ans++;
                break;
            }
            ans+=i;
        }
        //cout<<"ans: ";
        cout<<ans<<endl;
        */

    }

    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
    //g++ -O2 [path] && time ./a.out < in > out
}