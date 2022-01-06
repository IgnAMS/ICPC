#include<bits/stdc++.h>
using namespace std;
int main(){
  int a,b;
  vector<int> num;
  int t=0;

  while(cin>>a>>b){
    if(a==0 && b==0) break;
    t++;
    //cout<<t<<endl;
    int cont=0;
    int t=0;
    while(a!=0 || b!=0){
      if((a==0 || b==0) && t==0) break;
      int ha=a%10;
      int hb=b%10;
      a/=10;
      b/=10;
      if(ha+hb+t>=10){
        cont++;
        t=1;
      }
      else t=0;
    }
    /*if(cont==0) printf("No carry operation.\n");
    else if(cont==1) printf("1 carry operation.\n");
    else printf("%d carry operations.\n",cont);
    */
    num.push_back(cont);

  }
  for(int i=0;i<num.size();i++){
    if(num[i]==0) printf("No carry operation.\n");
    else if(num[i]==1) printf("1 carry operation.\n");
    else printf("%d carry operations.\n",num[i]);
  }
  return 0;
}
