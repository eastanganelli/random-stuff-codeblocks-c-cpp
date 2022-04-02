#include <stdio.h>
#include <stdlib.h>
#define N 2
#define M 2

struct s_datos
{
    int valor;
    int x;
    int y;
};
typedef struct s_datos t_datos;

struct s_nodo
{
    struct s_datos datos;
    struct s_nodo * pSig;
};
typedef struct s_nodo * t_nodo;

void push(t_nodo * , int);
int * arreglo_de_correctos(int[N][M], t_nodo *);
t_datos pop(t_nodo *);
void imprimir_pila(t_nodo*);
void imprimir(int*);

int main()
{
    t_nodo Pila=NULL;
    int Matriz[N][M], *Arre = NULL, i = 0, j = 0;
    while(i < N)
    {
        printf("Por favor ingrese un numero natural:\n");
        scanf("%d",&Matriz[i][j]);
        push(&Pila, Matriz[i][j]);
        j++;
        if(j == M)
        {
            j = 0;
            i++;
        }
    }

    printf("\nSalio!");
    imprimir_pila(&Pila);
    imprimir_pila(&Pila);
    imprimir_pila(&Pila);
    imprimir_pila(&Pila);
    // Arre = arreglo_de_correctos(Matriz, &Pila);
    //imprimir(Arre);
    //free(Pila);
    return 0;
}

void push(t_nodo * PilA, int NUM)
{
    t_nodo Nuevo = NULL;
    Nuevo = malloc(sizeof(t_nodo));
    if(Nuevo != NULL)
    {
        Nuevo->datos.valor = NUM;
        printf("Por favor ingrese dos numeros naturales:\n");
        scanf("%d %d",&Nuevo->datos.x, &Nuevo->datos.y);
        Nuevo->pSig = *PilA;
        *PilA = Nuevo;
    }
}

int * arreglo_de_correctos(int Matt[N][M], t_nodo * Pilla)
{
    t_datos Datos;
    int * Arreglo = NULL, i = 0;
    printf("\nEntro!");
    Arreglo = malloc(sizeof(int));
    if(Arreglo != NULL)
    {
        printf("\nSigue!");
        while(*Pilla != NULL)
        {
            printf("\nReconoce");
            Datos = pop(Pilla);
            printf("\nSigue!!!!");
            if(Matt[Datos.x][Datos.y] == Datos.valor)
            {
                printf("\nEntroooooo!!!!!");
                *(Arreglo + i) = Datos.valor;
                i++;
                Arreglo = realloc(Arreglo, sizeof(int)*(i + 1));
            }
            printf("\nTermino!!!");
        }
        *(Arreglo + i) = 0;
    }
    return Arreglo;
}

void imprimir_pila(t_nodo * PILA)
{
    t_datos Datos;
     printf("\nImprimiendo");
    /*while(PILA != NULL)
    {*/
        Datos = pop(PILA);
        printf("\nValor: %d, X: %d, Y: %d",Datos.valor, Datos.x, Datos.y);
    //}
}

t_datos pop(t_nodo * PILA)
{
    t_datos Num;
    Num.valor=0;
    Num.x=0;
    Num.y=0;
    if(*PILA != NULL)
    {
        t_nodo Aux = *PILA;
        Num = (*PILA)->datos;
        *PILA = (*PILA)->pSig;
        printf("\nSigue");
        free(Aux);
        printf("\nSale");
    }
    return Num;
}

void imprimir(int * A)
{
    int i = 0;
    printf("\nImprime");
    while(*(A + i) != 0)
    {
        printf("%d",*(A + i));
        i++;
    }
}
