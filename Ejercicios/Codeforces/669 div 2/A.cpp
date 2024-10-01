#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int arr[n];
        int sum0=0,sum1=0;
        rep(i,n) {
            cin>>arr[i]; 
            if(i%2==0 && arr[i]==1) sum0++; 
            if(i%2==1 && arr[i]==1) sum1++;
        }
        if(sum0==sum1){
            cout<<n<<"\n";
            rep(i,n) cout<<arr[i]<<" ";
            cout<<"\n";
            continue;
        }


        int acc0[n],acc1[n]; 
        memset(acc0,0,sizeof(acc0)); 
        memset(acc1,0,sizeof(acc1));
        acc1[n-1]= arr[n-1]==1? 1:0;
        acc1[n-2]= acc1[n-1];
        acc0[n-2]= arr[n-2]==1? 1:0;

        for(int i=n-3;i>=0;i--){
            acc0[i]=acc0[i+1], acc1[i]=acc1[i+1];
            if(i%2==0 && arr[i]==1) acc0[i]++;
            if(i%2==1 && arr[i]==1) acc1[i]++; 
        }
        //cout<<sum0<<" "<<sum1<<"\n";
        //cout<<acc0[0]<<" "<<acc1[0]<<"\n";
        int ind=-1;
        for(int i=0;i<n;i++){
            //cout<<i<<"\n";
            //cout<<sum0-acc0[i]+acc1[i]<<" "<<sum1-acc1[i]+acc0[i]<<"\n";
            if(i%2==0){
                if(sum0-acc0[i]+acc1[i]==sum1-acc1[i]+acc0[i]-(arr[i]==1? 1:0)){
                    ind=i;
                    //cout<<ind<<"\n";
                    break;
                }
            }
            else{
                if(sum0-acc0[i]+acc1[i]-(arr[i]==1? 1:0)==sum1-acc1[i]+acc0[i]){
                    ind=i;
                    //cout<<ind<<"\n";
                    break;
                }
            }
        }
        cout<<n-1<<"\n";
        rep(i,n){
            if(i==ind) continue;
            cout<<arr[i]<<" ";
        }
        cout<<"\n";
    }


    return 0;
}