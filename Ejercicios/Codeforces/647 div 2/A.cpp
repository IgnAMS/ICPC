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
    for(int i=0;i<n;i++){
        ll a,b;
        cin>>a>>b;
        //la condicion a cumplir es que uno sea multiplo del otro
        if(a%b!=0 && b%a!=0){
            cout<<-1<<endl;
            continue;
        }
        ll aux;
        //haremos que b siempre sea el mayor
        if(a>b){
            aux=b;
            b=a;
            a=aux;
        }
        ll num=b/a;
        //chequeamos de que sean solamente potencias de 2
        //evitar no usar doubles y usar division de 2
        int cont=0;
        while(num%2==0){
            num/=2;
            cont++;
        }
        if(num!=1){
            cout<<-1<<endl;
            continue;
        }
        ll mullt2=cont;
        ll mult8= ll(mullt2)/ll(3);
        mullt2= mullt2%3;
        ll mult4=mullt2/2;
        mullt2%=2;
        //printf("se necesitaron %lld op de 2, %lld op de 4, %lld op de 8\n",mullt2,mult4,mult8);
        cout<<mullt2+mult4+mult8<<endl;
    }

    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}