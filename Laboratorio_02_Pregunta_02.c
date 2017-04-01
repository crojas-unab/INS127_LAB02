/**************************************************
* PROGRAMA : Laboratorio 02 - Pregunta 02
* OBJETIVO : Impletar el uso de punteros y matrices
* Fecha creacion : 30 / 03 / 2017
* GRUPO : 
			Alex Ceverino Chuquiano
			Waldo Peyrau Morales
			Cristian Rojas Saavedra
			
* ASIGNATURA : Estructura de Datos 
* SECCION : 651
* FECHA DE ULTIMA ACTUALIZACION : 31 / 03 / 2017

***************************************************/
#include <stdio.h>
#include <stdlib.h>

//se define una estructura Matrix
typedef struct matrix{
	float **matriz_dinamica; //se crea una matriz dinamica
	int filas;
	int columnas;
	
}Matrix;
//se declara una funcion de tipo Matrix
Matrix iniciarMatriz(Matrix matriz){
	int hora = time(NULL);  
    // Semilla de rand();      
	printf("\nFila : ");
	scanf("%i",&matriz.filas);
	printf("\nColumna : ");
	scanf("%i",&matriz.columnas);
	//reserva de memmoria para las filas indicadas
	matriz.matriz_dinamica = (float**)malloc(matriz.filas*sizeof(float*));
	int i, j ; //variables de control
	for (i=0;i<matriz.filas;i++){
		//para cada fila se reserva memoria para las columnas
		matriz.matriz_dinamica[i] = (float*)malloc(matriz.columnas*sizeof(float));
	}		
	//ciclos para recorrer cada espacio de memoria dentro de la matriz
	for (i=0;i<matriz.filas;i++){
		for(j=0;j<matriz.columnas ;j++){
			//para cada espacio se le asigna con numeros ramdon
			matriz.matriz_dinamica[i][j] = rand()%100;	
		}	
	}
	//semilla para cambiar los numeros aleatorios
	srand(hora);
	return  matriz;
}

Matrix sumarMatriz(Matrix matriz_01,Matrix matriz_02){
	Matrix suma_matriz;//se declara una variable Matrix
	int fila,columna;
	//condicion para validar la suma de matrices
	//se comparan si filas y columnas son iguales 
	if (matriz_01.filas == matriz_02.filas && matriz_01.columnas == matriz_02.columnas){
		fila = matriz_01.filas;
		columna = matriz_01.columnas;
		//reserva de memmoria para las filas indicadas
		suma_matriz.matriz_dinamica = (float**)malloc(fila*sizeof(float*));
		int i,j;//variables de control
		for (i=0;i<fila;i++){
			//para cada fila se reserva memoria para las columnas
			suma_matriz.matriz_dinamica[i]=(float*)malloc(columna*sizeof(float));
		}	
		for (i=0;i<fila;i++){
			for(j=0;j<columna;j++){
				suma_matriz.matriz_dinamica[i][j] = matriz_01.matriz_dinamica[i][j] + matriz_02.matriz_dinamica[i][j];
				}
		}
		return suma_matriz;
	
	}else{
		suma_matriz.filas = 0;
		suma_matriz.columnas = 0;
		return suma_matriz;
	}	
}

//funcion para imprimir por consola las matrices
void mostrarMatriz(Matrix matriz){
	int i, j ; 
	for (i=0;i<matriz.filas;i++){
		for (j=0;j<matriz.columnas;j++){
			printf("%2.1f\t",matriz.matriz_dinamica[i][j]);
		}
		printf("\n");
	}
}

int main (int argc , char *argv[]){
	printf("SUMA DE MATRICES \n");
	printf("\nDatos matriz 1 :\n");
	Matrix matriz_01; // se declara una variable de tipo Matrix
	Matrix matriz_02; // se declara una variable de tipo Matrix
	Matrix suma_matriz;
	matriz_01 = iniciarMatriz(matriz_01);
	printf("\nMATRIZ 1 : \n");
	printf("\n");
	mostrarMatriz(matriz_01);
	printf("\nDatos matriz 2 :\n");
	matriz_02 = iniciarMatriz(matriz_02);
	printf("\nMATRIZ 2 : \n");
	printf("\n");
	mostrarMatriz(matriz_02);
	suma_matriz = sumarMatriz(matriz_01,matriz_02);
	if (suma_matriz.filas == 0 && suma_matriz.columnas == 0){
		printf("\nError!!! No se pueden sumar!!\n");		
	}else{
		printf("\nMATRIZ 2 : \n");
		printf("\n");
		mostrarMatriz(suma_matriz);
	}
	return (0);	
}

