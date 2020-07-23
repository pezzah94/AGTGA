#include <stdio.h>

int main(){

  int x,y,z,t;  

  scanf("%d %d %d %d", &x, &y, &z, &t);

  if(x<y)
    printf("x: %d", x);
  else
    printf("y: %d", y);

  if(z<t){
    while(z<y){
      printf("z: %d", z);
      z++;
    }
  }else {
    while(t<x){
      printf("t: %d", t);
      t++;
    }
  }
  return 0;
}
