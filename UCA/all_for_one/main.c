#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <math.h>

struct habitantes {
    int ID_habitante, edad;
    char nombre[200], sexo;
};typedef struct habitantes t_habitantes;
typedef t_habitantes* t_habitantesPtr;

struct localidades {
    int ID_localidad, ID_zona;
    char nombre[200];
};typedef struct localidades t_localidades;
typedef t_localidades* t_localidadesPtr;

struct habitantesxlocalidad {
    int ID_localidad, ID_habitante;
};typedef struct habitantesxlocalidad t_habitantesxlocalidad;
typedef t_habitantesxlocalidad* t_habitantesxlocalidadPtr;

struct datos_habxloc {
    t_habitantesxlocalidad cantHabitantes;
    struct datos_habxloc* pSig;
};typedef struct datos_habxloc t_datos_habxloc;
typedef t_datos_habxloc* t_datos_habxlocPtr;

t_datos_habxlocPtr crear_nodo_habxloc(t_habitantesxlocalidad datos){
    t_datos_habxlocPtr pNuevo = NULL;
    pNuevo = malloc(sizeof(t_datos_habxloc));
    if(pNuevo != NULL) {
        pNuevo->cantHabitantes = datos;
        pNuevo->pSig = NULL;
        return pNuevo;
    }
}
void qeue(t_datos_habxlocPtr *habXloc) {
    if((*habXloc) == NULL) {
//        *habXloc = crear_nodo_habxloc(dato);
        return;
    } else { qeue(&((*habXloc)->pSig)); }
}
void load_files(t_habitantesPtr *hab_datos, t_localidadesPtr *loc_datos, t_habitantesxlocalidadPtr *habxloc_datos) {
    int i=0;
    printf("Ingresar datos de habitantes al archivo -> ");

}
void load_vars(t_habitantesPtr hab_datos, t_localidadesPtr loc_datos, t_datos_habxlocPtr *habxloc_datos) {
    int i=1, blk=1;
//    FILE*arch_hab=fopen('habitantes.dat','rb');
    FILE*arch_loc=fopen("localidades.txt","rw");
    FILE*arch_habXloc=fopen("habitantesXlocalidad.txt","rw");

//    hab_datos = malloc(sizeof(t_habitantes)*1);
    loc_datos = malloc(sizeof(t_localidades)*1);

//    if(arch_hab != NULL) {
//        while(!(feof(arch_hab))) {
//            fread((hab_datos+i), sizeof(t_habitantes),1 ,arch_hab);
//            i++;
//            if(i>=blk) {
//                realloc(hab_datos, sizeof(t_habitantes)*(blk+1));
//                blk = i + 1;
//            }
//        }
//    } else { printf("\nARCHIVO ERROR!"); }
    i=1; blk=1;
    if(arch_loc != NULL) {
        while(!(feof(arch_loc))) {
            fscanf(arch_loc,"%d,%s,%d", &((loc_datos+i)->ID_localidad), &((loc_datos+i)->nombre), &((loc_datos+i)->ID_zona));
            i++;
            if(i>=blk) {
                realloc(loc_datos, sizeof(t_localidades)*(blk+1));
                blk = i + 1;
            }
        }
    } else { printf("\nARCHIVO ERROR!"); }
    if(arch_habXloc != NULL) {
        while(!(feof(arch_habXloc))) {
            t_habitantesxlocalidadPtr datos = NULL;
            fscanf(arch_habXloc, "%d,%d", &(datos->ID_habitante), &(datos->ID_localidad));
            qeue(&habxloc_datos);
        }
    } else { printf("\nARCHIVO ERROR!"); }
//    fclose(arch_hab);
    fclose(arch_loc);
    fclose(arch_habXloc);
}

// Funciones del Final!!!


int code_loc(char nombreLoc[200]) {
    FILE*arch_loc=fopen('localidades.txt','rw');
    if(arch_loc!=NULL){
        while(!feof(arch_loc)){
            int cd_loc, cd_zone; char name[200];
            fscanf(arch_loc,"%d,%s,%d", &cd_loc, &name, &cd_zone);
            if(strcmp(nombreLoc,name)==1){ return cd_loc; }
            else { return -1; }
        }
    }
}
int is_genre(int id_hab, char sexo){
    t_habitantes habitante=NULL;
    FILE*arch_hab=fopen('habitantes.dat','rb');
    if(arch_hab!=NULL){
        while(!feof(arch_hab)){
            fread(&habitante,sizeof(t_habitantes),1, arch_hab);
            if(habitante->ID_habitante==id_hab && habitante->sexo==sexo){ return 1; }
            else { return 1; }
        }
    }
}
int cantHabitantes(char nombreLoc[200], char sexo) {
//    t_habitantesPtr hab_datos = NULL; t_localidadesPtr loc_datos = NULL; t_datos_habxlocPtr habxloc_datos = NULL;
    int my_Loc_use = -1, prom = 0, count_pp = 0;
    //load_files(&hab_datos, &loc_datos, &habxloc_datos);
    load_vars(&hab_datos, &loc_datos, &habxloc_datos);
    my_Loc_use = code_Loc(nombreLoc);
    if(my_Loc_use != -1) {
        FILE*arch_habXloc=fopen('habitantesXlocalidad.txt','rw');
        if(arch_habXloc!=NULL){
            while(!feof(arch_habXloc)){
                int cod_loc, cod_hab;
                fscanf(arch_habXloc, "%d,%d", &cod_loc, &cod_hab);
                if(cod_loc==my_Loc_use){
                    count_pp=count_pp + is_genre(cod_hab, sexo);
                }
            }
        }
    }else { printf("\nNo esta la localidad en la DB"); }
    return prom;
}
int get_age(int id){
    FILE*arch_hab=fopen('habitantes.dat','rb');
    if(arch_hab!=NULL){
        while(!feof(arch_hab)){
            t_habitantes habitante=NULL;
            fread(&habitante,sizeof(t_habitantes),1,arch_hab);
            if(habitante->ID_habitante==id){ return habitante->edad; }
        }
    }
    fclose(arch_hab);
}
void edadXlocalidad(){
    int ageXloc[99][4], i=0;
    ageXloc[i][0]=0
    FILE*arch_habXloc=fopen('habitantesXlocalidad.txt','r');
    if(arch_habXloc!=NULL){
            t_habitantesxlocalidad habitante=NULL;
        while(!feof(arch_habXloc)){
            fscanf(arch_habXloc,"%d,%d", &(habitante->ID_localidad), &(habitante->ID_habitante));
            for(i=0; i<99 || ageXloc[i][0]==0; i++){
                if(ageXloc[i][0]==habitante->ID_localidad){
                    ageXloc[i][2]=ageXloc[i][2]+get_age(habitante->ID_habitante);
                    ageXloc[i][3]++;
                    ageXloc[i][1]=ageXloc[i][2]/ageXloc[i][3];
                }
            }
            if(ageXloc[i][0]==0){
                ageXloc[i][0]=habitante->ID_localidad;
                ageXloc[i][2]=get_age(habitante->ID_habitante);
                ageXloc[i][3]=1;
                ageXloc[i][1]=ageXloc[i][2]/ageXloc[i][3];
                ageXloc[i+1][0]=0
            }
        }
        printf("Localidad | Promedio Edad")
        while(ageXloc[i][0]!=0){
            printf("%d          | %d\n", ageXloc[i][0],ageXloc[i][1]);
            i++;
        }
    }
    fclose(arch_habXloc);
}

int main(){
    int cant_hab = 0;
    cant_hab = cantHabitantes();
    edadXlocalidad();
    return 0;
}
