#include <stdio.h>

#include "libreria.h"

int main()
{
    pedirTF();
    pedirPMD();
    
    line();

    inicializarTC();
    inicializarTR();

    inicializarSemilla(); // Inicializar la semilla con el tiempo actual

    while (t <= tf){
        t = tpa;
        
        //generar siguiente averio
        double ia_valor = ia();
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
            //una maquina mas arreglada
            ca++;
            //la maquina vuelve a funcionar cuando termine el tc del empleado j
            tr[i] = tc[j];
            //se acumula un nuevo tiempo de averia general
            sta = sta + (tc[j] - t);
        }
    }

    printf("%i\n",ster);
    printf("%i\n",sto);

    printf("TF: %u \n", tf);
    printf("T: %u \n", t);
    printf("Porcentaje de tiempo ocioso (PTO) : %f\n", (sto/pmd)*100/t);
    printf("Promedio de tiempo de espera por reparacion (PTER) : %u\n", ster/ca);
    printf("Promedio de tiempo de averio de las máquinas (PTA) : %u\n", sta/ca);
    line();

    return 0;
}

