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
    int t;
    cin>>t;
    int n,k;
    while(t--){
        cin>>n>>k;
        vector<int> a(n);
        vector<int> w(k);
        int cont=0;
        for(int i=0;i<n;i++) cin>>a[i];
        for(int i=0;i<k;i++){
            cin>>w[i];
            if(w[i]==1){
                cont++;
            }
        }
        int aux=cont;
        sort(a.begin(),a.end());
        sort(w.begin(),w.end(), greater<int>());
        long long sum=0;
        for(int i=n-1;i>=n-k;i--){
            sum+= a[i];
            if(aux>0){
                sum+=a[i];
                aux--;
            }
        }
        int help=0;
        for(int i=0;i<k-cont;i++){
            sum+=a[help];
            help+=w[i]-1;
        }
        cout<<sum<<endl;
    }


    return 0;
}