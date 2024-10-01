#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

#define INF (int)1e9
#define pb push_back
#define OJ                            \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cout.tie(0);
    OJ;
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int abemus= (1<<(n))-1;
        cout<<abemus<<endl;

        string linea1,linea2;
        cin>>linea1>>linea2;

        int a=0,b=0;

        for(int i=0;i<n;i++){
            if(linea1[i]=='1'){
                a+=1<<(n-i-1);
            }
            if(linea2[i]=='1'){
                b+=1<<(n-i-1);
            }
        }

        vector<int> ans;
        int ind=n-1;
        int cont=0;
        while(a!=b){
            //cout<<"a vale: "<<a<<endl;
            if(a%2 != b%2){
                int aux = a>>ind;
                cont++;
                //cout<<"aux: "<<aux<<endl;
                if(aux%2 == b%2){
                    //cout<<"entre en este if"<<endl;
                    cont++;
                    ans.push_back(1);
                    if(aux%2==1){
                        a -= (1<<ind);
                    }
                    else{
                        a += (1<<ind);
                    }
                    //cout<<"aux<<ind: "<<(1<<ind)<<endl;
                }
                ans.push_back(ind+1);
                //cout<<"a vale: "<<a<<" not a: "<<!a<<endl;
                //cout<<a<<" "<<b<<endl;
                int help=0;
                int asd=0;
                //falta puro invertir el a para conseguir abemus...
                cout<<(a^abemus)<<endl;
                
                for(int i=0;i<ind+1;i++){
                    //cout<<"ind-i: "<<(ind-i)<<endl;
                    asd = ((a+1)%2)<<(ind-i);
                    help += asd;
                    //cout<<"asd: "<<asd<<endl;
                    a/=2;
                }
                a=help;
                cout<<"help: "<<help<<endl;
            }
            abemus/=2;
            cout<<abemus<<endl;
            ind--;
            a/=2;
            b/=2;
        }
        
        cout<<ans.size();
        if(ans.size()==0){
            cout<<endl;
            continue;
        }
        for(int i=0;i<ans.size();i++){
            cout<<" "<<ans[i];
        }
        cout<<endl;
    }


    //cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
    //g++ -O2 [path] && time ./a.out < in > out
}