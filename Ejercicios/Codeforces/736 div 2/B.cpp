#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;


int main(){
    int t; cin>>t;
    //simular();
    map<int,int> mapa;  
    while(t--){
        int n; cin>>n;
        string aux; cin>>aux;
        bool E[n]; rep(i, n) E[i] = aux[i] == '1';
        cin>>aux;
        bool A[n]; rep(i,n) A[i] = aux[i] == '1';

        int ans = 0;
        rep(i, n) if(A[i] and !E[i]) { A[i] = 0; ans++; continue; }
        
        int aux1 = 0;
        bool E1[n]; rep(i, n) E1[i] = E[i];
        rep(i, n){
            bool entre = 0; 
            if(A[i] and i and E1[i-1]) { 
                E1[i-1] = 0, aux1++;
                //cout<<1<<' '<<i<<'\n';
            }
            else if(A[i] and i<n-1 and E1[i+1]){ 
                E1[i+1] = 0, aux1++;
                //cout<<2<<' '<<i<<'\n';
            }
        }
        cout<<ans+aux1<<'\n';
    }



    return 0;
}