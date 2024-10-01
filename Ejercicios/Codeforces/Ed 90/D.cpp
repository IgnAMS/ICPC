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
        int n; cin>>n;
        vector<ll> paresacc;
        vector<ll> imparesacc;
        vector<ll> num(n);
        ll acc=0;
        for(int i=0;i<n;i++){
            cin>>num[i];
            if(i%2==0) acc+=num[i];
        }
        ll maxi=0;
        ll kad1=0;
        for(int i=0;i<n-1;i+=2){
            kad1+= num[i+1]-num[i];
            if(kad1<0) kad1=0;
            maxi=max(maxi,kad1);
        }
        ll kad2=0;
        for(int i=1;i<n-1;i+=2){
            kad2+= num[i]-num[i+1];
            if(kad2<0) kad2=0;
            maxi=max(maxi,kad2);
        }
        cout<<acc+maxi<<endl;
    }


    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
    //g++ -O2 [path] && time ./a.out < in > out
}