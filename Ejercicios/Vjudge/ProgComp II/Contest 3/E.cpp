#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)

int main(){
    int n; cin>>n;
    int k=log2(n)+1;
    int arr[n];
    rep(i,n) cin>>arr[i];
    int mrq[n][k];
    rep(i,n) mrq[i][0]=arr[i];

    for(int j=1;j<k;j++){
        for(int i=0;i+(1<<j)<=n;i++){
            mrq[i][j]=min(mrq[i][j-1],mrq[i+(1<<(j-1))][j-1]);
        }
    }

    int q;
    cin>>q;
    while(q--){
        int i,j;
        cin>>i>>j;
        int l=j-i+1;
        k=log2(l);
        cout<<min(mrq[i][k],mrq[j-(1<<k)+1][k])<<"\n";
    }



    return 0;
}