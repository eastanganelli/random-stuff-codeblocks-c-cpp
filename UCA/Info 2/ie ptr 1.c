#include <stdio.h>
#include <stdlib.h>

int main(){
	int a=1, b=2, c=3, d=4;

	int *ptr;
	ptr=&a;
    ptr++;
	printf("%d", *ptr);

	return 0;
}