#pragma once

#include <stdio.h>
#include <string.h>

extern int cont;
extern int opc;
extern char rta;
extern char productos[10][70];
extern float precioProducto[10];

void menu();
void ingresarProductos();
void totalInventario();
void productoCaroYBarato();
void precioPromedio();
void buscar();

