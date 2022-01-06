#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;
typedef pair<int,int> ii;
#define ff first
#define ss second

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; 
    while(cin>>n){
        vector<ii> A;
        for(int i=n+1;i<=2*n;i++){
            if( (n*i) % (i-n) == 0){
                A.push_back({n*i/(i-n),i});
            }
        }
        cout<<A.size()<<"\n";
        rep(i,A.size()){
            cout<<"1/"<<n<<" = "<<"1/"<<A[i].ff<<" + "<<"1/"<<A[i].ss<<"\n";
        }
    }



    return 0;
}