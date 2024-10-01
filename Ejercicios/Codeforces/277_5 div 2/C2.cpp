#include<bits/stdc++.h>
using namespace std;

bool can(int s, int m){
    return s>=0 && s<=9*m;
}

int main(){
    int m,s; cin>>m>>s;
    if(s> m*9 || s==0 && m>1){
        cout<<-1<<" "<<-1<<endl;
    }
    string minn="";
    string maxx="";
    int sum=s;
    for(int i=0;i<m;i++){
        for(int d=0;d<10;d++){
            if((i>0 || d>0 || (s==0 && m==1)) && can(sum-d,m-i-1)){
                minn+= '0'+d;
                sum-=d;
                break;
            }
        }
    }
    sum=s;

    for(int i=0;i<m;i++){
        for(int d=9;d>=0;--d){
            if((i>0 || d>0 || (s==0 && m==1)) && can(sum-d,m-i-1)){
                maxx+= '0'+d;
                sum-=d;
                break;
            }
        }
    }
    cout<<minn<<" "<<maxx<<endl;


    return 0;
}