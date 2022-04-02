#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

typedef struct{
    char *txt;
    unsigned int longitud;
}
t_texto;

void cargar(t_texto *textoptr){
    int i=0, blk=1, total=blk; char l, *f_texto,j=0;

    f_texto = malloc(sizeof(char)*2);

    l=getche();
    while(l!='\r' && i<10){
        *(f_texto+i)=l;
        i++;
        if(l==' ')
            j++;
        if(i>=total){
                total = total + blk;
            f_texto = realloc(f_texto, sizeof(char)*(i+1));
        } l = getche();
    }

    f_texto = realloc(f_texto, sizeof(char)*(i+1));
    *(f_texto+i)='\0';

    textoptr->txt = malloc(sizeof(char)*i);
    textoptr->longitud=i-j;
    strcpy(textoptr->txt,f_texto);
    free(f_texto);
}


int main()
{
    t_texto text;

    cargar(&text);
    printf("\n--> Frase: %s    Longitud: %d", text.txt,text.longitud);
    return 0;
}
