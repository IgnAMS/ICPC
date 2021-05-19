#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define repx(i,a,b) for(int i=a;i<b;i++)
typedef long long ll;

int main(){
    int n;
    while(cin>>n && n){
        int A[n];
        int first=-1;
        rep(i,n) { cin>>A[i]; if(first==-1 && A[i]) first = i; }
        if(first==-1) { cout<<(n+1)/2<<"\n"; continue; }
        int ind=(first+1)%n;
        int ans=0, cont=0;
        repx(i, first, n+first){
            if(A[i%n]==1) { ans+=cont/2; cont=0; }
            else cont++; 
        }
        ans+=cont/2;
        cout<<ans<<"\n";
    }


    return 0;
}