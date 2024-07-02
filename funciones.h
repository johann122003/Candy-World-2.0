#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//puntero file para inventario
FILE * fd;
//puntero file para temporal
FILE *temporal;
//puntero para lista de productos (backup)
FILE * fe;
//estructura de inventario
struct datosInventario{
  char codigo[7]; 
  char producto[25];
  char precio[5]; 
  char cantidad[5];
  char vacio[1];
}inventario;
 int pregunta;
 int espacioArreglo=0;

//estructura de lista
struct datosLista{
char codigo[50];
char nombre[25];
}lista; 
// funcion para agregar desde 0;
void nuevoarchivo (struct datosInventario inventario [100]){
  char archivo[] = "InventarioCandyWorld.dat"; 
  fd = fopen(archivo, "w");
  if (fd == NULL){
    printf("Error al ubicar el archivo!!!%s\n", archivo);
    return;
  }
  fprintf(fd, ".*.*.*.|I|N|V|E|N|T|A|R|I|O|.*.*.*.\n\n");
  fprintf(fd, "|Codigo|\t|Producto     |\t|Precio|\t|Cantidad|\n");
  fprintf(fd, "______________________________________________________________\n");
  do{
  int i=0;
  printf("\nCodigo Producto: "); 
    scanf("%s",inventario[i].codigo);
  printf("\nProducto: "); 
    scanf("%s",inventario[i].producto);
  printf("\nPrecio: $ "); 
    scanf("%s",inventario[i].precio);
  printf("\nCantidad: "); 
    scanf("%s",inventario[i].cantidad);
    fprintf(fd, " %s   \t%s     \t$%s    \t\t%s\n", inventario[i].codigo, inventario[i].producto,inventario[i].precio,inventario[i].cantidad);
     fprintf(fd,"______________________________________________________________\n");
  printf("\nDesea Ingresa mas productos? (si -> 1)  (2 -> no) : "); 
  scanf("%d",&pregunta);
  printf("\n___________________________________\n");
  i++;
  espacioArreglo+=i-1;
  } while (pregunta == 1);
  fclose(fd);
}




// funcion para agregar desde lo ultimo :
void agregar (struct datosInventario inventario [100]){
  char archivo[] = "InventarioCandyWorld.dat";
  fd = fopen(archivo, "a");
  if (fd == NULL){
    printf("Error al ubicar el archivo!!!%s\n", archivo);
    return;
  }
  do{
  int i = espacioArreglo;
  printf("\nCodigo Producto: "); 
    scanf("%s",inventario[i].codigo);
  printf("\nProducto: "); 
    scanf("%s",inventario[i].producto);
  printf("\nPrecio: $ "); 
    scanf("%s",inventario[i].precio);
  printf("\nCantidad: "); 
      scanf("%s",inventario[i].cantidad);
    
    fprintf(fd, " %s   \t%s    \t$%s    \t\t%s\n", inventario[i].codigo, inventario[i].producto,inventario[i].precio,inventario[i].cantidad);
    fprintf(fd,"______________________________________________________________\n");
  printf("\nDesea Ingresa mas productos? (si -> 1)  (2 -> no) : "); 
  scanf("%d",&pregunta);
  i++;
  } while (pregunta == 1);
  fclose(fd);
}


// funcion para editar
void editar (struct datosInventario inventario [100]){
  int editado = 0;
  char codigo [10];
  char linea [100];
  char archivo[] = "InventarioCandyWorld.dat";
  char archivoT[] = "temporal.dat"; 
  FILE *fd = fopen(archivo, "r+"); // Abre el archivo en modo lectura/escritura

  if (fd == NULL) {
      printf("Error al ubicar el archivo!!!\n");
      fclose(fd);
      return;
  } 
  FILE *temporal = fopen(archivoT, "w");
  if (temporal == NULL) {
      printf("Error al ubicar el archivo!!!\n");
      fclose(fd);
      return;
  } 
      printf("Ingrese el codigo del producto que desea editar:\n");
      scanf("%s", codigo);


     while (fgets(linea, sizeof(linea), fd) != NULL) {
       if (strstr(linea, codigo) == NULL) {
           fprintf(temporal, "%s",linea);
       } else {
           int i = espacioArreglo;
           printf("\nNuevo Codigo Producto: "); 
             scanf("%s",inventario[i].codigo);
           printf("\nNuevo Producto: "); 
             scanf("%s",inventario[i].producto);
           printf("\nNuvo Precio: $ "); 
             scanf("%s",inventario[i].precio);
           printf("\nNueva Cantidad: "); 
               scanf("%s",inventario[i].cantidad);

             fprintf(temporal, " %s   \t%s    \t$%s    \t\t%s\n", inventario[i].codigo, inventario[i].producto,inventario[i].precio,inventario[i].cantidad);
           editado = 1;
       }
     }

     fclose(fd);
     fclose(temporal);
    if (editado>0) {
      remove(archivo);
      // renombramos el archivo temporal al nombre del archivo original
      rename("temporal.dat", archivo);

    } else {
      remove("temporal.dat");
    }

}

// funcion para eliminar
void eliminar() {
    int eliminado = 0;
    char codigo [10];
    char linea [100];
    char archivo[] = "InventarioCandyWorld.dat";
    char archivoT[] = "temporal.dat"; 
    FILE *fd = fopen(archivo, "r+"); // Abre el archivo en modo lectura/escritura

    if (fd == NULL) {
        printf("Error al ubicar el archivo!!!\n");
        fclose(fd);
        return;
    } 
    FILE *temporal = fopen(archivoT, "w");
    if (temporal == NULL) {
        printf("Error al ubicar el archivo!!!\n");
        fclose(fd);
        return;
    } 
        printf("Ingrese el codigo del producto que desea eliminar:\n");
        scanf("%s", codigo);
      
       while (fgets(linea, sizeof(linea), fd) != NULL) {
         if (strstr(linea, codigo) == NULL) {
             fprintf(temporal, "%s",linea);
         } else {
             eliminado = 1;
         }
       }

       fclose(fd);
       fclose(temporal);
      if (eliminado>0) {
        remove(archivo);
        // renombramos el archivo temporal al nombre del archivo original
        rename("temporal.dat", archivo);
       
      } else {
        remove("temporal.dat");
      }
    
}



// funcion para leer el archivo**
void visualizar (){
  int c;
   char archivo[] = "InventarioCandyWorld.dat";
   fd = fopen(archivo, "r");

   if (fd == NULL){
       printf("Error al ubicar el archivo!!!\n");
   }
   while((c=fgetc(fd))!=EOF){
       if (c=='\n'){
           printf("\n");
       }else{
           putchar(c);
       }
   }
   fclose(fd);
}


//LISTAAAAAAAAAAAAAAAAAAAAAAAAAAAA
void listado(){char archivolista[] = "Lista Backup.dat"; 
  int pregunta;
  int opclista;
   printf("\n.*.*.*.|L|I|S|T|A|backup.*.*.*.\n\n");
   printf("Ingresar |[1]AGREGAR|[2]LEER| -> ");
   scanf("%d", &opclista);
   printf("\n___________________________________");
   if(opclista == 1){
     int codigoacceso;
     WrongCode:
     printf("\nCódigo Acceso: ");
     scanf("%d", &codigoacceso);
  fe = fopen(archivolista, "a");   
     if(codigoacceso == 007){
  if (fe == NULL){
    printf("ERROR: No se puede ubicar el archivo\n");
    return;
  }
 
  do{
    printf("\n|CODIGO PRODUCTO| "); 
    scanf("%s", lista.codigo);

    printf("\n|NOMBRE PRODUCTO|"); 
    scanf("%s", lista.nombre);
    fprintf(fe, "|*| %s   \t%s\n", lista.codigo, lista.nombre);
    fprintf(fe,"\n___________________________________\n");
    printf("\n¿Ingresar más productos?  Si[1] - No[0] -> ");
    scanf("%d",&pregunta);
    printf("\n___________________________________\n");
  }while(pregunta == 1);
  fclose(fe);}
   //para leer archivo
              }else if(opclista == 2){int c;
                  char archivolista[] = "Lista Backup.dat";
                  fe = fopen(archivolista, "r");

                  if (fe == NULL){
                      printf("Error al ubicar el archivo!!!\n");

                  }

                  while((c=fgetc(fe))!=EOF){
                      if (c=='\n'){
                          printf("\n");
                      }else{
                          putchar(c);
                      }
                  }
                  fclose(fe);
                      }else{
                    goto WrongCode;}
                    }