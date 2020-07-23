#include <stdio.h>

int ostatak_sa_5(int x) {
  if(x%5 == 0)
    return 0;
  
  if(x%5 == 1 || x%5 == 3)
    return 1;
	
	if(x%5 == 2 || x%5 == 4)
    return 2;

  return 1; 
}

int main(int argc, char* argv[]) {
  int x;
  
  scanf("%d", &x);
  
  printf("%d", ostatak_sa_5(x));
  
  return 0;
}

