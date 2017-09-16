#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED
#include "Trabajador.h"
#include <stdlib.h>

class Nodo{
    private:
        Trabajador *tb;
        Nodo *Siguiente;
    public:
        Nodo (Trabajador *v, Nodo *sig=NULL){
            this->tb = v;
            this->Siguiente = sig ;
        }
        friend class Lista;
};
#endif // NODO_H_INCLUDED
