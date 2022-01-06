#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    bool primer=1;
    while(cin>>n && n){
        if(primer) primer=0;
        else cout<<"\n";
        vector<int> A(n); rep(i,n) cin>>A[i];
        for(int i=0;i<n-5;i++){
            for(int j=i+1;j<n-4;j++){
                for(int k=j+1;k<n-3;k++){
                    for(int h=k+1;h<n-2;h++){
                        for(int l=h+1;l<n-1;l++){
                            for(int a=l+1;a<n;a++){
                                cout<<A[i]<<" "<<A[j]<<" "<<A[k]<<" "<<A[h]<<" "<<A[l]<<" "<<A[a]<<"\n";
                            }
                        }
                    }
                }
            }
        }
        

    }



    return 0;
}