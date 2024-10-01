#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--){
        int n,x; cin>>n>>x;
        vector<int> A(n); rep(i,n) cin>>A[i];
        //rep(i,n) cout<<A[i]<<" "; cout<<"\n";
        int sum=0; rep(i,n) sum+=A[i];
        vector<int> ans;
        // si la suma es != x entonces hay sol
        if(sum!=x){
            int acc=0;
            rep(i,n) {
                //notar que esta restriccion nunca pasa al final
                if(A[i]+acc==x){
                    ans.push_back(A[i+1]);
                    ans.push_back(A[i]);
                    acc+=A[i]+A[i+1]; 
                    i++;
                }
                else{
                    ans.push_back(A[i]);
                    acc+=A[i];
                }
            }
            cout<<"YES\n";
            rep(i,n) cout<<ans[i]<<" "; cout<<"\n";
        }
        else{
            cout<<"NO\n";
        }
    }




    return 0;
}