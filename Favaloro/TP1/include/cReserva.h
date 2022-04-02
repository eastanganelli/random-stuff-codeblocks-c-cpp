#ifndef CRESERVA_H
#define CRESERVA_H
#include <stdlib.h>
#include <stdio.h>
/* My Libraries */
    #include <cPersona.h>
    #include <cResort.h>
    #include <cTelefono.h>

class cReserva{
    public:
        cReserva();
        ~cReserva();

        bool AgregarReserva(int, int);

    protected:
    private:
        void ExpandListReserva(cReserva *);
        int sizeListReservas, nowSizeReservas;
        int sizeListPersonas;
        int sizeListResorts;


        cReserva *ListaReserva = NULL;
        cPersona Person;
        cResort Resort;
        cTelefono PhoneNumb;
        int fechaYhora[5], tiempoReserva, codeReserva;

};

#endif // CRESERVA_H
