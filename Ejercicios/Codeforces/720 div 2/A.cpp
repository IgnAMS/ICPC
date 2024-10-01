    #include<bits/stdc++.h>
    using namespace std;
    #define rep(i,n) for(int i=0;i<n;i++)
    typedef long long ll;


    int main(){
        ios::sync_with_stdio(0); cin.tie(0);
        int t; cin>>t;
        while(t--){
            ll a,b; cin>>a>>b;
            if(b==1) { cout<<"NO\n"; continue; }
            cout<<"YES\n";
            //cout<<a*b<<" "<<a*(b-1)<<" "<<a*(2*b-1)<<"\n";
            if(b == 2){
                cout<<a*2*(b-1)+a<<" "<<a<<" "<<a*b*2<<"\n";
            }
            else{
                cout<<a*(b-1)<<" "<<a<<" "<<a*b<<"\n";
            }
            
        }





        return 0;
    }