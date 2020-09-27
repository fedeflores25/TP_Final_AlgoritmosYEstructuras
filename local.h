#ifndef LOCAL_H_INCLUDED
#define LOCAL_H_INCLUDED

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

/*
    NOTAS:
    Fijarse si CABA se considera provincia
    Fijarse si esta bien el struct y el constructor
    Buscar como trabajar con el enum
*/

enum tProvincia{Buenos_Aires, CABA, Catamarca, Chaco, Chubut, Cordoba, Corrientes, Entre_Rios, Formosa, Jujuy, La_Pampa, La_Rioja, Mendoza, Misiones, Neuquen, Rio_Negro, Salta, San_Juan, San_Luis, Santa_Cruz, Santa_Fe, Santiago_del_Estero, Tierra_del_Fuego, Tucuman};

struct Local{
    int codigoSucursal;
	tProvincia provincia;
	int cantidadArticulos;
	float monto;
	float metros;
	int casaMatriz;
	Local(){
		
	}
	Local(int codigosucursal, tProvincia prov, int cantidadarticulos, float mont, float metr, int casamatriz){
	codigoSucursal = codigosucursal;
    provincia = prov;
    cantidadArticulos = cantidadarticulos;
    monto = mont;
    metros = metr;
    casaMatriz = casamatriz;
	}
	
	Local(int codigosucursal, tProvincia prov, int cantidadarticulos, float mont, float metr){
	codigoSucursal = codigosucursal;
    provincia = prov;
    cantidadArticulos = cantidadarticulos;
    monto = mont;
    metros = metr;
	}
	
		
	};

//Constructor 3
Local crearLocal(Local *local, int codigoSucursal, tProvincia provincia, int cantidadArticulos, float monto, float metros, int casaMatriz);


//DESTRUCTOR
void destruirLocal(Local *local);

//GETTERS Y SETTERS
int getCodigoSucursal(Local *local);
void setCodigoSucursal(Local *local,int codigoSucursal);

tProvincia getProvincia(Local *local);
void setProvincia(Local local, tProvincia provincia);

int getCantidadArticulos(Local *local);
void setCantidadArticulos(Local *local, int cantidadArticulos);

float getMonto(Local *local);
void setMonto(Local *local, float monto);

float getMetros(Local *local);
void setMetros(Local *local, float metros);

int getCasaMatriz(Local *local);
void setCasaMatriz(Local *local, int casaMatriz);

/********************************************************************************************************************************/



#endif // LOCAL_H_INCLUDED
