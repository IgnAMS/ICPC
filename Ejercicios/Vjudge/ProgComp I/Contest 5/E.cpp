#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;

vector<int> List;
set<vector<int>> ans;
vector<int> aux;
int k, n;

void backtrack(int i, int sum){
    if(sum == k) {
        if(!ans.count(aux)){
            int h=0;
            rep(i,aux.size()) cout<<aux[i]<<(i<aux.size()-1? "+":"\n");
        }
        ans.insert(aux);
        return;
    }
    if(sum > k) return;
    if(i == n){
        return;
    }
    // Backtracking agregandolo
    aux.push_back(List[i]);
    backtrack(i+1, sum+List[i]);
    aux.pop_back();
    // Bactrack sin agregarlo
    backtrack(i+1, sum);
}



int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    while(cin>>k>>n){
        List.resize(n); rep(i,n) cin>>List[i];
        ans.clear();
        sort(List.rbegin(), List.rend());
        cout<<"Sums of "<<k<<":\n";
        backtrack(0, 0);
        if(!ans.size()) cout<<"NONE\n";
        
    }

    return 0;
}