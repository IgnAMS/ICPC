#include <iostream>
using namespace std;

int main() {
  int Matrix[5][5];
  int posX, posY;

  for(int i=0;i<5;i++){
    for(int j=0;j<5;j++){
      cin>>Matrix[i][j];
      if(Matrix[i][j]==1){
        posX=j+1;
        posY=i+1;
      }
    }
  }
  posX= abs(3-posX);
  posY= abs(3-posY);
  int suma= posX+posY;
  cout<<suma<<endl;


	return 0;
}
