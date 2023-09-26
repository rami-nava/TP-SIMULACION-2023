
#define CANTIDAD_MAQUINAS 15

// Condiciones iniciales
 double t = 0;  //tiempo actual
int cm = CANTIDAD_MAQUINAS;    //cantidad de maquinas
int pmd;    //cantidad trabajadores
 double tr[CANTIDAD_MAQUINAS]; //tiempo de reparacion de cada maquina
 double *tc;  //vector tiempo comprometido de cada maquina
double trPor[CANTIDAD_MAQUINAS] = {0.06, 0.12,0.2,0.26,0.33,0.4,0.45,0.51,0.58,0.64,0.7,0.78,0.87,0.93,1}; //porcentajes de rotura de maquina
 double tf; //tiempo final
 double tpa = 0; 
float sto = 0;
 double ster = 0;
 double sta = 0;
 int ca = 0;
 double da = 0;
 double pto = 0;
 double pter = 0;
 double pta = 0;

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
    tc = (double*)malloc(pmd*sizeof(double));

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