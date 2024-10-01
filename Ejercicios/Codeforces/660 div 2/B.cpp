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
        if(n%4==0){
            for(int i=0;i<n-n/4;i++){
                cout<<9;
            }
            for(int i=0;i<n/4;i++){
                cout<<8;
            }
            cout<<endl;
        }
        else{
            for(int i=0;i< n-n/4-1 ;i++){
                cout<<9;
            }
            for(int i=0;i<n/4+1;i++){
                cout<<8;
            }
            cout<<endl;
        }
    }


    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
    //g++ -O2 [path] && time ./a.out < in > out
}