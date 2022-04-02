#include <stdio.h>
#include <stdlib.h>

int main(){
    unsigned int val = 19950531, mask=1; int i=0, c = 0, mes=0, dia=0, anio=0;
    for(i=0;i<8;i++){
        dia=dia+(val&mask)*pow(10,i);
        val=val>>1;
    }
    for(i=0;i<8;i++){
        mes=mes+(val&mask)*pow(10,i);
        val=val>>1;
    }
    for(i=0;i<16;i++){
        anio=anio+(val&mask)*pow(10,i);
        val=val>>1;
    }
    printf("\n%d %d %d", dia, mes, anio);
    return 0;
}
