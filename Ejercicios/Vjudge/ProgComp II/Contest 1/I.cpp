#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;
typedef pair<int,int> ii;

int main(){
    int n; cin>>n;
    int arr[n];
    map<int,int> mapa; //este mapa tiene los valores de los x
    multiset<int> s,invs;
    int maxi=0;
    int x=1;
    rep(i,n){
        cin>>arr[i];
        if(!mapa.count(arr[i])) mapa.insert({arr[i],0});
        mapa[arr[i]]++;

        s.insert(mapa[arr[i]]);
        invs.insert(-mapa[arr[i]]);

        if(mapa[arr[i]]>1) {
            s.erase(s.find(mapa[arr[i]]-1));
            invs.erase(invs.find(-1*(mapa[arr[i]]-1)));
        }

        //for(auto x: invs) cout<<-x<<" "; cout<<endl;

        int aux  =*s.begin();
        int aux2 =*invs.begin();
        //primera opcion eliminar un minimo
        s.erase(s.begin());
        invs.erase(invs.find(-aux));   
        if(aux!=1) {s.insert(aux-1); invs.insert(1-aux);}
        if(!s.empty() && *s.begin()==-*invs.begin()){
            x=i+1;
            //cout<<"elimine el inicio de s"<<endl;
            //cout<<"ans1: "<<*s.begin()<<" "<<-1*(*invs.begin())<<endl;
        } 
        
        if(aux!=1) {s.erase(s.find(aux-1)); invs.erase(invs.find(1-aux));}
        s.insert(aux);
        invs.insert(-aux);

        //segunda opcion eliminar un maximo
        invs.erase(invs.begin());
        s.erase(s.find(-aux2));
        if(aux2!=-1) {invs.insert(aux2+1); s.insert(-aux2-1);}
        if(!invs.empty() && *s.begin()==-*invs.begin()){
            x=i+1;
            //cout<<"elimine el inicio de invs"<<endl;
            //cout<<"ans2: "<<*s.begin()<<" "<<-*invs.begin()<<endl;  
        } 
        if(aux2!=-1) {invs.erase(invs.find(aux2+1));s.erase(s.find(-aux2-1));}
        invs.insert(aux2);
        s.insert(-aux2);
    }

    cout<<x<<endl;

    return 0;
}