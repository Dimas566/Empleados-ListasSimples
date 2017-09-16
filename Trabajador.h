#ifndef TRABAJADOR_H_INCLUDED
#define TRABAJADOR_H_INCLUDED
#include <string.h>

class Trabajador{
    private:
        int id;
        string Nombres;
        string Apellidos;
        float SueldoMensual;
        float descuentoIsss;
        float descuentoAfp;
        float descuentoIsr;
        float TotalDescuentos;
        float TotalPagar;
    public:
        Trabajador(int c, string n, string a, float s){
            this->id = c;
            this->Nombres = n;
            this->Apellidos = a;
            this->SueldoMensual = s;
        }
        int getId(){
            return this->id;
        }
        string getNombres(){
            return this->Nombres;
        }
        string getApellidos(){
            return this->Apellidos;
        }
        float getSueldoMensual(){
            return this->SueldoMensual;
        }
        float getDescuentoIsss(){ ///Funcion para calcular el descuento ISSS.
            float salario = getSueldoMensual();
         if(salario > 0 && salario<=1000){
            this->descuentoIsss = 0.03 * salario;
         }else if(salario > 1000){
             this->descuentoIsss = 30;
         }else{
             this->descuentoIsss = 0;
         }
         return this->descuentoIsss;
        }
        float getDescuentoAfp(){ ///Funcion para calcular el descuento AFP.
            float salario = getSueldoMensual();
                if(salario > 0 && salario <= 6319.02){
                this->descuentoAfp= salario * 0.0625;
            }
            else if(salario > 6319.02 ){
                this->descuentoAfp = 6319.02 * 0.0625;
            }
            return this->descuentoAfp;
        }
        float getDescuentoIsr(){ ///Funcion para realizar el calculo del ISR. Basado en las tablas de educaconta.
            float sueldolibre = getSueldoMensual() - (getDescuentoIsss() + getDescuentoAfp());
            if (sueldolibre >= 0.01 && sueldolibre <= 472.00){
                this->descuentoIsr = 0.00;
            }
            else if (sueldolibre >= 472.01 && sueldolibre <= 895.24){
                    this->descuentoIsr =  (sueldolibre - 472.00) * 0.10 + 17.67;
            }
            else if (sueldolibre >= 895.25 && sueldolibre <= 2038.10){
                    this->descuentoIsr =  (sueldolibre - 895.24) * 0.20 + 60.00;
            }
            else if (sueldolibre >= 2038.11){
                    this->descuentoIsr =  (sueldolibre - 2038.10) * 0.30 + 288.57;
            }
            else {
                this->descuentoIsr =  0.00;
            }

            return this->descuentoIsr;
        }
        float getTotalDescuentos(){
            this->TotalDescuentos=getSueldoMensual()-(getDescuentoAfp()+getDescuentoIsss()+getDescuentoIsr());
            return this->TotalDescuentos;
        }
        float getTotalPagar(){
            this->TotalPagar = getTotalDescuentos();
            return this->TotalPagar;
        }
};
#endif // TRABAJADOR_H_INCLUDED
