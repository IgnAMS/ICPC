#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;

int ans=0;

struct Trie{
	int N[(int)1e6][26] = {0}, S[(int)1e6] = {0}, c = 0; 
	Trie() {}
	void add(string x){
		int p = 0; S[p]++;

		for (char l : x){
			int t = l - 'a';
			if (!N[p][t]) N[p][t] = ++c;
			S[p = N[p][t]] ++;
		}
	}

    void dfs(int p){
        int hijos=0;
        int cant=0;
        rep(i,25) if(N[p][i]) { dfs(N[p][i]); hijos++; }
        ans+= hijos==1? S[p]:0;
    }
};

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; 
    cout<<"aaasdasdsadasasd\n";
    cerr<<"aaasdasdsadasasd\n";
    while(cin>>n){
        if(n==-1) break;
        ans=0;
        string aux;
        Trie trie = Trie();
        int len=0;
        rep(i,n) { cin>>aux; trie.add(aux); }
        trie.dfs(0);
        cout<<ans<<"\n";
    }

    return 0;
}