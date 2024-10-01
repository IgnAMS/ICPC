#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        string b; cin>>b;
        string a="";
        int i=0;
        char c=b[0];
        bool sw=1;
        while(1){
            while(i<n && b[i]==c){
                a+=(sw? '1':'0');
                sw=!sw;
                i++;
            }
            if(i==n) break;
            sw= (a[i-1]==b[i-1]? 1:0);
            if(a[i-1]==b[i-1]){
                sw=1;
            }
            else{
                if(b[i]=='0') sw=0;
                else sw=1;
            }
            c=b[i];
        }
        cout<<a<<"\n";
    }



    return 0;
}