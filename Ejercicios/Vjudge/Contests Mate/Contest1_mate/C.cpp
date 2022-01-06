#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;

#define INF (int)1e9
#define pb push_back
#define OJ                            \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
vll lista;

void f(int n){
    vector<bool> visit(n+1,true);

    for(int i=2;i*i<=n;i++){
        if(visit[i]){
            for(int j=i*i;j<=n;j+=i){
                visit[j]=false;
            }
        }
    }
    for(int i=2;i<=n;i++){
        if(visit[i]){
            lista.emplace_back(i);
        }
    }
    return;
}



int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cout.tie(0);
    OJ;
    int n;
    cin>>n;
    f(1e9+1);
    int a,b;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        int lowi,topj;
        int low=0,mid, top=lista.size();
        while(low<top){
            mid=(low+top)/2;
            if(lista[mid]<a){
                low=mid+1;
            }
            else{
                top=mid-1;
                lowi=mid;
            }
        }
        low=0;
        top=lista.size();
        while(low<top){
            mid=(low+top)/2;
            if(lista[mid]<b){
                low=mid+1;
                topj=mid;
            }
            else{
                top=mid-1;
            }
        }
        for(int i=lowi;i<=topj;i++){
            cout<<lista[i]<<endl;
        }
    }


    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
    //g++ -O2 [path] && time ./a.out < in > out
}