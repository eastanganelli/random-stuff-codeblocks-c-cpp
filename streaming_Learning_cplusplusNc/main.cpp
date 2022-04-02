#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

int main()
{
    /*
    int temp_ = 0, switch_val = -1;
    char endChar = '\0';

    while(1) {
        cout << "Ingresar temperatura para analizar: ";
        cin>>temp_;

        if(temp_ > -25 && temp_<= 25) {
            //cout << "La temperatura esta bien!" << endl;
            if(temp_ > -25 && temp_ <= 0) switch_val = 0;
            else switch_val = 1;
        } else if(temp_ > 25 && temp_ <= 65) {
            //printf("La temperatura esta razonable\n");
            if(temp_ > 25 && temp_ <= 50) switch_val = 2;
            else switch_val = 3;
        } else switch_val = 4;

        switch(switch_val) {
            case 0: {
                cout << "Estamos subzero!!, PELIGRO DE FROSTING" << endl;
                break;
            } case 1: {
                cout << "Estamos cerca de temp ambiente" << endl;
                break;
            } case 2: {
                cout << "Sobre temperatura ambiente" << endl;
                break;
            } case 3: {
                cout << "Cerca de Chernobyl!!" << endl;
                break;
            } case 4: {
                cout << "Se viene Chernobyl" << endl;
                break;
            } default: {
                cout << "ERROR" << endl;
                break;
            }
        }
        cout << "Desea continuar?? e para salir... "; cin >> endChar;
        switch(endChar) {
            case 'e': {
                exit(0);
            } default: {

                break;
            }
        } system("cls");

    }
    */

    //15256

    //unsigned int i_val = 0; //No permite numeros <0 (Menor a cero)
    //int i = 0;

    //cout << "Ingresar un valor positivo: "; cin >> i_val;

    //while(i_val > 10) { // 11%10 = 5 => 15/10 = 1
    //    cout << i_val%10 << endl;
    //    i_val = i_val/10;
    //    i++; // i = i + 1;
    //}
    //cout << i_val << endl << "Se entro " << i << " veces al loop";

    //int i_val = -1, i = 0, flag_primo = 0;

    //do { //while(i_val > 0) => saltea por verificar al principio del loop
    //    cout << "Ingresar un valor primo y positivo ";
    //    cin >> i_val;
    //} while(i_val <= 0); // While verifica al final del loop


    //for(i=1; i<=i_val;i++) {
    //    if(i_val%i==0) flag_primo++;
    //}

    //if(flag_primo == 2) { // == equal | son iguales 5=5
    //    cout << "ES PRIMO EL VALOR " << i_val;
    //} else {
    //    cout << "NO ES PRIMO EL VALOR " << i_val;
    //}

    unsigned int i_val = 0, j=0, primos_encontrados = 0, es_primo = 0;
    cout << "Cuantos numeros primos se desea encontrar? "; cin >> i_val;

    while(primos_encontrados < i_val) {
        for(int i=1; i<=j; i++) {
            if(j%i==0) es_primo++;
        } if(es_primo==2) {
            primos_encontrados++;
            cout << "Primo encontrado nro "<< primos_encontrados << " y es el Nro " << j<< endl;
        } es_primo=0;
        j++;
    } cout << "Se encontraron " << primos_encontrados << " numeros primos";
    return 0;

    //MingW
}
