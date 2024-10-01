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
        }
        string linea1="";
        vector<string> ans;
        bool sw=false;
        string linea2="";
        char cont='a';
        for(int i=0;i<arr[0];i++){
            linea1+='a';
        }
        if(arr[0]==0){
            linea1+='a';
        }
        linea2=linea1;
        ans.push_back(linea1);
        int aux;
        //cout<<n<<endl;
        for(int i=0;i<n;i++){
            aux=arr[i];
            linea1="";
            linea1= linea2.substr(0,arr[i]);
            if(i<n-1 && arr[i+1]>arr[i]) cont++;
            if(cont>'z') cont='a';
            for(int j=arr[i]; i<n-1 && j < arr[i+1] ;j++){
                linea1+=cont;
            }

            if(i<n-1 && max(arr[i],arr[i+1])==0){
                char xd=linea2[0];
                xd++;
                if(xd>'z') xd='a';
                linea1+=xd;
            }

            if(i==n-1 && arr[i]==0){
                char xd=linea2[0];
                xd++;
                if(xd>'z') xd='a';
                linea1+=xd;
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