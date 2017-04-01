/**************************************************
* PROGRAMA : Laboratorio 02 - Pregunta 01
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
#include <math.h>
// declaracion de la estructura
typedef struct complex{
	int r;
	int i;	
}Complex;

// funcion Re que retorna la parte entera del numero complejo
int Re(Complex z){
	int a = z.r;
	return a;
}
// funcion Im que retorna la parte imaginaria del número complejo	
int Im(Complex z){
	int b = z.i;
	return b;
}
// Funcion que entrega el valor absoluto del numero complejo
float valor_absoluto(Complex x){
	int real = Re(x)*Re(x);
	int imag = Im(x)*Im(x);
	int aux = real + imag;
	float z;
	z = sqrt( aux );
	
	return z;
}
//procedimiento que imprime el conjugado del numero complejo
void conjugado(Complex z){
	
	printf("\nConjugado de x: %d + %di",Im(z),Re(z));

}	

int main(int argc , char *argv[]){
	//se inicializa la variable de tipo Complex
	Complex x;
	x.r = 10;
	x.i = 5 ;
		
	int aux ;
	//se asigna a una variable el valor de la parte entera del numero complejo
	aux = Re(x);
	printf("\nParte real de x: %d\n",aux);
	//se asigna a una variable el valor de la parte imaginaria del numero complejo
	aux = Im(x);
	printf("\nParte imaginaria de x: %d\n",aux);
	//se asigna a la variable el valor absoluto del numero complejo
	aux = valor_absoluto(x);
	printf("\nValor absoluto de x: %d\n",aux);
	// se invoca la funcion conjugado (void)
	conjugado(x);
	
	return (0);
}

