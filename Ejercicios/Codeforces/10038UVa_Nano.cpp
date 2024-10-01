#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  while(cin>>n){
    int list[n];
    vector<bool> visit(n-1,false);
    int rest=0;
    int ant=0;
    bool xd=true;
    bool primer=true;
    int cont=0;
    ant=abs(list[1]-list[0]);

    for(int i=0;i<n;i++){
      if(primer){
        cin>>list[i];
        primer=false;
        continue;
      }
      //cout<<"aaaa\n";
      cin>>list[i];
      rest=abs(list[i-1]-list[i]);
      rest--;
      if(rest<n-1 &&rest>=0){
        if(!visit[rest]) cont++;
        visit[rest]=true;
      }
    }

    if(cont==n-1) cout<<"Jolly\n";
    else cout<<"Not jolly\n";




  }



  return 0;
}
