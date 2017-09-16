/*Programa que permite agregar empleados a una lista.
Desarrollado por : Carlos Javier Cañenguez.
                   Marlon Josué Marquez Cano.
                   Brian Stanley Herrera Garcia.
                   José Dimas Carabantes Garcia.
Materia : Programación III.

*/
#include <iostream>
#include <stdlib.h>
using namespace std;
#include "Lista.h"

Lista lst;

void Buscar(){      ///Procedimiento que permite buscar un elemento dentro de una lista.
    int i;
    cout << "Digite el valor a buscar " << endl;
    cin >> i;
    if(lst.Buscar(i)!=NULL){
        cout << "Se encontro el elemento " << i << endl;
    }else{
        cout << "No se encontro el elemento " << endl;
    }
}

int menu(){ ///Menu de opciones.
    int op;
    cout << "*** Bienvenido ***" << endl;
    cout << "1. Agregar trabajador al inicio de la  lista " << endl;
    cout << "2. Agregar trabajador al final de la lista " << endl;
    cout << "3. Agregar trabajador en medio de la lista " << endl;
    cout << "4. Buscar trabajador en la lista " << endl;
    cout << "5. Eliminar trabajador en la lista" << endl;
    cout << "6. Modificar trabajador en la lista" << endl;
    cout << "7. Mostrar lista original" << endl;
    cout << "8. Mostrar lista ordenada" << endl;
    cout << "9. Salir\n" << endl;
    cout << "Digite una opcion: ";
    cin >> op;
    return op;


}

int main()
{
    int opc;
    do{
        int c;
        string n,a;
        float sm;
        Trabajador tb(c,n,a,sm);
        opc = menu();
        system("cls");
        switch(opc){
        case 1:{        ///AGREGAR TRABAJADOR AL INICIO
            cout << "Digite el codigo del trabajador: ";
            cin >> c;
            cout << "Digite el nombre del trabajador: ";
            cin >> n;
            cout << "Digite el apellido del trabajador: ";
            cin >> a;
            cout << "Digite el sueldo mensual del trabajador: ";
            cin >> sm;
            lst.Adicionar(c,n,a,sm);
        }break;
        case 2:{        ///AGREGAR TRABAJADOR AL FINAL
            int codigo;
            string nombre,apellido;
            float sueldo;
            cout << "Digite el codigo del trabajador: ";
            cin >> codigo;
            cout << "Digite el nombre del trabajador: ";
            cin >> nombre;
            cout << "Digite el apellido del trabajador: ";
            cin >> apellido;
            cout << "Digite el sueldo mensual del trabajador: ";
            cin >> sueldo;
            Trabajador *t = new Trabajador(codigo,nombre,apellido,sueldo);
            lst.Insertar(t);
        }break;
        case 3:{        ///AGREGAR TRABAJADOR EN MEDIO
            int r;
            cout << "Desea agregar" << endl;
            cout << "1. En medio antes " << endl;
            cout << "2. En medio despues" << endl;
            cout << "Digite una opcion: ";
            cin >> r;
            if(r==1){       ///AGREGAR TRABAJADOR EN MEDIO - ANTES
                system("cls");
                int c1, c2;
                string n1, a1, n2, a2;
                float sm1, sm2;
                cout << "Digite los datos del trabajador de referencia..." << endl;
                cout << "Digite el codigo del trabajador: ";
                cin >> c1;
                cout << "Digite el nombre del trabajador: ";
                cin >> n1;
                cout << "Digite el apellido del trabajador: ";
                cin >> a1;
                cout << "Digite el sueldo mensual del trabajador: ";
                cin >> sm1;
                cout << "\n";
                if(lst.Buscar(c1)){     ///SI ENCUENTRA LA REFERENCIA, QUE PROSIGA A DIGITAR EL NUEVO
                    Trabajador *trabajador = new Trabajador(c1, n1, a1, sm1);
                    cout << "Digite los datos del nuevo trabajador..." << endl;
                    cout << "Digite el codigo del trabajador: ";
                    cin >> c2;
                    cout << "Digite el nombre del trabajador: ";
                    cin >> n2;
                    cout << "Digite el apellido del trabajador: ";
                    cin >> a2;
                    cout << "Digite el sueldo mensual del trabajador: ";
                    cin >> sm2;
                    lst.AgregarAntes(trabajador, c2, n2, a2, sm2);
                }
                else{
                    cout << "El trabajador de referencia no fue encontrado...\n";
                }
            }
            else{       ///AGREGAR TRABAJADOR EN MEDIO - DESPUES
                system("cls");
                int c3, c4;
                string n3, a3, n4, a4;
                float sm3, sm4;
                cout << "Digite los datos del trabajador de referencia..." << endl;
                cout << "Digite el codigo del trabajador: ";
                cin >> c3;
                cout << "Digite el nombre del trabajador: ";
                cin >> n3;
                cout << "Digite el apellido del trabajador: ";
                cin >> a3;
                cout << "Digite el sueldo mensual del trabajador: ";
                cin >> sm3;
                cout << "\n";
                if(lst.Buscar(c3)){     ///SI ENCUENTRA LA REFERENCIA, QUE PROSIGA A DIGITAR EL NUEVO
                    Trabajador *trabajador = new Trabajador(c3, n3, a3, sm3);
                    cout << "Digite los datos del nuevo trabajador..." << endl;
                    cout << "Digite el codigo del trabajador: ";
                    cin >> c4;
                    cout << "Digite el nombre del trabajador: ";
                    cin >> n4;
                    cout << "Digite el apellido del trabajador: " ;
                    cin >> a4;
                    cout << "Digite el sueldo mensual del trabajador: ";
                    cin >> sm4;
                    lst.AgregarDespues(trabajador, c4, n4, a4, sm4);
                }
                else{
                    cout << "El trabajador de referencia no fue encontrado...\n";
                }
            }
        }break;
        case 4:{        ///BUSCAR TRABAJADOR
            int c;
            cout << "Digite el codigo del trabajador a buscar: " << endl;
            cin >> c;
            cout << "\n";
            lst.MostrarTbBuscado(c);
        }break;
        case 5:{        ///ELIMINAR TRABAJADOR
            int i;
            cout << "Digite el ID del trabajador a eliminar: ";
            cin >> i;
            if(lst.Buscar(i)){
                lst.Eliminar(i);
                cout << "Eliminado con exito...\n";
            }
            else{
                cout << "El ID no existe...\n";
            }
        }break;
        case 6:{        ///MODIFICAR TRABAJADOR
            int v, nc;
            string n, a;
            float sm;
            cout << "Digite el ID del trabajador a modificar: ";
            cin >> v;
            cout << "\n";
            if(lst.Buscar(v)){
                cout << "Digite los datos del nuevo trabajador..." << endl;
                cout << "Digite el codigo del trabajador: ";
                cin >> nc;
                cout << "Digite el nombre del trabajador: ";
                cin >> n;
                cout << "Digite el apellido del trabajador: ";
                cin >> a;
                cout << "Digite el sueldo mensual del trabajador: ";
                cin >> sm;
                Trabajador *tb = new Trabajador(nc, n, a, sm);
                lst.Modificar(v, tb);
            }
            else{
                cout << "El ID no fue encontrado...\n";
            }
        }break;
        case 7:{        ///MOSTRAR LISTA ORIGINAL
            lst.Mostrar();
        }break;
        case 8:{        ///MOSTRAR LISTA ORDENADA
            lst.ordenarBurbu();
        }break;
        case 9:{        ///SALIR
            cout << "Saliendo..." << endl;
            break;
            default:
                cout << "Opcion no valida..." << endl;
        }break;
        }
    system("pause");
    system("cls");
    }while(opc!=9);
    return 0;
}
