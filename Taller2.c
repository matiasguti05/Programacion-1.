#include "stdio.h"

#define MAX_FILA 100
#define MAX_COL 100

int main(){
    float matriz[MAX_FILA][MAX_COL];
    int fila,col;
    do{
        printf("ingrese el numero de filas:");
        scanf("%d",&fila);
    }while(fila<1   ||  fila>100);
    do{
        printf("ingrese el numero de columnas:");
        scanf("%d",&col);
    }while(col<1   ||  col>100);

    printf("Ingreso de datos:\n");
    for(int i=0; i<fila; i++){
        for(int j=0; j<col; j++){
            printf("matriz[%2d][%2d]:",i,j);
            scanf("%f",&matriz[i][j]);
        }
    }

    printf("Imprimir matriz\n");
    for(int i=0;i<fila;i++){
        for(int j=0; j<col;j++){
            printf("%5.2f",matriz[i][j]);
        }
        printf("\n");
    }
}