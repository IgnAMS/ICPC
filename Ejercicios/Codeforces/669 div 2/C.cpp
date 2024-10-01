#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin>>n;
    int op1, op2;
    int ans[n];
    memset(ans,-1,sizeof(ans));
    int use=1;
    //cout<<"aaa"<<endl;

    for(int i=1;i<=n-1;i++){
        cout<<"? "<<use<<" "<<i+1<<endl;
        cin>>op1;
        cout<<"? "<<i+1<<" "<<use<<endl;
        cin>>op2;
        if(op1>op2){
            //la operacion 1 es mayor, por ende p1%p2 -> p2 es mayor
            ans[use-1]=op1;
            //cout<<"1 la respuesta de "<<use<<" es: "<<op1<<"\n";
            use=i+1;
        }
        else{
            //la operacion 2 es mayor, por ende p2%p1 -> p1 es mayor
            ans[i+1-1]=op2;
            //cout<<"2 la respuesta de "<<i+1<<" es: "<<op2<<"\n";
        }
    }
    
    ans[use-1]=n;
    cout<<"! ";
    rep(i,n) cout<<ans[i]<<" ";
    cout<<"\n";


    return 0;
}
