#include <stdio.h>

int obtenerColumna(char evento){
    if (evento == 'C') return 0;
    if (evento == 'I') return 1;
    if (evento == 'N') return 2;
    if (evento == 'B') return 3;
    return -1;
}

int main(){

    int equipos[6] = {0, 1, 1, 1, 1, 0};
    char eventos[6] = {'C', 'I', 'I', 'I', 'N', 'C'}; //'C'= Acceso correcto,'I'= Contraseña incorrecta,'N'= Usuario inexistente,'B'= Acceso bloqueado.

    int matriz[2][4] = {0};

    printf("__Registro de eventos__\n");
    for(int i=0; i<6; i++) {
	printf("Evento %d | Equipo: PC-0%d | Tipo: %c\n", i + 1, equipos[i] + 1, eventos[i]);
    }
    printf("\n__Mapping de Columnas__\n");
    for (int i=0; i<6; i++){
        int col = obtenerColumna(eventos[i]);
        printf("El evento '%c' se guarda en la columna; %d\n", eventos[i], col);
    } 

    return 0;
}
