#include <stdio.h>
#include <stdlib.h>

/*
te dice que se recibe un nivel de un arbol
a partir de ese nivel, contar cuantos niveles tiene
*/

struct s_nodo
{
    int dato;
    struct s_nodo *izq;
    struct s_nodo *der;
};typedef struct s_nodo *t_nodoptr;
typedef struct s_nodo t_nodo;

t_nodoptr crear_nodo(int dato);
void insertar (t_nodoptr *arbol, int dato);
int inorder(t_nodoptr arbol);
void mostrar_nivel(t_nodoptr arbol,int n);
int calcular_altura(t_nodoptr arbol);
void por_niveles(t_nodoptr arbol, int high);


int main(){

    t_nodoptr arbol=NULL; int lvl=0;
    insertar(&arbol,7);
    insertar(&arbol,3);
    insertar(&arbol,8);
    insertar(&arbol,12);
    insertar(&arbol,5);
    insertar(&arbol,56);
    insertar(&arbol,9);
    printf("Ingresar nivel: ");scanf("%d",&lvl);
    por_niveles(arbol,lvl);
//    printf("\nCantidad impares: %d",inorder(arbol));
    return 0;
}
t_nodoptr crear_nodo(int dato)
{
    t_nodoptr nuevo=NULL;
    nuevo=malloc(sizeof(t_nodo));
    if(nuevo!=NULL)
    {
        nuevo->dato=dato;
        nuevo->der=NULL;
        nuevo->izq=NULL;
    }
    return nuevo;
}
void insertar (t_nodoptr *arbol, int dato)
{
    if(*arbol==NULL)
        *arbol=crear_nodo(dato);
    else if((*arbol)->dato>dato)
        insertar (&((*arbol)->izq),dato);
    else
        insertar(&((*arbol)->der),dato);
}
void por_niveles(t_nodoptr arbol, int high)
{
    int h=0,nivel=0, h_high=0;
    h=calcular_altura(arbol);
    h_high=contar_lvl_def(arbol, high);
    if(h_high==-1){
        printf("Nivel ingresado, fuera del arbol.");
        return;
    }
    printf("\nAltura(Lvl inicial: %d): %d\n", high, h_high);
    //for(nivel=0;nivel<h;nivel++)
    for(nivel=high;nivel<h;nivel++)
    {
        /*imp=imp+*/mostrar_nivel(arbol,nivel);
    }
    //printf("\n\n %d", imp);
}
int calcular_altura(t_nodoptr arbol)
{
    int izq=0,der=0;
    if(arbol==NULL)
        return;
    else{
        izq=calcular_altura(arbol->izq);
        der=calcular_altura(arbol->der);
        if(izq>der)
            return (izq+1);
        else
            return (der+1);
    }
}
int contar_lvl_def(t_nodoptr arbol,int n){
    int der=0, izq=0;
    if(arbol!=NULL){
        if(n==0)
            return calcular_altura(arbol);
        else{
            contar_lvl_def(arbol->izq,n-1);
            contar_lvl_def(arbol->der,n-1);
        }
    }else{
        return -1;
    }
}
void mostrar_nivel(t_nodoptr arbol,int n){
    int der=0, izq=0;
    if(arbol!=NULL)
    {
        if(n==0 /*&& arbol->dato%2==1*/){
            printf(" %d ",arbol->dato);
            //return 1;
        }
        else
        {
            /*izq=*/mostrar_nivel(arbol->izq,n-1);
            /*der=*/mostrar_nivel(arbol->der,n-1);
            //return der + izq;
        }
    }
}
