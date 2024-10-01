#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;
#define ff first
#define ss second


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        map<int, vector<ll>> A;
        vector<ll> U(n), s(n);
        rep(i,n) cin>>U[i];
        rep(i,n){
            cin>>s[i];
            if(!A.count(U[i])) A[U[i]]=vector<ll>();
            A[U[i]-1].push_back(s[i]);
        }
        for(auto& u: A) sort(u.ss.begin(), u.ss.end());
        map<int, vector<ll>> Acc;
        for(auto& u: A){
            Acc[u.ff] = vector<ll>();
            Acc[u.ff].assign(A[u.ff].size()+1, 0);
            for(int j=1; j<=A[u.ff].size(); j++){
                Acc[u.ff][j] = Acc[u.ff][j-1] + A[u.ff][j-1];
            }
        }
        
        for(int k=1; k<=n; k++){
            ll sum=0;
            for(auto& u: Acc){ 
                int siz=u.ss.size(); 
                sum += u.ss[siz-1] - u.ss[(siz-1)%k];
            }
            if(sum==0) while(k<=n && k++) cout<<0<<" ";
            else cout<<sum<<" ";
        }

        cout<<"\n";
        

    }




    return 0;
}