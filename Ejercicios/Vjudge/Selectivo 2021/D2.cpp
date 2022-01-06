#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;
typedef pair<int,int> ii;
#define ff first
#define ss second

vector<ii> DP(200010);
int n; 
vector<int> A;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    string linea; cin>>linea;
    n = linea.length(); A.resize(n);
    rep(i,n) A[i]= linea[i]-'0';
    int i=0;
    int suma=0;
    int ans=0;
    rep(j,n){
        suma+=A[j];
        if(suma%3==0) { ans++; i=j; suma=0; }
        else if(A[j]%3==0) { ans++; i=j; suma=0; }
        else if(j-i==3){
            suma=0; ans++; i=j;
        }
    }
    cout<<ans<<"\n";


    return 0;
}