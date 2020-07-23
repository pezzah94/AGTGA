#include <stdio.h>


int main(){
	int i, j, k;
	scanf("%d %d %d", &i, &j, &k);

	if(i < j){
		if(j < k){
			i = k;
		}else {
			k = i;
		}
	}

	printf("%d %d %d", i, j, k);
	return 0;
}
