#include "funciones.h"
int main() {
 int opcion; 
  Continue: 
  printf("\n\n_____________|M|E|N|U|_____________\n"); 
  printf("\n\n[1] *|C|R|E|A|R|*");
  printf("\n\n[2] *|A|G|R|E|G|A|R|*");
  printf("\n\n[3] *|E|D|I|T|A|R|*"); 
  printf("\n\n[4] *|E|L|I|M|I|N|A|R|*"); 
  printf("\n\n[5] *|V|I|S|U|A|L|I|Z|A|R|*"); 
  printf("\n\n[6] *|L|I|S|T|A|*");
  printf("\n\n[7] *|S|A|L|I|R|*");
  printf("\n");
  printf("\n|Opcion|-> ");
  scanf("%d", &opcion); 
  printf("\n___________________________________\n");

  if(opcion<= 7 && opcion>=1){
  switch (opcion){
    case 1: nuevoarchivo(&inventario); 
      goto Continue; 
      break;
    case 2: agregar(&inventario); 
      goto Continue;
      break; 
    case 3:editar(&inventario); 
      goto Continue; 
      break;
    case 4:eliminar(); 
      goto Continue;
      break;
    case 5: visualizar(); 
      goto Continue;
      break;  
    case 6: listado();
      goto Continue; 
      break; 
    case 7:  
      goto End; 
  }
  }else{
      printf("Ingrese una de las opciones");
      goto Continue;
    }
  End:
  return 0;
} 



