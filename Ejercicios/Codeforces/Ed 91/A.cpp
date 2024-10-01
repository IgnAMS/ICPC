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
        int n;
        cin>>n;
        int arr[n];
        ii minizq[n];
        ii minder[n];
        int mini=10000;
        bool yes=false;
        for(int i=0;i<n;i++){
            cin>>arr[i];

            if(mini > arr[i]){
                mini=arr[i];
                minizq[i]=ii(mini,i);
            }
            else{
                minizq[i]=minizq[i-1];
            }
        }
        mini=10000;
        for(int i=n-1;i>=0;i--){
            if(mini > arr[i]){
                mini=arr[i];
                minder[i]=ii(mini,i);
            }
            else{
                minder[i]=minder[i+1];
            }
        }
        for(int i=1;i<n-1;i++){
            if(minizq[i-1].first<arr[i] && arr[i]>minder[i+1].first){
                cout<<"YES"<<endl;
                cout<<minizq[i-1].second+1<<" "<<i+1<<" "<<1+minder[i+1].second<<endl;
                yes=true;
                break;
            }
        }
        if(!yes){
            cout<<"NO"<<endl;
        }

    }


    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
    //g++ -O2 [path] && time ./a.out < in > out
}