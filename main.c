#include <stdio.h>

#include "libreria.h"


int main()
{
    
    inicializarTRyTC();

    while (t <= tf){
        
        t = tpa;

        //generar siguiente averio
        double ia_valor = ia()*2000;
        tpa = t + ia_valor;

        //si alguna maquina esta funcionando
        if (algunaMaquinaEnfuncionamiento()){

            //maquina que se estropea
            int i = asignarMaquina();

            //empleado que la arregla, de menor TC
            int j = empleadoDisponible();

            //tiempo que tarda en volver a funcionar
            int da = duracionAverio();
            
            if(t <= tc[j]){
                //la maquina tiene tiempo de espera
                ster = ster + (tc[j] - t);
                tc[j] = tc[j] + da;
            } 
            else {
                //un empleado la arregla
                sto = sto + (t - tc[j]);
                tc[j] = t + da;
            }
            ca++;
            tr[i] = tc[j];
            sta = sta + (tc[j] - t);
        }
    }
    
    
    printf("TF: %i \n", tf);
    printf("T: %i \n", t);
    printf("Porcentaje tiempo ocioso (PTO) : %i\n", (sto*100)/t);
    printf("Promedio de tiempo de espera por reparacion (PTER) : %i\n", ster/ca);
    printf("Promedio de tiempo de averio de las máquinas (PTA) : %i\n", sta/ca);

    
    return 0;
}
