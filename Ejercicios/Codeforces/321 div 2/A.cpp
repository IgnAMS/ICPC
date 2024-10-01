#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)

int inf=1e9+1;

int n;
vector<int> values;

int main(){
    cin>>n;
    values.resize(n);
    rep(i,n) cin>>values[i];
    int low=0;
    int top=0;
    int maxi=values[0];
    int maxint=1;

    for(int i=1;i<n;i++){
        if(values[i]>=maxi){
            maxi=values[i];
            top=i;
        }
        else{
            maxint=max(maxint,top-low+1);
            maxi=values[i];
            low=i;
        }
    }
    maxint=max(maxint,top-low+1);
    cout<<maxint<<endl;
    return 0;
}