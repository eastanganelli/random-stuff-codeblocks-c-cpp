#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define N 100
void cargar(char []);
int es_separador(char a);
void change(char a[],char nuevo[]);
void switchPal(int ini, char a[], char newPal[], int tamSwitch);
void modTamArreglo(char a[], int ini ,int orgPal, int modPal);

int main()
{
    char arr[N]={'\0'},nueva[N]={'\0'};
    cargar(arr);
    printf("\n%s\n",arr);
    printf("\nPalabra nuevo: ");
    cargar(nueva);
    change(arr,nueva);
    printf("\n%s", arr);
    return 0;
}
void cargar(char a[])
{
    int i=0;
    char aux;
    while(aux!='\r' && i<N)
    {
        aux=getche();
        a[i]=aux;
        i++;
    }
    a[i-1]='\0';
}
int es_separador(char a)
{
    if(a=='.' || a==',' || a==' ' || a=='!' || a=='\0')
        return 1;
    else
        return 0;
}
void change(char a[],char nuevo[])
{
    int i=0, j=0, tamPal=0, tamIng=0, ini=-1, fin=0, ban=0; char pal[30]={'\0'};

    for(tamIng=-1; tamIng<N && nuevo[tamIng]!='\0'; tamIng++);
    printf("\nIngresar palabra a borrar: ");
    cargar(pal);
    for(i=0, j=0; a[i]!='\0' && i<N; i++){
        if(es_separador(a[i])!=1){
            if(a[i]==pal[j] && ban==0){
                if(ini==-1) ini=i;
                j++;
            }else if (a[i]!=pal[j]){ ban=1; }
        }else{
            if (ban!=1){
                fin=i; tamPal=fin-ini;
                modTamArreglo(a, ini, tamPal, tamIng);
                switchPal(ini,a,nuevo,tamIng);
            }
            ban=0; ini=-1; j=0;
        }
    }
    if (ban!=1){
        fin=i; tamPal=fin-ini;
        modTamArreglo(a, ini, tamPal, tamIng);
        switchPal(ini,a,nuevo,tamIng);
    }
}
void switchPal(int ini, char a[], char newPal[], int tamSwitch){
    int i=0,j=0;
    for(i=ini, j=0; i<(ini+tamSwitch) && newPal[j]!='\0'; i++,j++){
        a[i]=newPal[j];
    }
}
void modTamArreglo(char a[], int ini ,int orgPal, int modPal){
    int i=0, j=0, difMov=modPal-orgPal, fin=0;
    if(difMov<0){
        while(difMov<0){
            for(i=ini;i<N && a[i]!='\0';i++){
                a[i]=a[i+1];
            }difMov++;
        }
    }else if(difMov>0){
        for(fin=0; fin<N && a[fin]!='\0'; fin++);
        while(difMov>0){
            i=fin;
            for(i;i>ini;i--){
                a[i+1]=a[i];
            }difMov--;
        }
    }
}
