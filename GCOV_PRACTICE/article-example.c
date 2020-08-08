#include <stdio.h>


int main(){
	int i, j, k;
	scanf("%d %d %d", &i, &j, &k);

	if(i < j){
		if(j < k){
			i = k;
		}else {
			k = i;
            printf("Ovo je jos neka linija da bi se popunio block!");
		}
	}

	printf("%d %d %d", i, j, k);
	return 0;
}
