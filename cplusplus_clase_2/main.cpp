#include <iostream>
#include <stdio.h>

using namespace std;

#define N 100

int agregar_a_tabla(int pos, int valor, int tabla[N][2]);

int main() {
    // 0<N<100
    //unsigned int i_val = 0, j=0, primos_encontrados[N] = {0}, h=0, es_primo = 0;
    //cout << "Cuantos numeros primos se desea encontrar? (Maximo " << N << ") "; cin >> i_val;
    //while(i_val > N) {
    //    cout << "Por favor, ingresar un valor menor a " << N << ", nuevamente.. "; cin >> i_val;
    //}

    //while(h < i_val && h < N) {
    //    for(int i=1; i<=j; i++) //5<=5
    //        if(j%i==0) es_primo++;
    //    if(es_primo==2) {
    //        primos_encontrados[h] = j;
    //        h++;
    //    }
    //    es_primo=0;
    //    j++;
    //} if(h<i_val) primos_encontrados[h+1] = 0; //Usamos 0 como terminador del arreglo al imprimir
    //printf("Se encontraron %d numeros primos\n", h);
    //for(int i=0; i<N && primos_encontrados[i]!=0; i++)
    //    printf("Posicion: %d - Valor: %d\n", i, primos_encontrados[i]);

    //MCM (Minimo Comun Multiplo)
    int i_val = -1, aux = -1;
    int valores[N][2], i_=0; //En la columna 0 => lo valores (osea, la i) :::: en la columna 1 => los valores exponenciales (osea, la cantidad de veces que se repita el valor)
    bool is_finish = true, flag_kill = false;

    cout << "Ingreso un valor para hallar MCM: ";
    cin >> i_val;
    aux = i_val; //26
    while(is_finish) { //! => lo convierte a algo distinto, por ejemplo !true = false
        for (int i=2; i <= aux; i++) { //NUNCA DIVIDIR CON CERO
            if(aux%i==0) {
                aux=aux/i;
                i_ = i_ + agregar_a_tabla(i_, i, valores);
                break;
            }
        }
        if(aux <= 1) is_finish = false;
    }
    printf("El valor %d tiene como MCM a: ", i_val);
    for (int i = 0; i < (i_-1); ++i) {
        printf("%d^%d", valores[i][0], valores[i][1]);
        if(i+1<(i_-1)) printf("x");
    }
    return 0;
}

int agregar_a_tabla(int pos, int valor, int tabla[N][2]) {     // void agregar_a_tabla(int pos, int valor, int tabla[N][2]) ==> Void no retorna NADA;
	for(int i=0; i<=pos; i++) {
		if(tabla[i][0]==valor) {
			int auxSum = tabla[i][1];
			tabla[i][1] = auxSum++;
			return 0;
		} else {
			tabla[i][0] = valor;
			tabla[i][1] = 1;
			return 1;
		}
	} return 0;
}
