#include <bits/stdc++.h>
using namespace std;

int main() {
  int a;
  cin>>a;
  int h;

  while(a--){
    cin>>h;
    string idiomas[h];
    bool state = true;
    for(int i=0;i<h;i++){
      cin>>idiomas[i];
      if(i!=0 && idiomas[i] != idiomas[i-1]){
        state=false;
      }
    }
    if(state){
      cout<<idiomas[0];
    }
    else{
      cout<<"ingles";
    }
    cout<<endl;
  }

	return 0;
}
