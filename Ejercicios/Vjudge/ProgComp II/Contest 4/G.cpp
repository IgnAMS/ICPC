#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;

struct UnionFind {
    vector<int> p, rank, setSize;
    int numSets;
    UnionFind(int n) {
        numSets = n; setSize.assign(n,1); rank.assign(n, 0); p.resize(n);
        rep(i,n) p[i] = i;
    }
    int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
    bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
    void unionSet(int i, int j) { 
        if (!isSameSet(i, j)) {
            numSets--;
            int x = findSet(i), y = findSet(j);
            // rank is used to keep the tree short  
            if (rank[x] > rank[y]){
                p[y] = x; setSize[x] += setSize[y];
            } else {
                p[x] = y; setSize[y] += setSize[x];
                if (rank[x] == rank[y]) rank[y]++;
            }
        }
    }
    int numDisjointSets() { return numSets; }
    int sizeOfSet(int i) { return setSize[findSet(i)]; }
};



int main(){
    int n,q; cin>>n>>q;
    UnionFind uf= UnionFind(n);
    int a,b; char c;
    while(q--){
        cin>>c>>a>>b;
        if(c=='?') cout<<(uf.isSameSet(a,b)? "yes":"no")<<"\n";
        else uf.unionSet(a,b);
    }

    return 0;
}