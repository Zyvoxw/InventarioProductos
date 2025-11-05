#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <stdio.h>
#include <string.h>

// Variables globales
extern int cont;
extern int opc;
extern char rta;
extern char productos[10][70];
extern float precioProducto[10];

// Prototipos de funciones
void menu();
void ingresarProductos();
void totalInventario();
void productoCaroYBarato();
void precioPromedio();
void buscar();

#endif
