/*#include <stdio.h>
#include <stdlib.h>

char* cargarfrase(){
    char* arr; int i=0; char letra;
    arr= malloc(sizeof(char));
    printf("ingrese frase: ");
    letra=getche();
    while(letra!='\r'){
        //
        *(arr+i)=letra;
        i++;
        arr = realloc(arr,sizeof(char)*(i+1));
        //
        letra=getche();
    } *(arr+i)='\0';
    return arr;
}

int main(){
    char* phrase;
    phrase = cargarfrase();
    printf("\n%s", phrase);
    printf("Hello world!\n");
    return 0;
}*/

#include <stdio.h>
#include <stdlib.h>

struct s_tree{
    int dato;
    struct s_tree *izq;
    struct s_tree *der;
};typedef struct s_tree t_tree;
typedef struct s_tree* t_treePtr;

t_treePtr create_tree(int dato);
void insert_tree(t_treePtr *tree, int dato);


int contarNiveles(t_treePtr pTree){
    int izq, der;
    if(pTree!=NULL){
        izq = contarNiveles(pTree->izq);
        der = contarNiveles(pTree->der);
        if(izq>der){ return 1 + izq; }
        else { return 1 + der; }
    } else { return 0; }
}

int main(){
    t_treePtr tree=NULL;
    insert_tree(&tree, 1);
    insert_tree(&tree, 2);
    insert_tree(&tree, 3);
    insert_tree(&tree, 4);
    printf("\nLvl -> %d",contarNiveles(tree));
    return 0;
}

t_treePtr create_tree(int dato){
    t_treePtr tNuevo=NULL;
    tNuevo = malloc(sizeof(t_tree));
    if(tNuevo!=NULL){
        tNuevo->dato=dato;
        tNuevo->izq=NULL;
        tNuevo->der=NULL;
    } return tNuevo;
}

void insert_tree(t_treePtr *tree, int dato){
    if(*tree==NULL)
        *tree=create_tree(dato);
    else{
        if(dato<(*tree)->dato)
            insert_tree(&((*tree)->izq), dato);
        else if (dato>(*tree)->dato)
            insert_tree(&((*tree)->der), dato);
    }
}
