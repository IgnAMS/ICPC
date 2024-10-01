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
        int maxi=0;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            maxi=max(maxi,arr[i]);
        }

        string linea1="";
        vector<string> ans;
        bool sw=false;
        string linea2="";
        for(int i=0;i<50;i++){
            linea1+='a';
        }
        linea2=linea1;
        ans.push_back(linea1);
        int aux;
        char cont='a';
        for(int i=0;i<n;i++){
            aux=arr[i];
            linea1="";
            linea1= linea2.substr(0,arr[i]);
            cont++;
            if(cont==24) cont=0;
            for(int j=arr[i];j<50;j++){
                linea1+=cont;
            }
            ans.push_back(linea1);
            linea2=linea1;
        }
        
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<endl;
        }

    }


    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
    //g++ -O2 [path] && time ./a.out < in > out
}