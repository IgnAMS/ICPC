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
    OJ;
    int t; cin>>t;
    while(t--){
        int n,m; cin>>n>>m;
        int arr1[n],arr2[m];
        unordered_set<int> nums;
        int ans=-1;
        for(int i=0;i<n;i++){
            cin>>arr1[i];
            nums.insert(arr1[i]);
        }
        for(int i=0;i<m;i++){
            cin>>arr2[m];
            if(nums.count(arr2[m])){
                ans=arr2[m];
            }
        }
        if(ans=-1){
            cout<<"NO\n";
        }
        else{
            cout<<"YES\n";
            cout<<1<<" "<<ans<<endl;
        }
    }


    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
    //g++ -O2 [path] && time ./a.out < in > out
}