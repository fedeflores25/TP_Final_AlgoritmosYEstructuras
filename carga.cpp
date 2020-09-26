#include <iostream>
#include <cstdio>
#include <dirent.h>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void cargaDatos();
vector<string> cargaArchivo();
void lectura(string lista);
bool validarLinea(string tex);
vector<string> split(string str );

void cargaDatos(){
    vector<string> listaArchivos = cargaArchivo();                   // se cargan todos los archivos
    for_each(listaArchivos.begin(), listaArchivos.end(), lectura);  // cada archivo se lee y agregan los locales a las listas
}
vector<string> cargaArchivo(){
    DIR * carpeta;
    struct dirent * elemento;                               //es una estructura de elementos que se va a usar para listar los archivos
    string carp = "datos/";                                 //ruta para la carga de archivos
    string arch;                                            // variable para almacenar el nombre de cada archivo
    vector <string> archivos;                               // todos los archivos vana  ser almacenados  en este vector
    if (carpeta = opendir(carp.c_str())){                   // se comprieba si se puede abrir la carpeta
            while(elemento = readdir(carpeta)){             //mientras haya un archivo para leer
                arch = elemento->d_name;                    // guardamos el nombre del archivo en la variable
                if(arch !="." && arch !=".."){
                    archivos.push_back(arch);               //se guarda el nombre del archivo en el vector
                }
            }
    } else{
        cout << "No se puedo abrir la carpeta "+carp << endl;
        exit(1);
    }
    closedir(carpeta);
   return archivos;
}
void lectura(string arch){
    string datos = ("datos/"+arch);
    ifstream archivo;
    archivo.open(datos, ios::in);
    if(archivo.fail()){
        cout<< "No se pudo abrir el archivo "+datos << endl ;
        exit(1);
    }
    string texto;
    vector<string> resultados;
    while(!archivo.eof()){
        getline(archivo, texto);
        if (validarLinea(texto)){
            cout << "Existe algun dato erroneo en el archivo "+ datos << endl;
            cout<<"No se cargará la siguiente linea: "+ texto << endl;
        }
        else{
            resultados = split(texto);
            //enviar los resultados a ser convertidos en estructura de local y luego agregar a la lista de locales
        }
    }
    archivo.close();
}
bool validarLinea(string tex){
    bool flag = false;
    int j=0;
    for(int i=0;i<tex.size();i++){                          // este for cuenta los '-' y valida si hay 2 seguidos
        if (tex[i]== '-') j++;
        if (tex[i]== '-' && tex[i+1] == '-') flag=true;
    }
    if (j!=6) flag = true;
    return flag;
}
vector<string> split(string str ) {
    char pattern = '-';                                     //delimitador
    int posInit = 0;                                        //posicion iniicial del recorrido
    int posFound = 0;                                       //posicion final del recorrido
    string splitted;                                        // variable para almacenar el tramo de string
    vector<string> resultados;                              // vector para almacenar todos los recortes
    while(posFound >= 0){
        posFound = str.find(pattern, posInit);
        splitted = str.substr(posInit, posFound - posInit); //concatena desde la posicion inicial hasta la posicion final
        posInit = posFound + 1;
        resultados.push_back(splitted);                     //inserta el string al final del vector
    }
    return resultados;
}
