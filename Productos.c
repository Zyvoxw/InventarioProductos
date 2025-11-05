#include <stdio.h>
#include "Funciones.h"  

int main()
{
    int opc2 = 0;   

    do {
        menu();

        switch (opc)
        {
        case 1:
            ingresarProductos();
            break;

        case 2:
            totalInventario();
            break;

        case 3:
            productoCaroYBarato();
            break;
        
        case 4:
            precioPromedio();
            break;
        
        case 5:
            buscar();
            break;

        default:
            printf("Opcion invalida.\n");
            break;
        }

        do {
            printf("Desea seleccionar otra opcion: 1.Si / 2.No\n");
            scanf("%d", &opc2);

            if (opc2 != 1 && opc2 != 2)
            {
                printf("Solo 1 o 2\n");
            }
        } while (opc2 != 1 && opc2 != 2);

    } while (opc2 == 1);

    return 0;
}
