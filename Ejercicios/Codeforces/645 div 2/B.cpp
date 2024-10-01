#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  int t;
  cin>>t;
  while(t--){
    cin>>n;
    vector<int> vec(n);
    for(int i=0;i<n;i++) cin>>vec[i];
    sort(vec.begin(),vec.end());
    int low=0;
    int cont=1;
    int acum=0;
    for(int i=0;i<vec.size();i++){
        acum++;
      //printf("hay %d abuelitas\n",acum+cont-1);
      if(acum+cont-1>=vec[i]){
        cont+=acum;
        acum=0;
      }
      /*if(i==low){
        printf("hay %d abuelitas afuera, la abuelita %d entra si hay %d abuelitas\n",i-low+cont,i,vec[i]);
        if(cont+i-low>=vec[i]){
          printf("entraron %d abuelitas\n",acum);
          cont+=acum;
          acum=0;
          low=i;
        }
      }
      else{
        printf("hay %d abuelitas afuera, la abuelita %d entra si hay %d abuelitas\n",i-low+cont-1,i,vec[i]);
        if(i-low+cont-1>=vec[i]){
          printf("entraron %d abuelitas\n",acum);
          cont+=acum;
          acum=0;
          low=i;
        }
      }
      */


    }
    cout<<cont<<endl;
  }


  return 0;
}
