#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct{
    char texto;
}s_frase;

char *Load_Frase(){
    int i=0, blk=1, total=blk; char l, *f_texto;

    f_texto = malloc(sizeof(char)*2);

    FILE*txt_file=fopen("frase.txt","r");
    if(txt_file==NULL){
        printf("-->NO EXISTE ARCHIVO\N");
        return 0;
    }else{
        l=fgetc(txt_file);
        while(!(feof(txt_file))){
            *(f_texto+i)=l;
            i++;
            if(i>=total){
                    total = total + blk;
                f_texto = realloc(f_texto, sizeof(char)*(i+1));
            } l = fgetc(txt_file);
        }
        f_texto = realloc(f_texto, sizeof(char)*(i+1));
        *(f_texto+i)='\0';
        return f_texto;
    }free(f_texto);
}

char *subcadena(char * p, unsigned int i, unsigned int n){
    int a=0, blk=1, total=blk; char *f_mod;

    f_mod = malloc(sizeof(char)*2);
    *(f_mod+a)=*(p+i);
    for(i,a=0,n; *((f_mod+a)-1)!='\0' && n>0; i++,a++,n--){
        if(a>=total){
            total = total + blk;
            f_mod = realloc(f_mod, sizeof(char)*(a+1));
        }*(f_mod+a)=*(p+i);
    }
    f_mod = realloc(f_mod, sizeof(char)*(a-1));
    *(f_mod+a)='\0';
    return f_mod;
    free(f_mod);
}

int main(){
    s_frase *frase; int i=0, h=0; char *f_mod;

    frase = Load_Frase();
    printf("--> Frase Original: %s", frase);
    printf("--> Ingresar Posicion a Leer: \n--> ");
    scanf("%d", &i);
    printf("--> Ingresar cantidad de Caracteres a leer:\n--> ");
    scanf("%d", &h);

    f_mod = subcadena(frase,i-1,h);

    printf("--> %s", f_mod);

    return 0;
}
