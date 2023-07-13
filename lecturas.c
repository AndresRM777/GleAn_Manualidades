#include <stdio.h>
#include "lecturas.h"

int leerEntero() {
    int entero;
    scanf("%d", &entero);
    return entero;
}

float leerFlotante() {
    float flotante;
    scanf("%f", &flotante);
    return flotante;
}

void leerCadena(char *cadena, int longitud) {
    fflush(stdin);
    fgets(cadena, longitud, stdin);
    if (cadena[strlen(cadena) - 1] == '\n') {
        cadena[strlen(cadena) - 1] = '\0';  // Eliminar el salto de línea del final
    }
}

char leerCaracter() {
    char caracter;
    fflush(stdin);
    scanf("%c", &caracter);
    return caracter;
}

