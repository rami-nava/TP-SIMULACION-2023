
#define CANTIDAD_MAQUINAS 15

// Condiciones iniciales
unsigned int t = 0;  //tiempo actual
int cm = CANTIDAD_MAQUINAS;    //cantidad de maquinas
int pmd;    //cantidad trabajadores
unsigned int tr[CANTIDAD_MAQUINAS]; //tiempo de reparacion de cada maquina
unsigned int *tc;  //vector tiempo comprometido de cada maquina
double trPor[CANTIDAD_MAQUINAS] = {0.06, 0.12,0.2,0.26,0.33,0.4,0.45,0.51,0.58,0.64,0.7,0.78,0.87,0.93,1}; //porcentajes de rotura de maquina
unsigned int tf; //tiempo final
unsigned int tpa = 0; 
unsigned int sto = 0;
unsigned int ster = 0;
unsigned int sta = 0;
unsigned int ca = 0;
unsigned int da = 0;
unsigned int pto = 0;
unsigned int pter = 0;
unsigned int pta = 0;

void pedirTF(){
    int tf_meses;

    printf("Meses a simular (max~99.420): ");    //unsigned int 4 bytes
    scanf("%d", &tf_meses);

    getchar();  //limpiar buffer de \n basura

    tf = 43200*tf_meses;
}

void pedirPMD(){

    printf("Cantidad de trabajadores: ");
    scanf("%d", &pmd);

    getchar();  //limpiar buffer de \n basura
}

void inicializarTC(){

    //reservar espacio para el vector
    tc = (int*)malloc(pmd*sizeof(int));

    //inicializar los 'pmd' tiempos comprometidos en cero
    for (int i = 0; i<pmd; i++){
        tc[i] = 0;
    }

}

void inicializarTR(){
    // Inicializo vector en 0
    for (int i = 0; i<CANTIDAD_MAQUINAS; i++){
        tr[i] = 0;
    }
    
}