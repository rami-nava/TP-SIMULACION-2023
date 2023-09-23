#include <time.h>
#include <stdlib.h>
#include <math.h>
#include "init.h"

//genera random entre 0.0 y 1.0
double generarRandom(){
    
    //setear semilla en TIEMPO ACTUAL para rand()
    srand(time(NULL));

    return (double)rand() / RAND_MAX;
}

//intervalo entre averios
double ia(){

    double R=0;
    double IA=-1;

    while(IA<=0 || IA>=1716){
        while(R == 0 || R == 1){
            R = generarRandom();
        }
        IA = 28.89 + 25.095 * tan(M_PI*(R - 0.5));
        //reseteo R
        R=0;
    }

    return IA;
}

//REPARACION FALLO DE MAQUINA
double drbd(){
    //cargar FDP
    return generarRandom()*2000;
}

//REPARACION FUERZA MAYOR
double drco(){
    //cargar FDP
    return generarRandom()*2000;
}

//REPARACION MANTENIMIENTO
double drpm(){
    //cargar FDP
    return generarRandom()*2000;
}

//devuelve 1 si alguna maquina funciona
int algunaMaquinaEnfuncionamiento(){
    int i = 0;
    while (i < cm){
        if (tr[i] <= t){
            return 1;
        }
        else{
            i++;
        }
    }
    return 0;
}

int asignarMaquina(){
    while(1){
        double random = generarRandom();
        for(int i = 0; i < 15 ; i++)
        {
            //maquina i
            if(random <= trPor[i])
            {
                if(tr[i] <= t)
                {
                    return i;
                }else{
                    break;
                }
            }
        }
    }
}

int empleadoDisponible(){
    int menor = tc[0];
    int persona = 0;
    for(int j = 1; j < pmd; j++){
        if(tc[j] < menor){
            menor = tc[j];
            persona = j;
        }
    }
    return persona;
}

int duracionAverio(){
    double random = generarRandom();
    if (random <= 0.8){
        return drbd();
    } else {
        if(random <= 0.93){
            return drpm();
        }
        else {
            return drco();
        }
    }
}
