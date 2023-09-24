#include <time.h>
#include <stdlib.h>
#include <math.h>
#include "init.h"

void line(){
    printf("---------------------------------------\n");
}

//se inicializa una unica vez, para no obtener el mismo valor siempre
void inicializarSemilla(){
     //setear semilla en TIEMPO ACTUAL para rand()
    srand(time(NULL));
}

//genera random entre 0.0 y 1.0
double generarRandom(){
    return (double)rand() / RAND_MAX;
}

//intervalo entre averios
double ia(){

    double R=1;
    double IA=-1;

    //El valor debe estar dentro del intervalo
    while(IA > 1716 || IA < 0){
        while(R == 1){  //no puede ser 1
            R = generarRandom();
        }   //la cuenta esta acotada en los valores reales, aprox 20-200
        IA = 220.67*(pow(1-R, -0.22263285)-1);
        
        R = 1; //reinicio el random
    }
    
    return IA;
}

//REPARACION FALLO DE MAQUINA
double drbd(){

    double R=1;
    double DRBD=1081;

    //El valor debe estar dentro del intervalo
    while(DRBD > 1440 || DRBD < 1){

        while(R == 1){  //no puede ser 1
            R = generarRandom();
        } 
        //valores en 2-6 y 20-14
        DRBD = 1.8985*pow((pow((1-R), -3.973299428)-1), 0.3665151737) + 0.46196;

        R=1;//reinicio el random
    }

    return DRBD;
}

//REPARACION FUERZA MAYOR
double drco(){
    
    double R=1;
    double DRCO=1081;

    //El valor debe estar dentro del intervalo
    while(DRCO > 1380 || DRCO < 2){

        while(R == 1){  //no puede ser 1
            R = generarRandom();
        } 
            //valores en 200-400
        DRCO = 720.57*pow( pow(1/R, 9.36241925) - 1, -0.1466791833);

        R=1;//reinicio el random
    }

    return DRCO;
}

//REPARACION MANTENIMIENTO
double drpm(){
    double R=1;
    double DRPM=1081;

    //El valor debe estar dentro del intervalo
    while(DRPM > 1440 || DRPM < 1){

        while(R == 1){  //no puede ser 1
            R = generarRandom();
        } 

            //valores en 9-300
        DRPM = 8.773*pow((pow((1-R), -5.416531253)-1), 0.2798455253) + 0.02631;
        
        R=1;//reinicio el random
    }

    return DRPM;
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
    int persona = 0;
    for(int j = 1; j < pmd; j++){
        if(tc[j] < tc[persona]){
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