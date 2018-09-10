

#include "GestorLRU.h"

#include <iostream>

using namespace std;

// Contructor, par�metros:
//             - nPaginasEnMemoria: Numero maximo de paginas a alojar en memoria (marcos)
GestorLRU::GestorLRU(int nPaginasEnMemoria) :GestorMemoria(nPaginasEnMemoria) {
    listaAccesos=NULL;
    zonaMemoria=new int[nPaginasEnMemoria];
}

// Destructor: libera el espacio reservado para los marcos
GestorLRU::~GestorLRU() {
    delete[] zonaMemoria;
}


// Devuelve true si una p�gina esta cargada, false en otro caso
bool GestorLRU::estaCargadaPagina(int idPagina) {
    for (int i=0;i<nPaginas;i++)
        if (zonaMemoria[i]==idPagina)
            return true;
    return false;
}

// Carga una pagina en memoria
void GestorLRU::cargarPagina(int idPagina) {
    Nodo * nuevo;
    if (nPaginas<getMaxPaginas()) {
        zonaMemoria[nPaginas]=idPagina;
        nPaginas++;
    }
    else
        zonaMemoria[getZonaMemoriaUsadaMenosRecientemente()]=idPagina;
}

// Devuelve el id de la pagina en la posicion dada
int GestorLRU::getPaginaEnPosicion(int posicion) {
    return zonaMemoria[posicion];
}

// Intenta acceder a una p�gina, carg�ndola si es necesario.
// Devuelve true si se produjo un fallo de memoria, false en otro caso
// Nota: redefinimos el accederPagina para ir "anotando" los accesos
bool GestorLRU::accederPagina(int idPagina) {
    Nodo * nuevo=new Nodo;
    nuevo->dato=idPagina;
    nuevo->sig=listaAccesos;
    listaAccesos=nuevo;

    return GestorMemoria::accederPagina(idPagina);
}


// Devuelve el marco usado menos recientemnete
int GestorLRU::getZonaMemoriaUsadaMenosRecientemente() {
    int zonasMemoriaEncontradas=0;
    Nodo * aux;

    // Iniciamos una vector de distancias vacios
    int * distanciaPagina = new int[nPaginas];
    for (int i=0;i<nPaginas;i++)
        distanciaPagina[i]=0;

    // Contamos las distancias para cada zonaMemoria
    for (int i=0;i<nPaginas;i++) {
        aux=listaAccesos;
        while (aux!=NULL && aux->dato!=zonaMemoria[i]) {
            distanciaPagina[i]++;
            aux=aux->sig;
        }
    }
    // Devolvemos la componante con valor m�ximo
    int indiceMaximo=0;
    for (int i=0;i<nPaginas;i++)
        if (distanciaPagina[i]>distanciaPagina[indiceMaximo])
            indiceMaximo=i;
    return indiceMaximo;
}

