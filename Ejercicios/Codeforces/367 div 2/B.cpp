#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)

int main(){
    int n; cin>>n;
    vector<int> x(n);
    rep(i,n) cin>>x[i];
    sort(x.begin(),x.end());

    int q; cin>>q;
    int h;
    while(q--){
        cin>>h;
        int l=0;
        int r=n-1;
        int m;
        if(h>=1e5){
            cout<<n<<endl;
            continue;
        }
        //cout<<h<<endl;
        while(l<r){
            m=(l+r)/2;  
            //debo buscar mas abajo
            if(x[m]>h){
                r=m;
            }
            else{
                l=m+1;
            }
        }
        //r es el primero en cumplir que x[r]<=h
        if(x[r]<=h){
            cout<<r+1<<endl;
        }
        else{
            cout<<l<<endl;
        }
        
        
    }


    return 0;
}