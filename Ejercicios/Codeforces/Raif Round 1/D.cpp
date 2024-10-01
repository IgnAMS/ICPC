#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;
typedef pair<int,int> ii;
#define ff first
#define ss second

int main(){
    int n; cin>>n;
    vector<int> a(n); 
    bool flag=false;
    int cont3=0, cont2=0, cont1=0;
    vector<int> next;
    rep(i,n){ 
        cin>>a[i];
        if(a[i]>0) next.push_back(i);
    }
    vector<ii> ans;
    vector<int> tres;
    vector<int> dos;
    rep(i,next.size()){
        if(a[next[i]]==3){
            if(!tres.empty()){
                ans.push_back(ii(tres.back(),next[i]));
                tres.pop_back();
            }
            ans.push_back(ii(next[i],next[i]));
            tres.push_back(next[i]);
        }
        if(a[next[i]]==2){
            if(!tres.empty()){
                ans.push_back(ii(tres.back(),next[i])); tres.pop_back();
            }
            ans.push_back(ii(next[i],next[i]));
            dos.push_back(next[i]);
        }
        if(a[next[i]]==1){
            if(!dos.empty()) {
                ans.push_back(ii(dos.back(),next[i]));
                dos.pop_back(); 
            }
            else if(!tres.empty()){
                ans.push_back(ii(tres.back(),next[i]));
                ans.push_back(ii(next[i],next[i]));
                tres.pop_back();
            }
            else ans.push_back(ii(next[i],next[i]));
        }
    }
    if(!dos.empty() || !tres.empty()){
        cout<<-1<<"\n"; return 0;
    } 
    cout<<ans.size()<<"\n";
    rep(i,ans.size()) cout<<ans[i].ff+1<<" "<<ans[i].ss+1<<"\n";

    



    return 0;
}