#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  int t=0;
  while(cin>>n){
    if(n==0) break;

    t++;
    vector<int> stacks;
    int h;
    int suma=0;
    for(int i=0;i<n;i++){
      cin>>h;
      suma+=h;
      stacks.push_back(h);
    }
    int prom= suma/n;
    int dif=0;
    for(int i=0;i<n;i++){
      if(stacks[i]-prom>0){
        dif+=stacks[i]-prom;
      }
    }
    printf("Set #%d\nThe minimum number of moves is %d.\n\n",t,dif);

  }



  return 0;
}
