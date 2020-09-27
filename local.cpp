
#include "local.h"

/********************************************************************************************************************************/
/*
    ATRIBUTOS:
    codigoSucursal
    provincia
    cantidadArticulos
    monto
    metros
    casaMatriz

    AXIOMAS:
    codigoSucursal > 0
    provincia (Buenos_Aires por default)
    cantidadArticulos => 0
    monto >= 0
    metros > 0
    casaMatriz (codigoSucursal del local desde que se maneja todo)
*/
/********************************************************************************************************************************/


//Constructores
//Constructor para que el usuario pueda crear locales
/*Local crearLocal(){

    struct LocalStruct* Local = new LocalStruct;

    Local->codigoSucursal    = 1;
    Local->provincia         = Buenos_Aires;
    Local->cantidadArticulos = 1;
    Local->monto             = 0;
    Local->metros            = 1;
    Local->casaMatriz        = 1;

    return Local;
}*/

//Constructor 3 - para crear locales cuando se lee el archivo
Local crearLocal(Local *local, int codigoSucursal, tProvincia provincia, int cantidadArticulos, float monto, float metros, int casaMatriz){

    Local* local = new Local();

    local->codigoSucursal    = codigoSucursal;
    local->provincia         = provincia;
    local->cantidadArticulos = cantidadArticulos;
    local->monto             = monto;
    local->metros            = metros;
    local->casaMatriz        = casaMatriz;

    return *local;
}


//Destructor
void destruirLocal(Local *local){
	delete local; 
}


//Getters y Setters
int getCodigoSucursal(Local *local){
    return local->codigoSucursal;
}

void setCodigoSucursal(Local *local,int codigoSucursal){
    if(codigoSucursal > 0) local->codigoSucursal = codigoSucursal;
}


tProvincia getProvincia(Local *local){
    return local->provincia;
}
void setProvincia(Local *local, tProvincia provincia){
    local->provincia = provincia;
}


int getCantidadArticulos(Local *local){
    return local->cantidadArticulos;
}
void setCantidadArticulos(Local *local, int cantidadArticulos){
    if(cantidadArticulos >= 0) local->cantidadArticulos = cantidadArticulos;
}
float getMonto(Local *local){
    return local->monto;
}
void setMonto(Local *local, float monto){
    if(monto >= 0) local->monto = monto;
}


float getMetros(Local *local){
    return local->metros;
}
void setMetros(Local *local, float metros){
    if(metros > 0) local->metros = metros;
}


int getCasaMatriz(Local *local){
    return local->casaMatriz;
}
void setCasaMatriz(Local *local, int &casaMatriz){
    if(casaMatriz > 0) local->casaMatriz = casaMatriz;
}

/********************************************************************************************************************************/
