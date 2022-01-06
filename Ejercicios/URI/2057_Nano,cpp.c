#include <bits/stdc++.h>
using namespace std;

int main() {
  int a,b,c;
  cin>>a>>b>>c;
  int answer=a+b+c;
  if(answer>=24){
    answer-=24;
  }
  if(answer>=24){
    answer-=24;
  }
  if(answer<0){
    answer+=24;
  }
  cout<<answer<<endl;



	return 0;
}
