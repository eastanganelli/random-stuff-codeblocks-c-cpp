#include<stdio.h>
#include<stdlib.h>

/* Link list node */
struct s_nodo{
    int data;
    struct node* next;
};
 typedef struct s_nodo *t_nodoPtr;

void recursiveReverse(t_nodoPtr *head_ref){
    t_nodoPtr first;
    t_nodoPtr rest;

    /* empty list */
    if (*head_ref == NULL)
       return;

    /* suppose first = {1, 2, 3}, rest = {2, 3} */
    first = *head_ref;
    rest  = first->next;

    /* List has only one node */
    if (rest == NULL)
       return;

    /* reverse the rest list and put the first element at the end */
    recursiveReverse(&rest);
    //first->next->next  = first;

    /* tricky step -- see the diagram */
    first->next  = NULL;

    /* fix the head pointer */
    (*head_ref) = rest;

}

/* Function to push a node */
void push(t_nodoPtr *lista, int new_data){
    /* allocate node */
    t_nodoPtr new_node = malloc(sizeof(t_nodoPtr));

    /* put in the data  */
    new_node->data  = new_data;

    /* link the old list off the new node */
    new_node->next = (*lista);

    /* move the head to point to the new node */
    (*lista)    = new_node;
}

/* Function to print linked list */
void printList(t_nodoPtr *head){
    if((*head)==NULL)return;
    else{
        printf("%d ", (*head)->data);
        printList(&((*head)->next));
    }
}

/* Driver program to test above function*/
int main(){
    /* Start with the empty list */
    t_nodoPtr head = NULL;

    push(&head, 20);
    push(&head, 4);
    push(&head, 15);
    push(&head, 17);
    push(&head, 85);

    printList(&head);

    recursiveReverse(&head);
    printf("\n-------------------\nReversed Recursive Linked list \n");
    printList(&head);
}
