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
        int n; cin>>n;
        int arr[n];
        for(int i=0;i<n;i++) cin>>arr[i];

        string linea1="",linea2;
        for(int i=0;i<51;i++) linea1+="a";
        linea2=linea1;
        cout<<linea1<<endl;
        for(int i=0;i<n;i++){
            linea1=linea2;
            if(linea2[arr[i]]=='a'){
                linea1[arr[i]]='b';
            }
            else{
                linea1[arr[i]]='a';
            }
            cout<<linea1<<endl;
            linea2=linea1;
        }
    }


    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
    //g++ -O2 [path] && time ./a.out < in > out
}