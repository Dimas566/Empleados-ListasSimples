#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
#include "Nodo.h"

class Lista{
    private:
        Nodo *Primero;
        Nodo *Ultimo;
        bool ListaVacia(){
            return (this->Primero == NULL);
        }
    public:
        Lista(){
            Primero = NULL;
            Ultimo = NULL;
        }
        ~Lista(){
            this->Ultimo = NULL;
            while(this->Primero){
                Nodo *temp = this->Primero;
                this ->Primero = this->Primero->Siguiente;
                delete temp;
            }
        }
        void Insertar(Trabajador *tb){      ///INTRODUCE AL FINAL
            Nodo *nuevo = new Nodo(tb);
            if(this->ListaVacia()){
                this->Primero = nuevo;
            }
            else{
                this->Ultimo = this->Primero;
                if(this->ListaVacia()!=true){
                    while(this->Ultimo->Siguiente!=NULL){
                        this->Ultimo = this->Ultimo->Siguiente;
                    }
                }
            }
            this->Ultimo->Siguiente = nuevo;
        }
        void Insertar(int c, string n, string a, float s){      ///INTRODUCE AL FINAL
            Trabajador *tb = new Trabajador(c, n, a, s);
            this->Insertar(tb);
        }
        void Adicionar(Trabajador *tb){     ///INTRODUCE AL PRINCIPIO
            this->Ultimo = this->Primero;
            Nodo *nuevo = new Nodo(tb);
            if(this->ListaVacia()){
                this->Primero = nuevo;
            }
            else{
                nuevo->Siguiente = this->Primero;
                this->Primero = nuevo;
                while(this->Ultimo){
                    this->Ultimo = this->Ultimo->Siguiente;
                }
            }
        }
        void Adicionar(int c, string n, string a, float s){     ///INTRODUCE AL PRINCIPIO
            Trabajador *tb = new Trabajador(c, n, a, s);
            this->Adicionar(tb);
        }
        void AgregarAntes(Trabajador *tg, Trabajador *nt){      ///INTRODUCE EN MEDIO - ANTES
            Nodo *nuevo = new Nodo(nt);
            Nodo *aux = this->Buscar(tg);
            if(this->ListaVacia()){
                this->Primero = nuevo;
            }
            else{
                if(this->Primero->tb->getId() == tg->getId()){
                    this->Adicionar(nt);
                }
                else{
                    Nodo *posterior = this->Primero;
                    Nodo *anterior;
                    while(posterior->tb->getId()!= aux->tb->getId()){
                        anterior = posterior;
                        posterior = posterior->Siguiente;
                    }
                    anterior->Siguiente = nuevo;
                    nuevo->Siguiente = posterior;
                }
            }
        }
        void AgregarAntes(Trabajador *tg, int c, string n, string a, float s){      ///INTRODUCE EN MEDIO - ANTES
            Trabajador *nt = new Trabajador(c, n, a, s);
            this->AgregarAntes(tg, nt);
        }
        void AgregarDespues(Trabajador *tg, Trabajador *nt){        ///INTRODUCE EN MEDIO - DESPUES
            Nodo *nuevo = new Nodo(nt);
            Nodo *aux = this->Buscar(tg);
            if(this->ListaVacia()){
                this->Primero = nuevo;
            }
            else{
                if(this->Primero->tb->getId() == tg->getId() && this->Primero->Siguiente == NULL){
                    this->Insertar(nt);
                }
                else{
                    if(this->Primero->tb->getId() == aux->tb->getId() && this->Primero->Siguiente->Siguiente == NULL){
                        Nodo *posterior = this->Primero->Siguiente;
                        this->Primero->Siguiente = nuevo;
                        nuevo->Siguiente = posterior;
                    }
                    else{
                        Nodo *actual = this->Primero;
                        Nodo *posterior;
                        while(actual->tb->getId()!= aux->tb->getId()){
                            actual = actual->Siguiente;
                            posterior = actual->Siguiente;
                        }
                        actual->Siguiente = nuevo;
                        nuevo->Siguiente = posterior;
                    }
                }
            }
        }
        void AgregarDespues(Trabajador *tg, int c, string n, string a, float s){        ///INTRODUCE EN MEDIO - DESPUES
            Trabajador *nt = new Trabajador(c, n, a, s);
            this->AgregarDespues(tg, nt);
        }
        Nodo *Buscar(Trabajador *nt){
            Nodo *tmp=this->Primero;
            while(tmp){
                if(tmp->tb->getId() == nt->getId() ){
                return  tmp;
                }
                tmp = tmp->Siguiente;
            }
            return NULL;
        }
        Nodo *Buscar(int c){
            Nodo *tmp = this->Primero;
            while(tmp){
                if(tmp->tb->getId() == c){
                return tmp;
                }
                tmp = tmp->Siguiente;
            }
            return NULL;
        }
        void Mostrar(){     ///MUESTRA LA LISTA
            Nodo *tmp = this->Primero;
            cout << "Id\tNombre\tApellidos\tSueldo\tISSS\tAFP\tISR\tSueldo Total\n";
            while(tmp){
                cout << tmp->tb->getId() << "\t";
                cout << tmp->tb->getNombres() << "\t";
                cout << tmp->tb->getApellidos() << "\t";
                cout <<"\t"<<tmp->tb->getSueldoMensual() << "\t";
                cout << tmp->tb->getDescuentoIsss() << "\t";
                cout << tmp->tb->getDescuentoAfp() << "\t";
                cout << tmp->tb->getDescuentoIsr() << "\t";
                cout << tmp->tb->getTotalPagar()<< "\n";
                tmp = tmp->Siguiente;
            }
            cout << "NULL" << endl;
        }
        void MostrarTbBuscado(int c){       ///MUESTRA EL TRABAJADOR BUSCADO
            if(this->Buscar(c)){
                cout << "Id\tNombre\tApellidos\tSueldo\tISSS\tAFP\tISR\tSueldo Total\n";
                cout << this->Buscar(c)->tb->getId() << "\t";
                cout << this->Buscar(c)->tb->getNombres() << "\t";
                cout << this->Buscar(c)->tb->getApellidos() << "\t";
                cout <<"\t"<< this->Buscar(c)->tb->getSueldoMensual() <<"\t";
                cout << this->Buscar(c)->tb->getDescuentoIsss() << "\t";
                cout << this->Buscar(c)->tb->getDescuentoAfp() << "\t";
                cout << this->Buscar(c)->tb->getDescuentoIsr() << "\t";
                cout << this->Buscar(c)->tb->getTotalPagar()<< "\n";
            }
            else{
                cout << "El ID no fue encontrado...\n";
            }
        }
        void Eliminar(int v){       ///ELIMINA UN TRABAJADOR DE LA LISTA
            Nodo *tmp = this->Primero;
            Nodo *anterior = NULL;
            bool encontrado = false;
            while(tmp && !encontrado){      ///MIENTRAS NO HAYA SIDO ENCONTRADO
                if(tmp->tb->getId() == v){
                    encontrado = true;
                    if(this->Primero == tmp){       ///AL PRINCIPIO
                        this->Primero = tmp->Siguiente;
                    }
                    else{
                        if(this->Ultimo == tmp){        ///AL FINAL
                            this->Ultimo = anterior;
                            this->Ultimo->Siguiente = NULL;
                        }
                        else{      ///EN MEDIO
                            anterior->Siguiente = tmp->Siguiente;
                        }
                    }
                    delete tmp;
                }
                else{       ///SE ASIGNA ANTERIOR A NUESTRO TMP Y NUESTRO TMP AHORA APUNTA AL SIGUIENTE PARA RECORRER LA LISTA
                    anterior = tmp;
                    tmp = tmp->Siguiente;
                }
            }
        }
        void Modificar(int v, Trabajador *nt){
            Nodo *temp = this ->Buscar(v);
            if(temp){
                temp->tb = nt;
            }
            else{
                cout << "Dato no encontrado en la lista" << endl;
            }
        }
        void ordenarBurbu(){        ///ORDENA LA LISTA SEGUN ID E IMPRIME
            Nodo *tmp = this->Primero;
            while(tmp){
                Nodo *tmp2 = tmp->Siguiente;
                while(tmp2){
                    if(tmp->tb->getId() > tmp2->tb->getId()){
                        Trabajador *aux = tmp2->tb;
                        tmp2->tb = tmp->tb;
                        tmp->tb = aux;
                    }
                    tmp2 = tmp2->Siguiente;
                }
                tmp = tmp->Siguiente;
            }
            this->Mostrar();
        }
};
#endif // LISTA_H_INCLUDED
