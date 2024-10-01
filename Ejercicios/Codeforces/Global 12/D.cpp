#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)

typedef long long ll;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> arr(n);
        string ans="";
        vector<int> conts(n+1,0);
        bool primer=1;
        rep(i,0,n){
            cin>>arr[i];
            conts[arr[i]]++;
            if(conts[arr[i]]>1) primer=0;
        }
        int l=0, r=n-1;
        bool flag=0;
        //cout<<conts[1]<<"\n";
        rep(i,0,n-1){
            if(conts[i+1]>0) ans+='1';
            else { ans+='0'; while(++i<n-1) ans+='0'; }
            if(arr[l]==i+1 && conts[i+1]==1) l++;
            else if(arr[r]==i+1 && conts[i+1]==1) r--;
            else while(++i<n-1) ans+='0';
        }
        if(primer) ans+='1';
        else ans+='0';
        reverse(ans.begin(),ans.end());
        

        cout<<ans<<"\n";
        
    }

    return 0;
}