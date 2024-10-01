#include<bits/stdc++.h>
using namespace std;
int main(){
  vector<int> snack;
  int n;
  cin>>n;
  int max=n;
  int h;
  bool visit[n];
  for(int i=0;i<n;i++){
    visit[i]=false;
  }
  for(int i=0;i<n;i++){
    cin>>h;
    visit[h-1]=true;
    if(h==max){
      for(int j=h-1;j>=0;j--){
        if(!visit[j]) break;
        else{
          max--;
          if(j<h-1) cout<<" ";
          cout<<j+1;
        }
      }
    }
    cout<<endl;
  }



  return 0;
}
