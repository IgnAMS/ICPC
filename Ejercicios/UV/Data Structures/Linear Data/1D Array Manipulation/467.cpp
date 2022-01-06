#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    string linea;
    int s=0;
    while(getline(cin,linea)){
        s++;
        vector<int> time;
        int aux=0;
        int mini=91, maxi=0;
        rep(i,linea.length()){
            if(linea[i]==' '){
                time.push_back(aux);
                mini=min(mini,aux);
                maxi=max(maxi,aux);
                aux=0;
                continue;
            }
            aux= aux*10+linea[i]-'0';
        }
        if(aux!=0){
            time.push_back(aux); mini=min(mini,aux); maxi=max(maxi,aux);
        }
        vector<int> col(time.size(),0); //0->green, 1->yellow, 2->red
        int ans=-1;
        for(int i=mini-5;i<=60*60;i++){
            bool flag=1;
            //cerr<<"time: "<<i<<", casos: ";
            rep(j,time.size()){
                if(col[j]==0 && (i+5)%time[j]==0) col[j]= 1;
                else if(col[j]==1 && i%time[j]==0) col[j]= 2;
                else if(col[j]==2 && i%time[j]==0) col[j]= 0;
                if(col[j]) flag=0;
                //cerr<<col[j]<<" ";
            }
            //cerr<<"\n";
            if(flag){ ans=i; break;}
        }
        ans=ans;
        cout<<"Set "<<s<<" ";
        if(ans>0) cout<<"synchs again at "<<ans/60<<" minute(s) and "<<ans%60<<" second(s) after all turning green.\n";
        else cout<<"is unable to synch after one hour.\n";
        
    }
}