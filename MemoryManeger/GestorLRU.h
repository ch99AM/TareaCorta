
#include "iostream"
#include "GestorMemoria.h"
#include "Nodo.h"

class GestorLRU : public GestorMemoria {
private:
    Nodo * listaAccesos;
    int * zonaMemoria;

    // Devuelve el marco usado menos recientemnete
    int getZonaMemoriaUsadaMenosRecientemente();

public:
    // Contructor, par�metros:
    //             - nPaginasEnMemoria: Numero maximo de paginas a alojar en memoria (marcos)
    GestorLRU(int nPaginasEnMemoria);

    // Destructor: libera el espacio reservado para los marcos
    ~GestorLRU();

    // Devuelve true si una p�gina esta cargada, false en otro caso
    bool estaCargadaPagina(int idPagina);

    // Carga una pagina en memoria
    void cargarPagina(int idPagina);

    // Devuelve el id de la pagina en la posicion dada
    int getPaginaEnPosicion(int posicion);

    // Intenta acceder a una p�gina, carg�ndola si es necesario.
    // Devuelve true si se produjo un fallo de memoria, false en otro caso
    bool accederPagina(int idPagina);
};
