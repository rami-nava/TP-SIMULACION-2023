#define CANTIDAD_TRABAJADORES 7

#define CANTIDAD_MAQUINAS 15

// Condiciones iniciales
int t = 0;  //tiempo actual
int cm = CANTIDAD_MAQUINAS;    //cantidad de maquinas
int pmd = 7;    //cantidad trabajadores
int tr[CANTIDAD_MAQUINAS]; //tiempo de reparacion de cada maquina
int tc[CANTIDAD_TRABAJADORES];  //tiempo comprometido de cada maquina
double trPor[CANTIDAD_MAQUINAS] = {0.06, 0.12,0.2,0.26,0.33,0.4,0.45,0.51,0.58,0.64,0.7,0.78,0.87,0.93,1}; //porcentajes de rotura de maquina
int tf = 43200; //tiempo final
int tpa = 0; 
int sto = 0;
int ster = 0;
int sta = 0;
int ca = 0;
int da = 0;
int pto = 0;
int pter = 0;
int pta = 0;

void inicializarTRyTC(){
    // Inicializo vector en 0
    for (int i = 0; i<CANTIDAD_MAQUINAS; i++){
        tr[i] = 0;
    }
    
    for (int i = 0; i<CANTIDAD_TRABAJADORES; i++){
        tc[i] = 0;
    }
}