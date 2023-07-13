#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <stdio.h>
#include "estructuras.h"
#include "lecturas.h"

void ingresarProducto(struct Inventario *inventario);
void editarProducto(struct Inventario *inventario);
void eliminarProducto(struct Inventario *inventario);
void listarProductos(struct Inventario *inventario);

#endif