#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#define  BLK 1

struct s_nodo{
    char *txt;
    struct s_nodo *pSig;
};
typedef struct s_nodo t_nodo;
typedef struct s_nodo* t_nodoPtr;

t_nodoPtr create_nodo(char *dato){
    t_nodoPtr pNuevo=NULL;
    pNuevo = malloc(sizeof(t_nodo));
    if(pNuevo!=NULL){
        (*pNuevo).txt = malloc(sizeof(dato));
        strcpy((*pNuevo).txt,dato);
        pNuevo->pSig=NULL;
    }return pNuevo;
}

char *load_word(char *lWord){
    char aux; int i=0, ocupied=BLK;

    lWord = malloc(sizeof(char));
    if(lWord==NULL){
        printf("\nNo se pudo crear el arreglo.");
        return NULL;
    }
    aux = getche();
    while(aux != ' '){
        *(lWord+i) = aux;
        i++;
        if(i >= ocupied){
            lWord = realloc(lWord,sizeof(char)*(i+BLK));
            ocupied = i;
        }
        aux = getche();
    } *(lWord+i) = '\0';
    return lWord;
}
/*
void enqueue(t_nodoPtr *pLista, char *pWord){
    if(pLista==NULL){
        *pLista = create_nodo(pWord);
        (*pLista)->pSig = NULL;
    }
    else{
        pWord = load_word(&pWord);
        enqueue(&(*pLista)->pSig, *pWord);
    }
}*/

void push(t_nodoPtr *pLista, char *pWord){
    t_nodoPtr pNuevo = create_nodo(pWord);
    if(pNuevo!=NULL){
        pNuevo->pSig = *pLista;
        *pLista = pNuevo;
    }
}

void filtrar_palabras(int vLimit, t_nodoPtr pLista){

}

void print_txt(t_nodoPtr pLista){
   if(pLista!=NULL){
        print_txt(pLista->pSig);
        mostrarPalabra(pLista->txt);

   }
}
void mostrarPalabra(char *palabra){
    int i;
    for(i=0;*(palabra+i)!='\0';i++){
        printf("%c",*(palabra+i));
    }
    printf(" ");
}

int main(){
    t_nodoPtr pLista=NULL;
    char *word;

    printf("\nCargar Palabra: ");
    word = load_word(&word);
    push(&pLista, word);
    word = load_word(&word);
    push(&pLista, word);
    word = load_word(&word);
    push(&pLista, word);
    word = load_word(&word);
    push(&pLista, word);
    word = load_word(&word);
    push(&pLista, word);
    word = load_word(&word);
    push(&pLista, word);
    printf("\n");
    print_txt(pLista);
    return 0;
}
