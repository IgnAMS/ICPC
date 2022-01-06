#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;

    if(n<=3){
        rep(i,n-1) cout<<1<<" ";
        cout<<n<<"\n";
        return 0;
    }
    vector<int> logs(int(log2(1e6))+2,0);
    for(int i=1;i<n+1;i++){
        for(int k=log2(1e6)+1; k>=0;k--){
            //cout<<(1<<k)<<"\n";
            if(i%(1<<k)==0){
                //cout<<i<<"\n";
                logs[k]++;
                break;
            }
        }
    }
    
    int k=0;
    for(int i=0;i<log2(1e6)+2;i++){
        for(int j=0;j<logs[i];j++){
            k++;
            if(k==n && (1<<i)+(1<<(i-1))<=n) { cout<<(1<<i)+(1<<(i-1))<<" "; }  
            else cout<<(1<<i)<<" ";
        }
        //cout<<logs[i]<<" ";
    }
    cout<<"\n";


    return 0;
}