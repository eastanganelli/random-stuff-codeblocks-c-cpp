#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 5
#define M 20
#define O 8
#define SizeSpace 13

void cargar_equipos(char ma[N][M], unsigned int r_[N][O]){
    int space_move=0,m=0, aux,i=0, j=0, leido;
    FILE*arch=fopen("\equipos.txt","r");
    if(arch==NULL)
        printf("Error en apertura");
    else{
        while(leido!=EOF){
            leido=fgetc(arch);
            ma[i][j]=leido;
            if(leido!='\n'){
                printf("%c",ma[i][j]);
                space_move++;
            }
            if(leido=='\n'){
                if ((SizeSpace-space_move)!=0){
                    for(m=(SizeSpace-space_move); i>0; m--){
                        printf(" ");
                    }
                }
                i++;
                ma[i][j]='\0';
                cargar_puntos(r_, i);
            }
        }
        ma[i][0]='\0';
    }
    fclose(arch);
}

void cargar_puntos(int r_i[N][O], int height){
    int f=height;

    FILE * archi=fopen("\puntos.txt","r");
    if(archi==NULL)
        printf("\Error");
    else{
        fscanf(archi,"%d %d %d %d %d %d %d %d",&r_i[f][0],&r_i[f][1],&r_i[f][2],&r_i[f][3],&r_i[f][4],&r_i[f][5],&r_i[f][6],&r_i[f][7]);
        printf("\t      %d |        %d |        %d |        %d |        %d |        %d |        %d |        %d\n", r_i[f][0], r_i[f][1], r_i[f][2], r_i[f][3], r_i[f][4], r_i[f][5], r_i[f][6], r_i[f][7]);
        fclose(archi);
    }
}

int main(){
    char ma[N][M]= {'\0'};
    unsigned int pun[N][O];
    printf("Equipo\t\t      PTS        PJ         PG         PE         PP         GF         GC         DFG\n");
    printf("-------------------------------------------------------------------------------------------------------\n");
	cargar_equipos(ma, pun);
	system("pause");
    return 0;
}
