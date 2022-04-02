#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 5
#define M 20
#define O 8
#define SizeSpace 13

void cargar_equipos(char ma[N][M], int r[N][O]){
    int space_move=0,m=0,aux,i=0, j=0, leido;
    FILE*arch=fopen("equipos.txt","r");
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
                    for(m=(SizeSpace-space_move); m>=0; m--){
                        printf(" ");
                    }
                    space_move=0;
                }
                ma[i][j]='\0';
                print_points(r,i);
                i++;
            }
        }
        ma[i][0]='\0';
    }
    fclose(arch);
}

void cargar_puntos(int r[N][8]){
    FILE*arch = fopen("puntos.txt","r");
    int f=0;
    if(arch==NULL){
        printf("Error en la apertura...");
        return 0;
    }
    else{
        while(!feof(arch) && f<N){//mientras que la funcion feof aplicada a arch me devuelva falso, osea que no llego al end of file voy a hacer que siga leyendo el archivo
             fscanf(arch,"%d %d %d %d %d %d %d %d",&r[f][0],&r[f][1],&r[f][2],&r[f][3],&r[f][4],&r[f][5],&r[f][6],&r[f][7]);
             f++;
        }
    }
    fclose(arch);
}


void print_points(int r[N][O], int height){
    int i;
    printf("\t");
    for(i=0; i<O; i++){
        if(r[height][i]>9){
            printf("%d         ", r[height][i]);
        }
        else{
            printf("%d          ", r[height][i]);
        }
    }
    printf("\n");
}

int main(){
    char ma[N][M]= {'\0'};
    int pun[N][O];
    cargar_puntos(pun);
    printf("Equipo\t        PTS        PJ         PG         PE         PP         GF         GC         DFG\n");
    printf("-------------------------------------------------------------------------------------------------\n");
    cargar_equipos(ma, pun);
    return 0;
}