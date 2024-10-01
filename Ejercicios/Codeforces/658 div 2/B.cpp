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
        ll arr[n];
        ll sum=0;
        bool rulea=1;
        int ans=-1;
        bool primer=true;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            if(arr[i]==1){
                rulea=!rulea;
            }
            if(arr[i]>1 && primer){
                primer=false;
                //cout<<"rulea: "<<rulea<<endl;
                ans=rulea;
            }
        }
        if(ans==-1){
            if(rulea!=0){
                cout<<"Second"<<endl;
            }
            else{
                cout<<"First"<<endl;
            }
            
        }
        else{
            if(ans==0){
                cout<<"Second"<<endl;
            }
            else{
                cout<<"First"<<endl;
            }
        }
    }


    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
    //g++ -O2 [path] && time ./a.out < in > out
}