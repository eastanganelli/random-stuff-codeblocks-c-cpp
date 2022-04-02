#include <stdio.h>
#include <stdlib.h>

int alcanza(int numero, int cant)
{
	int limite;
	limite=pow(numero,cant); //no tengo idea que hacer
	if(limite<=cant)
		return 1;
	else
		return 0;
}

int main()
{
    printf("%d",alcanza(2,2));
    return 0;
}
