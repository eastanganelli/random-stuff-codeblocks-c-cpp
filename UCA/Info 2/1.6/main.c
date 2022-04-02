#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 5
#define M 20
#define O 8
void cargar_equipos(unsigned char ma[N][M],    unsigned int pun[N][O]);
void cargar_puntos(unsigned int pun[N][O]);
void imprimir(char ma[N][M]);
void imprimir_puntos(unsigned int pun[N][O]);
int main()
{
    unsigned char ma[N][M]= {'\0'};
    unsigned int pun[N][O];
    printf("Equipo\t\t PTS   PJ   PG   PE   PP   GF   GC   DFG\n");
    printf("----------------------------------------------------------\n");
    cargar_equipos(ma,pun);
    imprimir(ma);
    cargar_puntos(pun);
    imprimir_puntos(pun);
    return 0;

}
void cargar_puntos(unsigned int r[N][O])
{
    int f=0;
    FILE * archi=fopen("puntos.txt","r");
    if(archi==NULL)
        printf("\Error");
    else
    {

        while(!feof(archi) && f<5)//mientras que la funcion feof aplicada a arch me devuelva falso, osea que no llego al end of file voy a hacer que siga leyendo el archivo
        {
            fscanf(archi,"%d,%d,%d,%d,%d,%d,%d,%d",&r[f][0],&r[f][1],&r[f][2],&r[f][3],&r[f][4],&r[f][5],&r[f][6],&r[f][7]);
            printf("%d |    %d |    %d |    %d |    %d |    %d |    %d |    %d\n",r[f][0],r[f][1],r[f][2],r[f][3],r[f][4],r[f][5],r[f][6],r[f][7]);
            f++;
        }
    }
            fclose(archi);

}

void imprimir_puntos(unsigned int r[N][8])
{
    int f=0;

    for(f=0; f<N; f++)
    {

        printf("%d |    %d |    %d |    %d |    %d |    %d |    %d |    %d\n",r[f][0],r[f][1],r[f][2],r[f][3],r[f][4],r[f][5],r[f][6],r[f][7]);
    }
}

void cargar_equipos(unsigned char ma[N][M],    unsigned int r[N][O])
{
    int i=0,j=0,leido, f=0;
    FILE*arch=fopen("equipos.txt","r");
    FILE*archi=fopen("puntos.txt","r");

    if(archi==NULL)
        printf("\Error");
    else if(arch==NULL)
        printf("\nError en apertura");
    else
    {
        leido=fgetc(arch);

        while(leido!=EOF && f<5)
        {

            ma[i][j]=leido;
            printf("%c",ma[i][j]);
            leido=fgetc(arch);

            if(leido=='\n')
            {
                printf("\t\t");
                fscanf(archi,"%d,%d,%d,%d,%d,%d,%d,%d",&r[f][0],&r[f][1],&r[f][2],&r[f][3],&r[f][4],&r[f][5],&r[f][6],&r[f][7]);
                printf("   %d |    %d |    %d |    %d |    %d |    %d |    %d |    %d\n",r[f][0],r[f][1],r[f][2],r[f][3],r[f][4],r[f][5],r[f][6],r[f][7]);
                f++;
            }

        }
    }
    ma[i][0]='\0';


    fclose(arch);
    fclose(archi);
}
void imprimir(char ma[N][M])
{
    int i;
    printf("\n");


    printf("%s\n",ma[i]);

}
