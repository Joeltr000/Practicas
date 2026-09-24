#include <stdio.h>

int main(){

    int equipos[6] = {0, 1, 1, 1, 1, 0};
    char eventos[6] = {'C', 'I', 'I', 'I', 'N', 'C'}; //'C'= Acceso correcto,'I'= Contraseña incorrecta,'N'= Usuario inexistente,'B'= Acceso bloqueado.

    printf("__Registro de eventos__\n");
    for(int i=0; i<6; i++) {
	printf("Evento %d | Equipo: PC-0%d | Tipo: %c\n", i + 1, equipos[i] + 1, eventos[i]);
    }

    return 0;
}
