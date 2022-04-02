#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int a, b;
}t_dosint;

void cambiar(t_dosint *var,t_dosint*var1);
int main()
{
    t_dosint dos;
    dos.a=3;
    dos.b=5;
    cambiar(&dos.a,&dos.b);
    printf("a:%d  b:%d",dos.a,dos.b);
    return 0;
}
void cambiar(t_dosint *var,t_dosint *var1)
{
    t_dosint aux;

    aux=*var;
    *var=*var1;
    *var1=aux;
}
