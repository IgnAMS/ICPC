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
        int n,k;
        cin>>n>>k;
        int mat[n][n];
        memset(mat,0,sizeof(mat));
        
        if(k%n==0) cout<<0<<endl;
        else cout<<2<<endl;

        for(int i=0;i<n;i++){
            for(int j=0;j<n && k>0;j++){
                k--;
                mat[j][(i+j)%n]=1;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<mat[i][j];
            }
            cout<<endl;
        }
    }

    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
    //g++ -O2 [path] && time ./a.out < in > out
}