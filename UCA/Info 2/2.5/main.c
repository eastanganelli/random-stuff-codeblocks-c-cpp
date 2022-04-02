#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define N 50

struct s_persona
{
    char nombre[N];
    char pais[N];
    int documento;
};
typedef struct s_persona persona;

void load_data(persona per[N]){
    int i=0, aux=-1, j=0, k=0, regit=0, m=0, no_repeat=0; char auxape, auxnom;
    for(i=0;i<N || aux!=0;i++){
        int flag=0;
        printf("Ingrese documento: ");
        while(aux!=0 && flag==0){
            scanf("%d",&aux);

            no_repeat=0;
            for(m=0; m<i; m++){
                if(per[m].documento==aux){
                    no_repeat++;}
            }

            if((aux>1000000 || aux<=-1) && aux!=0 || no_repeat!=0){
                printf("\nIngresar denuevo documento: ");}
            else{
                per[i].documento=aux;
                flag=1;
            }
        }
        if(aux==0)
            if(i==0) return 0;
            else break;
        else{
            char l='\0'; j=0;

            printf("Ingrese nombre: ");
            while(j<N && l!='\r'){
                l=getche();
                per[i].nombre[j]=l;
                j++;
            }

            if (l=='\r'){
                per[i].nombre[j-1]='\0';
                l='\0';}
            j=0;
            printf("\nIngrese pais: ");
            while(j<N && l!='\r'){
                l=getche();
                per[i].pais[j]=l;
                j++;
            }
            if (l=='\r'){
                per[i].pais[j-1]='\0';
                l='\0';}
            regit++;
            printf("\n--------\n");
        }
    }print_file_screen(per, regit);
}

void read_file(persona per[N]){
    int i=0;
    FILE*datos=fopen("datos.txt","r");
    if(datos==NULL){
        printf("Error al abrir el archivo");
        return 0;
    }
    while(fscanf(datos,"%d %s %s", &per[i].documento, &per[i].pais, &per[i].nombre)!=-1 && i<N){
        fscanf(datos,"%d %s %s\n", &per[i].documento, &per[i].pais, &per[i].nombre);
        i++;
    }
    fclose(datos);
    print_file_screen(per, i);
}

void print_file_screen(persona per[],int regit){
    int i;
    printf("\n------------------------------------------------------\n");
    /*FILE*datos=fopen("datos.txt","w");
    if(datos==NULL){
        printf("Error al abrir el archivo");
        return 0;
    }*/

    for(i=0;i<regit;i++){
        printf("\nDocumento: %d",per[i].documento);
        printf("\nPais: %s",per[i].pais);
        printf("\nNombre: %s",per[i].nombre);
        printf("\n");
        //fprintf(datos, "%d %s %s\n", per[i].documento,per[i].pais,per[i].nombre);
    }
    //fclose(datos);
}

int main(){
    persona per[N]; int selection=0;
    printf("Si desea Cargar datos desde:\nArchivo --> '1'\nTeclado --> '2'\n");
    while(selection!=1 && selection!=2){
        printf("--> ");
        scanf("%d",&selection);
        if(selection!=1 && selection!=2){
            printf("Seleccione opcion, Por favor!");
        }
    }
    if(selection==2)
        { load_data(per); }
    else if (selection==1)
    { read_file(per); }
    return 0;
}
