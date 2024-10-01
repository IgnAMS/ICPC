#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;


int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int A[n]; rep(i,n) cin>>A[i];
        vector<vector<int>> ans;
        rep(i,n-1){
            if(__gcd(A[i], A[i+1]) != 1) {
                int mini = min(A[i], A[i+1]);
                int auxint = mini+1;
                while(i && (__gcd(auxint, A[i-1])!=1 || __gcd(auxint, mini)!=1)){
                    auxint++;
                }
                vector<int> aux= { i+1, i+2, auxint, mini };
                ans.push_back(aux);
                A[i] = auxint;
                A[i+1] = mini;
            }
        }
        // rep(i,n) cout<<A[i]<<" "; cout<<"\n";
        cout<<ans.size()<<"\n";
        for(auto& u: ans) { for(auto& v: u) cout<<v<<" "; cout<<"\n"; }
    }




    return 0;
}