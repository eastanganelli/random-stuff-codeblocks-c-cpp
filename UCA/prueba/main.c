#include <stdio.h>
#include <stdlib.h>

//void foo(int **p);
//
//int main(){
//    int i=97, *p=&i;
//    foo(&p);
//    printf("%d", *p);
//    return 0;
//}
//
//void foo(int **p){
//    int j=2;
//    *p=&j;
//    printf("%d", **p);
//}
//void foo(int *);
//
//int main(){
//   int i=10;
//   foo((&i)++);
//   return 0;
//}
//
//void foo(int *p){
//    printf("%s\n", *p);
//}

void *load_arr(int *arr){
    arr = malloc(sizeof(int)*5);
    *(arr+0)=1;
    *(arr+1)=2;
    *(arr+2)=3;
    *(arr+3)=0;
    return arr;
}
void print(int *arr){
    int i=0;
    while((*(arr+i))!=0){
        printf("%d-", *(arr+i));
        i++;
    }
}

int main(){
    int arr;
    arr = load_arr(&arr);
    print(arr);
    return 0;
}
