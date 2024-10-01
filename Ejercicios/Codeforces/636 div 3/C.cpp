#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)

int main(){
    ios::sync_with_stdio(0); cin.tie(0);    .tie(0);
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        ll arr[n];
        rep(i,n) cin>>arr[i];

        deque<ll> pos;
        bool p=true;
        ll sum=0;

        rep(i,n){
            //cout<<sum<<endl;
            if(p && arr[i]>0){
                pos.push_back(arr[i]);
                sum+=arr[i];
                p=!p;
            }
            else if(!p && arr[i]>0 && arr[i]>pos.back()){
                sum-=pos.back();
                sum+=arr[i];
                pos.back()=arr[i];
            }
            else if(!p && arr[i]<0){
                sum+=arr[i];
                pos.push_back(arr[i]);
                p=!p;
            }
            else if(p && arr[i]<0 && pos.size() && arr[i]>pos.back()){
                sum-=pos.back();
                sum+=arr[i];
                pos.back()=arr[i];
            }
        }
        deque<ll> neg;
        p=false;
        ll sum2=0;

        rep(i,n){
            //cout<<p<<" "<<sum2<<endl;
            if(p && arr[i]>0){
                neg.push_back(arr[i]);
                sum2+=arr[i];
                p=!p;
            }
            else if(!p && arr[i]>0 && neg.size() && arr[i]>neg.back()){
                sum2-=neg.back();
                sum2+=arr[i];
                neg.back()=arr[i];
            }
            else if(!p && arr[i]<0){
                sum2+=arr[i];
                neg.push_back(arr[i]);
                p=!p;
            }
            else if(p && arr[i]<0 && arr[i]>neg.back()){
                sum2-=neg.back();
                sum2+=arr[i];
                neg.back()=arr[i];
            }
        }

        if(neg.size()>pos.size()){
            cout<<sum2<<endl;
        }
        else if(neg.size()<pos.size()){
            cout<<sum<<endl;
        }
        else{
            cout<<max(sum,sum2)<<endl;
        }

    }

    return 0;
}