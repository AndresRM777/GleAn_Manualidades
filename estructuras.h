#ifndef ESTRUCTURAS_H
#define ESTRUCTURAS_H

#define MAX_PRODUCTOS 100

struct Producto {
    char nombre[50];
    int cantidad;
    float precio;
};

struct Inventario {
    struct Producto productos[MAX_PRODUCTOS];
    int numProductos;
};

#endif