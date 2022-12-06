#include<stdio.h>
#include <stdlib.h>
#include <time.h>//Offers ramdoms values from clock

void mostrarTablero(void); 
int movimiento();

int tablero[8][8]={0};//inicializa el tablero con ceros
int horizontal[8]={2,1,-1,-2,-2,-1,1,2}; //Vector de posiciones posibles
int vertical[8]={-1,-2,-2,-1,1,2,2,1};//Vector de posiciones posibles
int x,y;//variables globales donde se guardan las posiciones



int main(){
  printf("Seleccione que posicion horizontal(Del 0 al 8 )\n");
  scanf("%d",&x );
  printf("Introduzca posicion vertical (Del 0 al 8)\n" );
  scanf("%d",&y);
  tablero[y][x]=1; //inicializa la posicion del caballo
  mostrarTablero();

  printf("Se inicia el recorrido aleatorio\n");
  srand( time( NULL ) ); //  randomiza el generador de números aleatorios mediante la función time */


  while (movimiento()) {
    movimiento();

  }

  mostrarTablero();
  printf("Movimiento = \n",movimiento );
  return 0;

} //Fin de main



/*Funcion con  for solo para mostrar que valores tiene la matriz del mostrarTablero
debido a que la matriz esta declarada de manera global, se puede acceder a ella
 desde cualquier punto del programa sin tener que declararla en la cabecera
 de la funcion. */
void mostrarTablero(void){
  for(int b=0;b<8;b++){
    for(int c=0;c<8;c++){
      printf("      %d      " ,tablero[b][c] );
    }
    printf("\n\n\n\n\n");
  }
}


/* La funcion movimiento:
    1)inicializa variable movimientos de forma estatica
      es decir aunque salga de la funcion no se borra el valor.
    2)Elige un movimiento aleatorio del 0-7.
    3)Determina si es un movimiento valido.
        *Evalua los limites en eje Y si es valido
        *Evalua en eje X si es valido
        *Evalua si la posicion no esta ocupada
        *si todo esta bien sale del while con la bandera flag=1
        *Incrimenta la variable movimiento
        *si despues de 25 repeticiones del while no encuentra una
         posicion valida sale del while con flag=1
    4)Si todo esta bien asigna la nueva posicion y la funcion retorna 1
      si no retorna 0
    */

int movimiento(){
  static int movimiento=1;
  int flag=0;
  int numMovi;
  int whilecounter=0;

  while (flag==0) {
    whilecounter++;
    numMovi=rand() % 8;
    //Bloque de codigo que evalua no caiga en movimiento no permitido
    if( !(y==0 && (numMovi==2||numMovi==1||numMovi==0||numMovi==3)) ){
      if( !(y==1 && (numMovi==2||numMovi==1)) ){
        if( !(y==7 && (numMovi==5||numMovi==6||numMovi==7||numMovi==4)) ){
          if( !(y==6 && (numMovi==5||numMovi==6)) ){
            //empezamos a revisar el eje X
            if( !(x==0 &&(numMovi==2||numMovi==3||numMovi==4||numMovi==5)) ){
              if( !(x==1 &&(numMovi==4||numMovi==3)) ){
                if( !(x==7 &&(numMovi==1||numMovi==7||numMovi==0||numMovi==6)) ){
                  if( !(x==6 && (numMovi==0||numMovi==7)) ){
                    if( tablero[y+vertical[numMovi]][x+horizontal[numMovi]]==0){
                      flag=1;
                      movimiento++;
                    }
                  }
                }
              }
            }
          }
        }
      }
    }

    if(whilecounter==25){ //Si despues de pasar 25 veces no hay posicion valida
      flag=1;             // sale del ciclo while porque no hay mas opcion
    }

  }//Fin While


  if(whilecounter<25){
    x=x+horizontal[numMovi]; //asigna las nuevas posiciones
    y=y+vertical[numMovi];
    tablero[y][x]=movimiento;
    return 1;
  } else{
    printf("Hasta aqui llego \n" );
    return 0;
   }

}//Fin movimiento()
