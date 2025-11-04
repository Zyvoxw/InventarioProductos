/*Integrantes:
Fecha:
Descripcion:
*/

#include <stdio.h>
#include <string.h> 

void menu();
void ingresarProductos();
void totalInventario();
void productoCaroYBarato();
void precioPromedio();
void buscar();

int cont=0;
int opc;

char rta;
char productos[10][70];

float precioProducto[10];

int main()
{

  int opc2=0;   

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

            if (opc2!=1 && opc2!=2)
            {
              printf("Solo 1 o 2\n");
            }
            
          }while (opc2 !=1 && opc2 !=2);

} while(opc2==1);

  return 0;
}

void menu(){

  printf("Seleccione una opcion:\n");
  printf("1. Ingresar los productos y precios:\n");
  printf("2. Ver el precio total del inventario:\n");
  printf("3. Producto mas caro y mas barato:\n");
  printf("4. Precio promedio de todos los productos:\n");
  printf("5. Buscar un producto:\n");
  printf(">>");
  scanf("%d", &opc);
}

void ingresarProductos(){
  do {

    do {
    printf("Ingresar el nombre del producto num %d:\n", cont + 1);
    fflush(stdin);
    fgets(productos[cont], 70, stdin);
    int len = strlen(productos[cont]) - 1;
    productos[cont][len]= '\0';

    if (productos[cont][0] >= '0' && productos[cont][0] <= '9' )
    {
      printf("No se aceptan numeros\n");
    } else {
      break;
    } 
  }while (1);

    do
    {
      printf("Ingrese el precio del producto %s:\n", productos[cont]);
      if(scanf("%f", &precioProducto[cont]) != 1 || precioProducto[cont] < 0)
      {
        printf("Solo numeros positivos, no letras ni negativos\n");
        fflush(stdin);
      }else
      {
        break;
      }
      
    } while (1);

    cont++;
      

    if (cont < 10)
    {
      printf("Desea seguir ingresando productos (s/n) ?\n");
      fflush(stdin);
      scanf(" %c", &rta);
    }else
    {

        printf("Ya ingreso el maximo de productos\n");

      break;
    }

  } while ((rta == 's' || rta == 'S') && cont<10);


  printf("Productos ingresados: \n");
  for (int i = 0; i < cont; i++)
  {
    printf("\t%d\n-\t%s\n-\t$%.2f\n", i + 1,  productos[i], precioProducto[i]);
  }
  return;
}


void totalInventario(){

  if (cont == 0)
  {
    printf("No hay productos ingresados\n");
    return;
  }
  

  float total=0;
  for (int i = 0; i < cont; i++)
  {
    total+=precioProducto[i];
  }
  
printf("El precio total del inventario es $%.2f\n", total);

}

void productoCaroYBarato(){

  if (cont == 0)
  {
    printf("No hay productos ingresados\n");
    return;
  }

  int min=0;
  int max=0;

    for (int i = 0; i < cont; i++)
    {
      if (precioProducto[i]>precioProducto[max])
      {
        max=i;
      }

      if (precioProducto[i]<precioProducto[min])
      {
        min=i;
      }
    }

printf("-----El producto mas caro es:--------\n");
printf("\t%s\n-\t$%.2f\n", productos[max], precioProducto[max]);

printf("-----El producto mas barato es:------\n");
printf("\t%s\n-\t$%.2f\n", productos[min], precioProducto[min]);

}

void precioPromedio(){
  float suma=0;
  float promedio=0;

  if (cont == 0)
  {
   printf("No hay productos ingresados\n");
   return;
  }

    for (int i = 0; i < cont; i++)
    {
      suma+= precioProducto[i];
    }
    
    promedio=suma/cont;

    printf("El numero de productos ingresados es %d\n", cont);
    printf("El precio precio promedio es: $%.2f\n", promedio);

  
}

void buscar(){


  if (cont == 0)
    {
      printf("No hay productos ingresados\n");
      return;
    }

    char buscar[70];
    int enc=0;

      printf("Nombre del producto para buscar:\n");
      fflush(stdin);
      fgets(buscar, 70, stdin);
      int len = strlen(buscar) - 1;
      buscar[len]='\0';

    for (int i = 0; i < cont; i++)
    {
      if (strcmp(buscar, productos[i]) == 0)
      {
        printf("Producto encontrado\n");
        printf("\tNombre: %s\n - \tprecio $%.2f\n", productos[i], precioProducto[i]);
        enc=1;
        break;
      }
      
    }

    if (enc == 0)
    {
      printf("Producto no encontrado\n");
    } 

}