#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;


int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> A(n); rep(i,n) cin>>A[i];
        sort(A.begin(),A.end());
        vector<int> aux;
        rep(i,n){
            if(i>0 && A[i]==A[i-1]) aux.push_back(A[i]);
            else cout<<A[i]<<" ";
        }
        rep(i,aux.size()) cout<<aux[i]<<" ";
        cout<<"\n";

    }




    return 0;
}