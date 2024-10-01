#include<bits/stdc++.h>
using namespace std;


int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        string linea; cin>>linea;
        
        int cont=0;

        int arr[n];
        map<int,vector<int>> mapa;
        mapa.insert({0,vector<int>()});
        mapa.insert({1,vector<int>()});
        //el mapa indica que  
        for(int i=0;i<n;i++){
            if(linea[i]=='1'){
                //si es 1, entonces busco un conjunto que termina en 0
                if(mapa[0].size()>0){
                    arr[i]=arr[mapa[0][0]];
                    mapa[1].push_back(mapa[0][0]);
                    mapa[0].erase(mapa[0].begin());
                }
                else{
                    mapa[1].push_back(i);
                    arr[i]=mapa[0].size()+mapa[1].size();
                }
            }
            else{
                //si es 0, busco un conjunto que termina en 1
                if(mapa[1].size()>0){
                    arr[i]=arr[mapa[1][0]];
                    mapa[0].push_back(mapa[1][0]);
                    mapa[1].erase(mapa[1].begin());
                }
                else{
                    mapa[0].push_back(i);
                    arr[i]=mapa[0].size()+mapa[1].size();
                }
            }
        }
        cout<<mapa[0].size()+mapa[1].size()<<endl;
        for(int i=0;i<n;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }



    return 0;
}