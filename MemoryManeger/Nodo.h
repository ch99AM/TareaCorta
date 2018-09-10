/*
 * Nodo.h
 *
 * Definicion de los nodos usados en GestorMemoriaFIFO, GestoLRU y GestorMemoriaReloj
 *
 * Fecha: 23/11/2011
 */

#ifndef NODO_H
#define NODO_H 1

class Nodo {
public:
    int dato;
    Nodo * sig;
};

#endif
