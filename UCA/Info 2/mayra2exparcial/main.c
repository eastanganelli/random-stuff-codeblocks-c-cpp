#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define  blk 1

int contar(char *str, char c)
{
    printf("%c - ", *str);
    if(*str!='\0')
    {
        if((*str)==c)
            return 1 + contar((str+1),c);
        else
            return contar((str+1),c);
    }
    else
        return 0;

}

int main()
{
    char *texto,aux;
    int i=0, rep=0, ocupado=1;
    texto=malloc(sizeof(char)*blk);
    if(texto==NULL)
        return 0;
    aux=getche();
    while(aux!='\r')
    {
        *(texto+i)=aux;
        i++;
        if(i>=ocupado)
        {
            texto=realloc(texto,sizeof(char)*(i+blk));
            ocupado=i;
        }
        aux=getche();
    }
    *(texto+i)='\0';
    printf("\n");
    rep = contar(texto,'c');
    printf("\n%c aparecio %d veces",'c', rep);
    return 0;
}
