#include <stdio.h>


int main(){
	int a,b,c,d,e,f,g,h,i;
	scanf("%d %d %d %d %d %d %d %d %d", &a, &b, &c, &d, &e, &f, &g, &h, &i);

	if(a < b && c > d && g < i && h > f){
		if(i < e || f > i && a > c || g < 2 * b - c){
			a = b;
            c = g;
            d = h;
            f = i;
		}else {
			f = i;
            a = h;
            c = e;
            e = b;
		}
	}

	printf("%d %d %d %d %d %d %d %d %d", a,b,c,d,e,f,g,h,i);
	return 0;
}
