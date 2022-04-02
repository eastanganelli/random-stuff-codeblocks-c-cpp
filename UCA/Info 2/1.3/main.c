#include <stdio.h>
#include <stdlib.h>
#define  N 30
#define  M 20

void lectArch(char teams[N][M]){
    FILE*arch; arch=fopen("equipos.txt","r"); int val, i=0,r=0;
    if(arch!=NULL){
        //printf("Hay lectura!!!\n");
        while(!(feof(arch))){
            r=0;
            fscanf(arch,"%c",&val);
            //printf("%c", val);
            while(feof(arch) && val!='\n'){
                teams[i][r]=val; i++;
                fscanf(arch,"%c",&val);
                //printf("Hay lectura!!!\n");
            }
            if(val=='\n'){teams[i][r]='\0'; r++;}
            fscanf(arch,"%c",&val);
        }
        fclose(arch);
    }
}

void lectArr(char teams[N][M]){
    int i=0,r=0;
    for (r = 0; r < M; r++) {
        for (i = 0; i < N; i++) {
            //grid[i][r] = '.';
            printf("%c ", teams[i][r]);
        }printf("\n");
    }
}

int main()
{   char equipos[N][M];
    lectArch(equipos);
    //lectArr(equipos);
    return 0;
}
