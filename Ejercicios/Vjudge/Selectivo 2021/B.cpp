#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--){
        string linea; cin>>linea;
        int n=linea.length();
        vector<char> V(linea.length());
        bool oc = 0;
        rep(i,n) V[i]=linea[i]; 
        rep(i,n-1) if(V[i]!=V[i+1]) oc=1;
        if(!oc) { cout<<-1<<"\n"; continue; }

        sort(V.begin(),V.end());
        rep(i,n) cout<<V[i]; 
        cout<<"\n";
    }


    return 0;
}