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
    //  OJ;
    int t; cin>>t;
    while(t--){
        int n,k,z;
        cin>>n>>k>>z;
        int arr[n];
        for(int i=0;i<n;i++) cin>>arr[i];
        int DP[z+1][n];
        memset(DP,0,sizeof(DP));
        DP[0][0]=arr[0];
        int maxi=0;
        for(int i=0;i<=z;i++){
            for(int j=0;j+2*i<=k;j++){
                int aux=0;
                if(j-1>=0){
                    DP[i][j]=max(DP[i][j-1]+arr[j],DP[i][j]);
                    //cout<<"tomo el anterior "<<DP[j-1][i]<<" y sumo "<<arr[j]<<endl;
                } 
                if(i-1>=0 && j+1<n) DP[i][j]=max(DP[i-1][j+1]+arr[j],DP[i][j]);
                //cout<<DP[i][j]<<" ";
                maxi=max(maxi,DP[i][j]);
            }
            //cout<<endl;
        }
        cout<<maxi<<endl;
    }


    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
    //g++ -O2 [path] && time ./a.out < in > out
}