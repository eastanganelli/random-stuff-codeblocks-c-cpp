#include<stdio.h>
#include<stdlib.h>

/* Link list node */
struct s_nodo{
    int data;
    struct node* next;
};
 typedef struct s_nodo *t_nodo;

/* Function to reverse the linked list */
void reverse(t_nodo* lista){
    t_nodo prev   = NULL;
    t_nodo current = *lista;
    t_nodo next;
    while (current != NULL)
    {
        next  = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *lista = prev;
}

void recursiveReverse(t_nodo *head_ref){
    t_nodo first;
    t_nodo rest;

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
   // first->next->next  = first;

    /* tricky step -- see the diagram */
    first->next  = NULL;

    /* fix the head pointer */
    *head_ref = rest;

}

/* Function to push a node */
void push(t_nodo *lista, int new_data){
    /* allocate node */
    t_nodo new_node = malloc(sizeof(t_nodo));

    /* put in the data  */
    new_node->data  = new_data;

    /* link the old list off the new node */
    new_node->next = (*lista);

    /* move the head to point to the new node */
    (*lista)    = new_node;
}

/* Function to print linked list */
void printList(t_nodo head){
    t_nodo temp = head;
    while(temp != NULL)
    {
        printf("%d  ", temp->data);
        temp = temp->next;
    }
}

/* Driver program to test above function*/
int main(){
    /* Start with the empty list */
    t_nodo head = NULL;

     push(&head, 20);
     push(&head, 4);
     push(&head, 15);
     push(&head, 17);
     push(&head, 85);

     printList(head);

     reverse(&head);
     printf("\n-------------------\nReversed Linked list \n");
     printList(head);

     recursiveReverse(&head);
     printf("\n-------------------\nReversed Recursive Linked list \n");
     printList(head);

}
