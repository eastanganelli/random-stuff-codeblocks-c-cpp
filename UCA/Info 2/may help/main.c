#include <stdio.h>
#include <stdlib.h>
#define N 6

void cargar(int [N][8]);
void imprimir(int [N][8]);

int main()
{
    int torneo[N][8] = {0};
    cargar(torneo);
    imprimir(torneo);
    return 0;
}

void cargar(int r[N][8])
{
    FILE*arch = fopen("puntos.txt","r");
    int f=0;
    if(arch==NULL)
    {
        printf("Error en la apertura...");
        fclose(arch);
        return 0;
    }

    while(!feof(arch) && f<N-1) //mientras que la funcion feof aplicada a arch me devuelva falso, osea que no llego al end of file voy a hacer que siga leyendo el archivo
     {
         fscanf(arch,"%d %d %d %d %d %d %d %d\n",&r[f][0],&r[f][1],&r[f][2],&r[f][3],&r[f][4],&r[f][5],&r[f][6],&r[f][7]);
         f++;
     }
     fclose(arch);
}

void imprimir(int r[N][8])
{
    int f=1;
    for(f=0;f<N-1;f++)
    {
        printf("%d - %d - %d - %d - %d - %d - %d - %d\n",r[f][0],r[f][1],r[f][2],r[f][3],r[f][4],r[f][5],r[f][6],r[f][7]);
    }
}
