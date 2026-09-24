
#include <stdio.h>

	//Funcion con paso por valor
int obtenerColumna(char evento){
    if (evento == 'C') return 0;
    if (evento == 'I') return 1;
    if (evento == 'N') return 2;
    if (evento == 'B') return 3;
    return -1;
}
	//Funcion  con  paso por referencia
void sumarEvento(int *celda){
    if (celda != NULL){
        (*celda)++;
    }
}

int main(){
	//Arreglo unidimencional
    int equipos[6] = {0, 1, 1, 1, 1, 0};
    char eventos[6] = {'C', 'I', 'I', 'I', 'N', 'C'}; //'C'= Acceso correcto,'I'= Contraseña incorrecta,'N'= Usuario inexistente,'B'= Acceso bloqueado.
	//Arreglo bidimencional
    int matriz[2][4] = {0};
	//Apuntadores y Aritmetica de Apuntadores
    int *ptr_eq = equipos;
    char *ptr_ev = eventos;

    for(int i=0; i<6; i++){
       int eq = *(ptr_eq + i);
       char ev = *(ptr_ev + i);
       int col = obtenerColumna(ev);
       if (col != -1) {
          sumarEvento(&matriz[eq][col]);
       }
    }

    printf("__Registro de eventos__\n");
    for(int i=0; i<6; i++) {
	printf("Evento %d | Equipo: PC-0%d | Tipo: %c\n", i + 1, equipos[i] + 1, eventos[i]);
    }
    printf("\n__Mapping de Columnas__\n");
    for (int i=0; i<6; i++){
        int col = obtenerColumna(eventos[i]);
        printf("El evento '%c' se guarda en la columna; %d\n", eventos[i], col);
    }
    printf("\n__Matriz__\n");
    printf("Equipo | Correctos | Contraseña Incorrecta | Usuario inexistente | Bloqueados | Total Fallos | Estado\n");
    for (int i=0; i<2; i++){
        int correctos = matriz[i][0];
	int incorrectos = matriz[i][1];
	int inexistentes = matriz[i][2];
	int bloqueados = matriz[i][3];
	int total_fallos = incorrectos + inexistentes;
	char *estado;
	if (total_fallos > 3){
	    estado = "Sospechoso";
	} else {
	    estado = "Normal";
	}
        printf("PC-0%d  | %-9d | %-10d            | %-10d          | %10d | %12d | %s\n",i + 1,correctos,incorrectos,inexistentes, bloqueados, total_fallos, estado);
    }

    return 0;
}

