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


int main(){
    //OJ;
    int n;
    cin>>n;
    while(n--){
        int m;
        cin>>m;
        int temp;
        set<int> S;
        int sum=0;
        int inf=1024;
        for(int i=0;i<m;i++) {
            cin>>temp;
            S.insert(temp);
        }
        int ans=-1;
        for(int k=1;k<1024;k++){
            set<int> elements;
            for(set<int>::iterator it=S.begin();it!=S.end();it++){
                if(S.count(*it^k)){
                    if(!elements.count(*it^k)){
                        elements.insert(*it^k);
                    }
                    else{
                        break;
                    }
                }
                else{
                    break;
                }
            }
            if(elements.size() == S.size()){
                ans=k;
                break;
            }
        }
        cout<<ans<<endl;
        /*int maxii=  
        for(int i=1;i<){

        }*/
    }


    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}