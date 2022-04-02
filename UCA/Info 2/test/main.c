#include <stdio.h>
#include <stdlib.h>

int factorial(int valor){
	if(valor<=0){ return 1; }
	else{ return valor*factorial(valor-1); }
}

int main(){

	printf("%d", factorial(5));

	return 0;
}
