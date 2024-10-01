#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin>>t;
    while(t--){
        string a, b; cin>>a>>b;
        int n1= a.length(), n2 = b.length();
        set<string> sa;
        set<string> sb;
        for(int i=0;i<n1;i++){
            for(int j=i+1;j<=n1;j++){
                string aux="";
                for(int k=i;k<j;k++){
                    aux+=a[k];
                }
                sa.insert(aux);
            }
        }
        for(int i=0;i<n2;i++){
            for(int j=i+1;j<=n2;j++){
                string aux="";
                for(int k=i;k<j;k++){
                    aux+=b[k];
                }
                sb.insert(aux);
            }
        }
        int maxi=0;
        for(auto u: sa){
            for(auto& v:sb){
                if(u==v){
                    maxi=max((int)u.length(),maxi);
                }
            }
        }
        cout<<a.length()+b.length()-2*maxi<<"\n";
    }




    return 0;
}