#include <iostream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
/* My Libs */
    #include <cReserva.h>
    #include <cPersona.h>

using namespace std;

int main(){
    int dni, telefono;
    char nombre, apellido;
    cReserva lReserva;
    cPersona  *aux = NULL;
    int opcion = -1;
    while(opcion!=0) {
        printf("Agregar Reserva opcion -> 1\nQuitar Reserva opcion -> 2\nBorrar Todas las Reservas opcion -> 3\nSalir -> 0");
        scanf("%d", &opcion);
        switch(opcion) {
            case 1:
                printf("Ingresar Nombre: ");
                cin >> nombre;
                printf("Ingresar Apellido: ");
                cin >> apellido;
                printf("\Ingresar DNI: ");
                cin >> dni;
                printf("\nIngresar Telefono");
                cin >> telefono;

                //aux->cPersona(nombre, apellido, dni, telefono);

                //lReserva.AgregarReserva(&aux);
                break;
        }
    }
    return 0;
}
