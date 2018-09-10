/*
 * GestorMemoria.h
 *
 * Clase abstracta que ser� definida por todos los gestores de memoria que ser�n subclases de ellas
 * y que deber�n definir los m�todos estaCargadaPagina(int) : bool,  cargarPagina(int) : void, y getPagina(int) : int
 *
 * Fecha: 21/11/2011
 */
#include <iostream>

#ifndef GESTORMEMORIA_H
#define GESTORMEMORIA_H 1

class GestorMemoria {
private:
    int nMaxPaginas;

protected:
    int nPaginas;

    // Los siguientes m�todos deber�n ser implementados por las clases hijas.
    virtual bool estaCargadaPagina(int idPagina)=0;
    virtual void cargarPagina(int idPagina)=0;

public:
    // Contructor, par�metros:
    //             - nPaginasEnMemoria: Numero maximo de paginas a alojar en memoria (marcos)
    GestorMemoria(int nPaginasEnMemoria){
        nMaxPaginas=nPaginasEnMemoria;
        nPaginas=0;
    };

    // Devuelve el numero maximo de paginas a alojar en memoria (marcos)
    int getMaxPaginas(){
        return nMaxPaginas;
    };

    // Devuelve el id de la pagina en la posicion especificada
    virtual int getPaginaEnPosicion(int posicion)=0;

    // Intenta acceder a una p�gina, carg�ndola si es necesario.
    // Devuelve true si se produjo un fallo de memoria, false en otro caso
    virtual bool accederPagina(int idPagina){
        if (estaCargadaPagina(idPagina))
            return false;
        else {
            cargarPagina(idPagina);
            return true;
        }
    };

    // Muestra el estado de la memoria por pantalla.
    virtual void mostrar(){
        int pagina;
        for (int i=0;i<nPaginas;i++) {
            pagina=getPaginaEnPosicion(i);
            std::cout<<"  "<<pagina<<"  "<<std::endl;
        }
    };
};

#endif
