#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, q; cin>>n>>q;
    int A[n]; rep(i,n) cin>>A[i]; 
    int x;
    while(q--){
        cin>>x;
        //rep(i,n) cout<<A[i]<<" "; cout<<"\n";
        rep(i,n){
            if(A[i]==x){
                cout<<i+1<<" ";
                for(int j=i; j>=1;j--) A[j]=A[j-1];
                A[0]=x;
                break;
            }
        }
    }
    cout<<"\n";





    return 0;
}