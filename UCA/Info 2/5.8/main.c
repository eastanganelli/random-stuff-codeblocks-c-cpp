#include <stdio.h>
#include <stdlib.h>

struct s_nodo{
    int dato;
    struct s_nodo *pSig;
    struct s_nodo *pAnt;
};
typedef struct s_nodo t_nodo;
typedef struct s_nodo* t_nodoPtr;

t_nodoPtr crear_nodo(int dato);
void insert_order(t_nodoPtr *pLista,int dato);
void print_list(t_nodoPtr nodo);

int main(){
    t_nodoPtr lista=NULL;

    insert_order(&lista,1);
    insert_order(&lista,3);
    insert_order(&lista,5);
    insert_order(&lista,7);
    print_list(lista);
    return 0;
}

t_nodoPtr crear_nodo(int dato){
    t_nodoPtr pnuevo=NULL;
    pnuevo=malloc(sizeof(t_nodo));
    if(pnuevo!=NULL){
        pnuevo->dato=dato;
        pnuevo->pSig=NULL;
        pnuevo->pAnt=NULL;
    }   return pnuevo;
}

void insert_order(t_nodoPtr *pLista,int dato){
    if(*pLista==NULL)   *pLista=crear_nodo(dato);
    else if(dato<(*pLista)->dato){
        t_nodoPtr pNuevo = crear_nodo(dato);
        if(pNuevo!=NULL){
            pNuevo->pSig=*pLista;
            pNuevo->pAnt=(*pLista)->pAnt;
            (*pLista)->pAnt=pNuevo;
            (*pLista)=pNuevo;
        }
    }
    else if((*pLista)->pSig==NULL){
        t_nodoPtr pNuevo=crear_nodo(dato);
        if(pNuevo!=NULL){
            pNuevo->pAnt=*pLista;
            (*pLista)->pSig=pNuevo;
        }
    }
    else    insert_order(&((*pLista)->pSig),dato);
}

void print_list(t_nodoPtr nodo){
    while(nodo!=NULL){
        printf("%d - ",nodo->dato);
        nodo=nodo->pSig;
    }
}
