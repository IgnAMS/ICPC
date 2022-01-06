#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)
typedef long long ll;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int A[n];
        int B[n-1]; rep(i,0,n-1) B[i]=0;
        ll sum=0;
        rep(i,0,n){
            cin>>A[i];
            rep(j,0,i)
                if(A[j]<=A[i]) sum++;
        }
        cout<<sum<<"\n";
    }

    



    return 0;
}