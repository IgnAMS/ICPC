#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define ff first
#define ss second

int main(){
    int n,k; cin>>n>>k;
    vector<int> left(n), right(n);
    vector<int> ans(n,0), arr(n);
    map<int,int> pos;
    rep(i,n) cin>>arr[i];

    right[n-1]=-1;
    rep(i,n){
        left[i]=i-1;
        if(i<n-1) right[i]=i+1;
        pos.insert({arr[i],i}); //el elemento arr[i] esta en i
    }
    bool team=1;
    while(!pos.empty()){
        auto it=pos.rbegin();
        //cout<<"voy a explorar al "<<it->ff<<endl;
        int l,r;
        int u=it->ss;
        for(int i=0;i<k;i++){
            if(right[u]!=-1){
                //cout<<"exploro al "<<arr[right[u]]<<" a la derecha"<<endl;
                ans[right[u]]= team?1:2;
                pos.erase(arr[right[u]]);
                u=right[u];
                if(u!=-1) r=right[u];
            }
            else{
                r=-1;
                break;
            }
        }
        u=it->ss;
        ans[it->ss]=team?1:2;
        pos.erase(it->ff);
        for(int i=0;i<k;i++){
            if(u!=-1 && left[u]!=-1){
                //cout<<"exploro al "<<arr[left[u]]<<" a la izq"<<endl;
                ans[left[u]]=team?1:2;
                pos.erase(arr[left[u]]);
                u=left[u];
                if(u!=-1) l=left[u];
            }
            else{
                l=-1;
                break;
            }
        }
        if(l!=-1){
            right[l]=r;
            //cout<<"marco que el right["<<l<<"]: "<<r<<endl;
        } 
        if(r!=-1){
            left[r]=l;
            //cout<<"marco que el left["<<r<<"]: "<<l<<endl;
        }

        team= !team;
    }
    rep(i,n) cout<<ans[i];
    cout<<endl;


    return 0;
}