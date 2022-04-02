#ifndef CPERSONA_H
#define CPERSONA_H
#include <string>
/* My Libraries */
    #include <cTelefono.h>

class cPersona{
    public:
        cPersona();
        ~cPersona();
    protected:
    private:
        static const int dni;
        cTelefono Num_Telefono;
        char nombre;
        char apellido;
};

#endif // CPERSONA_H
