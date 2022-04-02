#include <stdio.h>
#include <stdlib.h>

char *cargarArreglo(){
	char *texto, caracter; int i=0, blk=10, total=blk;

	texto = malloc(sizeof(char)*100);

	caracter = getche();
	while(caracter!='\r'){
		*(texto+i) = caracter;
		printf("(%d)", i);
		i++;
		if(i>=total){
			total = total + blk;
			texto = realloc(texto, sizeof(char)*total);
			printf("\nMEMORIA\n");
		}
		caracter = getche();
	}
	texto = realloc(texto, sizeof(char)*(i+1));
	*(texto+i)='\0';
	return texto;
}

int main(){
	char *txt;
	txt=cargarArreglo();
	printf("\n%s\n", txt);

	return 0;
}
