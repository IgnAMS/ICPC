#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;
typedef pair<int,int> ii;
typedef pair<ii,int> iii;
#define ff first
#define ss second

struct query{
    int l, r, ind;
    query(int l, int r, int ind): l(l),r(r),ind(ind) {}
};


int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin>>n;
    vector<query> events;
    vector<int> arr(n);
    unordered_map<int,int> conts;
    rep(i,n) {cin>>arr[i]; if(!conts.count(arr[i])) conts.insert({arr[i],0});}
    int m; cin>>m;
    vector<int> ans(m);
    int sqr= sqrt(n);
    
    rep(i,m){
        int l,r;
        cin>>l>>r;
        events.emplace_back(query(l,r,i));
    }

    sort(events.begin(), events.end(), [&](const query &a, const query &b){
        if(a.l/sqr == b.l/sqr) return a.r < b.r;
        return a.l/sqr < b.l/sqr;
    });
    
    int left=events[0].l-1;
    int right=events[0].r-1;
    int cont=0;
    for(int i=events[0].l-1;i<=events[0].r-1;i++){
        if(conts[arr[i]]==0) cont++;
        conts[arr[i]]++;
    }

    ans[events[0].ind] = cont;
    for(int i=1;i<m;i++){
        for(int j=right; j>events[i].r-1; j--){
            //cout<<"quito el elemento "<<j<<"\n";
            conts[arr[j]]--;
            if(conts[arr[j]]==0) cont--;
        }
        
        for(int j=right+1; j<=events[i].r-1; j++){
            //cout<<"agrego el elemento "<<j<<"\n";
            //cout<<conts[arr[j]]<<"\n";
            if(conts[arr[j]]==0) cont++;
            conts[arr[j]]++;
        }


        for(int j=left;j<events[i].l-1;j++){
            //cout<<"quito el elemento "<<j<<"\n";
            //cout<<conts[arr[j]]<<"\n";
            if(conts[arr[j]]==1) cont--;
            conts[arr[j]]--;
        }

        for(int j=left-1;j>=events[i].l-1;j--){
            //cout<<"agrego el elemento "<<j<<"\n";
            if(conts[arr[j]]==0) cont++;
            conts[arr[j]]++;
        }
        
        ans[events[i].ind]=cont;
        left=events[i].l-1;
        right=events[i].r-1;
    }
    
    rep(i,m){
        cout<<ans[i]<<"\n";
    }

    return 0;
}