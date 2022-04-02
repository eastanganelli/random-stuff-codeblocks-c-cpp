#include <stdio.h>
   #include <stdlib.h>

   struct s_nodo{
      int dato;
      struct s_nodo *pSig;
      struct s_nodo *pAnt;
   };typedef struct s_nodo t_nodo;
   typedef struct s_nodo* t_nodoPtr;

   t_nodoPtr crear_nodo(int dato){
      t_nodoPtr pnuevo=NULL;
      pnuevo=malloc(sizeof(t_nodo));
      if(pnuevo!=NULL){
         pnuevo->dato=dato;
         pnuevo->pSig=NULL;
         pnuevo->pAnt=NULL;
      }return pnuevo;
   }
   /* Get Pointers of Ending and Beginning */
      t_nodoPtr get_PtrFirstNode(t_nodoPtr pLista){
         if(pLista != NULL) return pLista;
      }
      t_nodoPtr get_PtrLastNode(t_nodoPtr pLista){
         if(pLista != NULL) return pLista;
         else get_PtrLastNode(pLista->pSig);
      }
   /* Insert Nodes */
      void insert_order(t_nodoPtr *pLista,int dato){
         if(*pLista==NULL) *pLista=crear_nodo(dato);
         else if(dato<(*pLista)->dato){
            t_nodoPtr pNuevo = crear_nodo(dato);
            if(pNuevo!=NULL){
               pNuevo->pSig=*pLista;
               pNuevo->pAnt=(*pLista)->pAnt;
               (*pLista)->pAnt=pNuevo;
               (*pLista)=pNuevo;
            }
         }else if((*pLista)->pSig==NULL){
            t_nodoPtr pNuevo=crear_nodo(dato);
            if(pNuevo!=NULL){
               pNuevo->pAnt=*pLista;
               (*pLista)->pSig=pNuevo;
            }
         }else insert_order(&((*pLista)->pSig),dato);
      }
   /* Del Node and Clear List */
      void vaciar_lista(t_nodoPtr *pLista){
         if((*pLista)==NULL) return;
         else{
            vaciar_lista(&((*pLista)->pSig));
            free(*pLista);
            (*pLista)=NULL;
         }
      }
      int eliminar_nodo(t_nodoPtr *pLista/*, int val*/){
         if((*plista)->dato==dato){
            t_nodoPtr pAux=*pLista;
            (*pLista)=(*pLista)->pSig;
            ((*pLista)->pSig)->pAnt=(*pLista);
            (*pLista)->pAnt=pAux->pAnt;
            (pAux->pAnt)->pSig=(*pLista);
            free(pAux);
         }
      }
   /* Print Lists Modes */
      void print_list_back(t_nodoPtr pLista){
         /*Back to Front*/
         if(pLista==NULL) return;
         else{
            print_list_back(pLista->pSig);
            printf("%d", pLista->dato);
         }
      }
      void print_list_front(t_nodoPtr pLista){
         /*Front to Back*/
         if(pLista==NULL) return;
         else{
            printf("%d", pLista->dato);
            print_list_front(pLista->pSig);
         }
      }
   int main(){
      t_nodoPtr lista=NULL, PtrBegin, PtrEnd; int val=0;

      insert_order(&lista,1);
      insert_order(&lista,21);
      insert_order(&lista,13);
      insert_order(&lista,31);
      insert_order(&lista,51);
      PtrBegin = get_PtrFirstNode(lista);
      PtrEnd = get_PtrLastNode(lista); /* Teniendo el puntero del ultimo Nodo, me habilita de Leer desde atras como escribir a la ultimo
      sin tener que recorrer toda la Lista (crear una función similar a enqueue, pero que solo reciba el ultimo & del nodo y devuelva el nuevo & del Ptr ultimo
      (devuelve la dirreción del NULL, o sea, pLista->pSig) de la Lista) */
      eliminar_nodo(&lista,13); // Elimino Nodo con ese valor
      print("\nPrint List from Back To Front -> \n");
      print_list_back(lista);
      print("\nPrint List from Front To Back -> \n");
      print_list_front(lista);
      /* FNs de print puedo utilizar la & del ultimo noda para imprimir desde atras,
      asi no recurrir a imprimir como hace print_list_back(fn util para Lists SimpleLink), ya que estamos usando una List DobleLink */
      vaciar_lista(&lista);
      return 0;
   }
