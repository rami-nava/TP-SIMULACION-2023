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
    while(IA > 695|| IA < 0){
        while(R == 1){  //no puede ser 1
            R = generarRandom();
        }   //la cuenta esta acotada en los valores reales, aprox 20-200
        IA = 67.373/0.32084*(pow((1-R),-0.32084)-1) - 15.465; //gen_pareto
        R = 1; //reinicio el random
    }
    printf("IA: %lf\n", IA);
    return IA;
}

//REPARACION FALLO DE MAQUINA
double drbd(){

    double R=1;
    double DRBD=0;

    //El valor debe estar dentro del intervalo
    while(DRBD > 900 || DRBD < 30){

        while(R == 1 || R == 0){  //no puede ser 1
            R = generarRandom();
        } 
        DRBD = -2219.3 + 2715.4*pow((pow(R,(-1/0.13863))-1),(-1/112.01)); //dagum 4p
        R=1;//reinicio el random
    }
    printf("DRBD: %lf\n", DRBD);
    return DRBD;
}

//REPARACION FUERZA MAYOR
double drco(){
    
    double R=1;
    double DRCO=1500;

    //El valor debe estar dentro del intervalo
    while(DRCO > 540 || DRCO < 60){

        while(R == 0 || R == 1){  //no puede ser 0 o 1
            R = generarRandom();
        } 
            //valores en 200-400
        DRCO = 721.87/-1.8397 * (pow((1-R), 1.8397) -1) + 109.37; //gen_pareto

        R=0;//reinicio el random
    }

    return DRCO;
}

//REPARACION MANTENIMIENTO
double drpm(){
    double R=1;
    double DRPM=540;

    //El valor debe estar dentro del intervalo
    while(DRPM > 540 || DRPM < 30){

        while(R == 1 || R==0){  //no puede ser 1
            R = generarRandom();
        } 

            //valores en 9-300
        DRPM = 291.68 * (pow((1/R - 1), -0.29906)) -60.215 ; //log-logistic
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
    if (random <= 0.64){
        return drbd();
    } else {
       if(random <= 0.81){
            return drpm();
        }
        else {
            return drco();
        }
    }
}