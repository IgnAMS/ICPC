#include<bits/stdc++.h>
using namespace std;
int main(){
  int a,b;
  int cont=0;
  while(cin>>a>>b){
    if(a==0 && b==0) break;
    cont++;
    double h=a*1.0/b;
    int asd=a/b;
    if (h==asd && h<=26) printf("Case %d: %d\n",cont,asd-1);
    else if(asd<=27) printf("Case %d: %d\n",cont,asd);
    else printf("Case %d: impossible\n",cont);

  }


  return 0;
}
