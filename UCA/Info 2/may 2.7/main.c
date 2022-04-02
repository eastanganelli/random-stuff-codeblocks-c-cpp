#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct s_persona{
    int doc;
    char nombre[50],pais[50];
}per;

int main(){
    per ext[50]; int i=0, j=0, aux=-1; char l=-1;

    for(i=0; i<50 && aux!=0; i++){
        printf("Ingrese documento: ");
        scanf("%d",&aux);
        ext[i].doc=aux;

        if(aux!=0){
            printf("Ingrese nombre: ");
            l=getche();
            while(j<50 && l!='\r'){
                ext[i].nombre[j]=l;
                j++;
                l=getche();
            }
            j=0;
            l=-1;
            printf("\nIngrese pais: ");
            l=getche();

            while(j<50 && l!='\r'){
                ext[i].pais[j]=l;
                j++;
                l=getche();
            } printf("\n\n");
        }
    } return 0;
}

