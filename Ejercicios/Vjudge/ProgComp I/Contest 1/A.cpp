#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin>>n;
    string line; cin>>line;
    char c=line[0];
    int cont=0;
    for(int i=1;i<n;i++) line[i]==c? cont++:c=line[i];
    cout<<cont<<"\n"; 
    




    return 0;
}