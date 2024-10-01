#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

struct SegmentTree{
    vector<int> max;
    vector<int> min;
    int n;
    SegmentTree(vector<int> &A){
        n=A.size();
        max.resize(4*n);
        min.resize(4*n);
        built(0,);//recordar como hacer el built
    }
};


#define INF (int)1e9
#define pb push_back
#define OJ                            \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cout.tie(0);
    OJ;
    int n,m; cin>>n>>m;
    int x,k,y; cin>>x>>k>>y;
    vector<int> nums(n);
    vector<int> maxi(n);
    vector<int> ans(m);
    bool no=false;
    map<int,int> index;
    for(int i=0;i<n;i++){
        cin>>nums[i];
        index.insert(ii(nums[i],i));
    }
    for(int i=0;i<m;i++){
        cin>>ans[i];
        if(nums[i]!= ans[i] && n==m) {
            no=true;
            break;
        }
        
    } 

    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
    //g++ -O2 [path] && time ./a.out < in > out
}