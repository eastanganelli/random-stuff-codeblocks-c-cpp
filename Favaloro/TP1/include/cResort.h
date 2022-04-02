#ifndef CRESORT_H
#define CRESORT_H
/* Const */
    #define N 40
/* My Libraries */
    #include <cTelefono.h>

class cResort {
    public:
        cResort();
        ~cResort();

        void AgregarTelefonos(int, int);

    protected:
    private:
        cTelefono PhoneNum[2];
        char nombre[N];
};

#endif // CRESORT_H
