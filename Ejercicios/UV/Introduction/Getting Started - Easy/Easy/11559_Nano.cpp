#include<bits/stdc++.h>
using namespace std;

int main () {
  int N, B, H , W;
  while(cin>>N>>B>>H>>W){
    int p;
    int arr[W];
    int x=INT_MAX;

    for(int i=0; i<H; i++){

      cin>>p;
      for(int j=0; j<W; j++){
        //nota importante, esta vez se usa el iterador j ya que la variable i ya esta siendo
        //utilizada
        cin>>arr[j]; // pos 0, 1, 2... w-1 W casos
        if(arr[j]>=N){

          x=min(N*p,x);
          // 1 3 4 0
          // 1 1 1 0
        }
      }

    }
    if(x<=B){
      cout<<x<<"\n";
    }
    else{
      cout<<"stay home\n";
    }

  }

  return 0;
}
