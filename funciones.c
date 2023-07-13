#include <stdio.h>
#include "funciones.h"
#include "lecturas.h"

float calcularPrecioConIVA(float precio) {
    float porcentajeIVA = 0.12;  // 12% de IVA
    float precioConIVA = precio * (1 + porcentajeIVA);
    return precioConIVA;
}

void ingresarProducto(struct Inventario *inventario) {
    if (inventario->numProductos == MAX_PRODUCTOS) {
        printf("El inventario esta lleno. No se pueden agregar mas productos.\n");
        return;
    }

    int numIngresos;
    printf("Ingrese el numero de productos que desea ingresar: ");
    scanf("%d", &numIngresos);

    if (numIngresos <= 0) {
        printf("Numero de productos invalido.\n");
        return;
    }

    for (int i = 0; i < numIngresos; i++) {
        struct Producto nuevoProducto;

        printf("\n--- Ingresar producto %d ---\n", i + 1);
        printf("Nombre: ");
        scanf("%s", nuevoProducto.nombre);
        printf("Cantidad: ");
        scanf("%d", &nuevoProducto.cantidad);
        printf("Precio: ");
        scanf("%f", &nuevoProducto.precio);

        inventario->productos[inventario->numProductos] = nuevoProducto;
        inventario->numProductos++;
    }

    printf("Productos ingresados exitosamente.\n");
}

void editarProducto(struct Inventario *inventario) {
    if (inventario->numProductos == 0) {
        printf("El inventario esta vacio. No se pueden editar productos.\n");
        return;
    }

    int indice;
    printf("\n--- Editar producto ---\n");
    printf("Ingrese el numero de producto que desea editar (1-%d): ", inventario->numProductos);
    scanf("%d", &indice);

    if (indice < 1 || indice > inventario->numProductos) {
        printf("Numero de producto invalido.\n");
        return;
    }

    struct Producto *producto = &inventario->productos[indice - 1];

    printf("Nuevo nombre: ");
    scanf("%s", producto->nombre);
    printf("Nueva cantidad: ");
    scanf("%d", &producto->cantidad);
    printf("Nuevo precio: ");
    scanf("%f", &producto->precio);

    printf("Producto editado exitosamente.\n");
}

void eliminarProducto(struct Inventario *inventario) {
    if (inventario->numProductos == 0) {
        printf("El inventario esta vacio. No se pueden eliminar productos.\n");
        return;
    }

    int indice;
    printf("\n--- Eliminar producto ---\n");
    printf("Ingrese el numero de producto que desea eliminar (1-%d): ", inventario->numProductos);
    scanf("%d", &indice);

    if (indice < 1 || indice > inventario->numProductos) {
        printf("Numero de producto invalido.\n");
        return;
    }

    for (int i = indice - 1; i < inventario->numProductos - 1; i++) {
        inventario->productos[i] = inventario->productos[i + 1];
    }

    inventario->numProductos--;

    printf("Producto eliminado exitosamente.\n");
}

void listarProductos(struct Inventario *inventario) {
    if (inventario->numProductos == 0) {
        printf("El inventario esta vacio.\n");
        return;
    }

    printf("\n--- Lista de productos ---\n");
    for (int i = 0; i < inventario->numProductos; i++) {
        struct Producto producto = inventario->productos[i];
        printf("Producto %d:\n", i + 1);
        printf("  Nombre: %s\n", producto.nombre);
        printf("  Cantidad: %d\n", producto.cantidad);
        printf("  Precio: %.2f\n", producto.precio);
        printf("  Precio con IVA: %.2f\n", calcularPrecioConIVA(producto.precio));
        printf("\n");
    }
  
}
