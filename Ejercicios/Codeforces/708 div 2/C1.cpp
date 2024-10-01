#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin>>t;
    while(t--){
        int n,k; cin>>n>>k;
        if(n%2==1){
            cout<<n/2<<" "<<n/2<<" "<<1<<"\n";
        }
        else{
            if(n%4==0){
                cout<<n/2<<" "<<n/4<<" "<<n/4<<"\n";
            }
            else{
                cout<<(n-2)/2<<" "<<(n-2)/2<<" "<<2<<"\n";
            }
            
        }
    }




    return 0;
}