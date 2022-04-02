#include <stdio.h>
#include <stdlib.h>

typedef struct s_dato{
    int documento;
    char nombre[50];
}t_dato;

void funcion(t_dato *prs){
    prs->documento = 123456789;
	prs->nombre[0] = 'J';
	prs->nombre[1] = 'u';
	prs->nombre[2] = 'a';
	prs->nombre[3] = 'n';
	prs->nombre[4] = '\0';
}

int main(){
	t_dato persona;
	funcion(&persona);
	printf("Documento %d Nombre %s\n", persona.documento, persona.nombre);

	return 0;
}
