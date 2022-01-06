  #include<bits/stdc++.h>
  using namespace std;
  int main(){
    int n,c;
    cin>>n>>c;
    deque<int> asd;
    int last;
    int cont=0;
    int h;
    for(int i=0;i<n;i++){
      last=h;
      cin>>h;
      if(i>0){
        //cout<<h<<" "<<last<<endl;
        if(h-last>c){
          cont=0;
        }
      }
      cont++;
    }
    cout<<cont<<endl;

    return 0;
  }
