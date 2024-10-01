#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;


int main(){
    int t; cin>>t;
    while(t--){
        int n, m; cin>>n>>m;
        vector<string> lineas(n);
        rep(i,n) cin>>lineas[i];
        string ans=lineas[0];

        rep(i,m){
            char save=ans[i];
            for(char d='a'; d<='z';d++){
                ans[i]=d;
                bool flag=true;
                rep(j,n){
                    int error=0;
                    rep(k,m){
                        if(ans[k]!=lineas[j][k]){
                            error++;
                        }
                    }
                    if(error>1){
                        flag=false;
                        break;
                    }
                }
                if(flag){
                    cout<<ans<<endl;
                    goto exit;
                }
            }
            ans[i]=save;
        }
        cout<<-1<<endl;
        exit: 
            continue;

    }



    return 0;
}