#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;
 
 
int main(){
    int t; cin>>t;
    while(t--){
        ll n, k; cin>>n>>k;
        ll A[n]; rep(i,n) cin>>A[i];
        ll maxi=0;
        ll suma=0;
        for(int i=n-1;i>=0;i--){
            if(A[i]<maxi) suma+=maxi-A[i];
            maxi=max(maxi,A[i]);
        }
        if(suma<k) { cout<<"-1\n"; continue; }
        ll q=0;
        int i=0;
        while(q<k){
            while(i<n-2 && A[i]>=A[i+1]) i++;
            while(A[i]<A[i+1] && q<k){
                q++;
                A[i]++;
                if(i>0 && A[i]>A[i-1] && q<k) i--;
            }
            //cout<<q<<" "<<i+1<<"\n";
            if(i==n-2) break;
        }
        if(q<k) cout<<"-1\n";
        else cout<<i+1<<"\n";
    }
 
 
 
 
    return 0;
}