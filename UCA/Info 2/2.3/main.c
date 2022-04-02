#include <stdio.h>
#include <stdlib.h>
#define  N 9
#define  M 6
#define  L 20

typedef struct{
    int hola;

}tabla_equipos;

void cargar_tabla(tabla_equipos team){
    team.hola= 2;
    printf("%d", team.hola);
}

int main()
{
    tabla_equipos tabla;
    cargar_tabla(tabla);
    printf("%d", tabla.hola);
    return 0;
}
