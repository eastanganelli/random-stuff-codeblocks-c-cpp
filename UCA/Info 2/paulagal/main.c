#include <stdio.h>
#include <stdlib.h>

int recursive_fn(unsigned int val){
	unsigned int mask = 1, res=0;
	if(val!=0){
        res = val & 1;
        if (res == 0)
            return 1 + recursive_fn(val>>1);
        else
            return recursive_fn(val>>1);
	}
	else
		return 0;
}

int main(){
    unsigned int value=-1;
    printf("Ingresar valor: "); scanf("%d", &value);
    printf("El valor: %d - - - - Bits (0) ON: %d", value, recursive_fn(value));
    return 0;
}
