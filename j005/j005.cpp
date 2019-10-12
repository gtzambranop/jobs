#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define RESTRICCIONES	10 
#define LONGITUD		RESTRICCIONES * 2
#define COLUMNAS		7
#define FILAS			4
#define DISPONIBLES		(FILAS * COLUMNAS) - RESTRICCIONES
#define TAMAMATRIZ		7

using namespace std;


void pres();
void cls();
int menu();
int menuBus();
void imprimirBus(int [][COLUMNAS]);
bool sacarPasajero(int [][COLUMNAS]);
bool ingresarPasajero(int [][COLUMNAS]);
void busPublico();
void imprimirMatriz(float [][TAMAMATRIZ]);
void espiral();

void pres(){
	unsigned char a;

	printf("\nPresione ENTER para continuar\n");
	cin.ignore();
	a = getchar();
}

void cls(){
	if(system("cls")){ //limpiar consola windows
		system("clear"); //limpiar consola con SO basados en UNIX
	}
}

int menu(){
	int opcion	= 0;

	cls();

	printf("1) Bus de servicio publico.\n2) Espiral.\n3) Salir.\n");
	cin >> opcion;

	if((opcion > 3) || (opcion < 1)){
		opcion = menu();
	}
	return opcion;
}

int menuBus(){
	int opcion	= 0;
	
	cls();

	printf("1) Ingresar pasajero\n2) Sacar pasajero\n3) Datos de ");
	printf("ingreso y salida\n4) Valor ingresado.\n5) Salir.\n");
	cin >> opcion;
	if((opcion > 5) || (opcion < 1)){
		opcion = menuBus();
	}
	return opcion;

}

void imprimirBus(int bus[][COLUMNAS]){
	int i 	= 0,
		j 	= 0;

	printf("La siguiente matriz muestra la representacion del bus.\n");

	// For anidado que grafica el estado actual del bus
	for(i = 0; i <= (FILAS + 1); i++){
		for(j = 0; j <= COLUMNAS; j++){
			
			if((i == 0) && (j == 0)){
				printf("\t");
			}else if((i == 0) && j > 0){
				printf("%i\t", j); //indicador de las columnas
			}else if(i == 1){
				printf("--\t");
			}else if((i > 0) && (j == 0)){
				printf("%i |\t", i - 1); //indicador de las filas
			}else {
				printf("%i\t", bus[i - 2][j - 1]);
			}
		}
		printf("\n");
	}
	printf("\n");
}

bool sacarPasajero(int bus[][COLUMNAS]){
	int columna	= 0,
		fila	= 0,
		i 		= 0,
		j 		= 0;

	bool resultado;

	char cadena[16],
		 *token;

	cls();
	
	imprimirBus(bus);
	
	printf("Ingrese la coordenada del pasajero que desea sacar de la ");
	printf("siguiente manera:\nFILA COLUMNA\n");

	cin.ignore();

	//%[^\n] permite que reciba la cadena hasta que lea un salto de linea.
	scanf("%[^\n]", cadena);

	//strtok, separa la cadena por el delimitador " "
	token = strtok(cadena, " ");
	fila = atoi(token) - 1;
		
	token = strtok(NULL, " ");
	columna = atoi(token) - 1;

	// se declara false que significa error, en caso de que los datos sean 
	// ingresados correctamente el valor de esta variable cambiara.

	resultado = false;

	if((fila > FILAS) || (fila < 0) || (columna > COLUMNAS) || (columna < 0)){
		printf("La posicion ingresada es invalida.\n");
	}else{
		if(bus[fila][columna] <= 0){
			printf("No hay pasajeros en esta posicion o el espacio no esta ");
			printf("habilitado\n");
		}else{
			bus[fila][columna] = 0;
			resultado = true;
	
			printf("El pasajero ha sido sacado exitosamente.\n");
		}
	}
	return resultado;
}

/* Los asientos son llenados desde la posicion 0,0 y luego descienden hasta la
 * posicion 3,0. luego salta a la posicion 1,0 y reinicia el ciclo.
 */
bool ingresarPasajero(int bus[][COLUMNAS]){
	int columna	= 0,
		fila	= 0,
		i		= 0,
		j		= 0;
	bool resultado;

	char cadena[16],
		 *token;
	cls();

	imprimirBus(bus);
	
	printf("Ingrese la coordenada del pasajero que desea ingresar de la ");
	printf("siguiente manera:\nFILA COLUMNA\n");

	cin.ignore();

	//%[^\n] permite que reciba la cadena hasta que lea un salto de linea.
	scanf("%[^\n]", cadena);

	//strtok, separa la cadena por el delimitador " "
	token = strtok(cadena, " ");
	fila = atoi(token) - 1;
		
	token = strtok(NULL, " ");
	columna = atoi(token) - 1;

	// se declara false que significa error, en caso de que los datos sean 
	// ingresados correctamente el valor de esta variable cambiara.

	resultado = false;

	if((fila > FILAS) || (fila < 0) || (columna > COLUMNAS) || (columna < 0)){
		printf("La posicion ingresada es invalida.\n");
	}else{
		if(bus[fila][columna] != 0){
			printf("Ya hay pasajeros en esta posicion o el espacio no esta ");
			printf("habilitado\n");
		}else{
			bus[fila][columna] = 1;
			resultado = true;
		
			printf("El pasajero ha sido ingresado exitosamente.\n");
		}
	}
	return resultado;
}

void busPublico(){
	int costoPasaje	= 0,
		pActuales	= 0,
		pSacados	= 0,
		pTotales	= 0,
		ingreso		= 0,
		opcion		= 0,
		aux			= 0,
		i			= 0,
		j 			= 0,
		k			= 0;
	
	bool resultado;

	int bus[FILAS][COLUMNAS];

	/* El arreglo de restricciones contiene los pares de las coordenadas, 
	 * los cuales no podran ser utilizados en la ejecucion del programa.
	 * Este arreglo debe ser ordenado con las restricciones en orden 
	 * ascendente, es  decir, las restricciones de la fila 0 hasta la fila 3,
	 * acompanadas de el numero de columnas tambien en orden ascendente
	 * de 0 a 6.
	 */
	int noHabilitado[LONGITUD] = 
	{0,6, 1,6, 2,1, 2,2, 2,3, 2,4, 2,5, 2,6, 3,1, 3,6};
	
	costoPasaje = 2200;

	//Bucle para poblar la matriz con los valores especificados en el doc.
	for(i = 0; i < FILAS; i++){
		for(j = 0; j < COLUMNAS; j++){
			bus[i][j] = 0;
			
			/* La variable auxiliar guarda la coordenada de restriccion
			 * con mayor valor utilizada, con el fin de no recorrer toda 
			 * la cadena
			 */
			for(k = aux; k < RESTRICCIONES; k++){
				if((noHabilitado[aux*2] == i)&&(noHabilitado[aux*2 + 1] == j)){
					bus[i][j] = -1;
					aux = k + 1; 
				}
			}
		}
	}
	

	do{
		opcion = menuBus();
		resultado = false;
		cls();
		
		switch(opcion){
			case 1:
				if((pActuales >= 0) && (pActuales < DISPONIBLES)){
					resultado = ingresarPasajero(bus);

					// En caso de que el usuario ingrese mal los datos, los 
					// contadores no van a modificarse.
					if(resultado == true){
						pActuales ++;
						pTotales ++;
					}

				}else{
					printf("No hay asientos disponibles\n");
				}
				break;
			case 2:
				if(pActuales != 0){
					resultado = sacarPasajero(bus);
					
					// En caso de que el usuario ingrese mal los datos, los 
					// contadores no van a modificarse.
					if(resultado == true){
						pSacados ++;
						pActuales --;
					}
				}else{
					printf("No hay asientos disponibles\n");
				}
				break;
			case 3:
				printf("En el bus hay actualemnte %i pasajeros\n", pActuales);
				printf("A lo largo del dia han ingresado ");
				printf("%i pasajeros y han salido %i \n", pTotales ,pSacados);
				break;
			case 4:
				printf("El ingreso total ha sido: %i\n", pTotales * costoPasaje);
				break;
		}

		pres();

	}while(opcion != 5);
}

void imprimirMatriz(float matriz[][COLUMNAS]){
	int limEspiral	= 0,
		i 			= 0,
		j 			= 0;
	
	cls();
	
	limEspiral = TAMAMATRIZ - 1;

	/* Bucle anidado para imprimir matriz de espiral con sus respectivos
	 * promedios
	 */

	for(i = 0; i < TAMAMATRIZ; i++){
		for(j = 0; j < TAMAMATRIZ; j++){
			if ((j!= limEspiral) && (i != limEspiral)){	
				//%.f -> sin decimales
				printf("%.f\t", matriz[i][j]);
			}else{
				if (!((j == limEspiral) && (i == limEspiral))){	
					//%.1f -> dos decimales
					printf("%.1f\t", matriz[i][j]);
				}
			}
		}
		printf("\n");
	}
	pres();
}

void espiral(){
	int sumaColumnas	= 0,
		minColumna		= 0,
		maxColumna		= 0,
		limEspiral		= 0,
		sumaFilas		= 0,
		minFila			= 0,
		maxFila			= 0,
		columna			= 0,
		centro			= 0,
		valor			= 0,
		fila			= 0,
		tope			= 0;
		
	float matriz[TAMAMATRIZ][TAMAMATRIZ];

	limEspiral = TAMAMATRIZ - 1;
	centro = (limEspiral / 2) - 1;
	
	minColumna 	= centro;
	maxColumna 	= centro + 1;
	maxFila		= centro + 1;
	minFila		= centro;

	fila = centro + 1;
	columna = centro;
	tope = (limEspiral)*(limEspiral);
	valor ++;

	while(valor < tope){
		for(columna = minColumna; columna < maxColumna; columna ++){
			if(valor > tope) break;
			matriz[fila][columna] = valor ++;
		}

		for(fila = maxFila; fila > minFila; fila --){
			if(valor > tope) break;
			matriz[fila][columna] = valor ++;
		}

		for(columna = maxColumna; columna > (minColumna - 1); columna --){
			if(valor > tope) break;
			matriz[fila][columna] = valor ++;
		}

		for(fila = minFila; fila < (maxFila + 1); fila ++){
			if(valor > tope) break;
			matriz[fila][columna] = valor ++;
		}

		maxColumna ++;
		minColumna --;
		maxFila ++;
		minFila --;
	}
	
	/* Bucle anidado que recorre la matriz de arriba hacia abajo y va 
	 * almacenando el valor del promedio correspondiente a cada columna.
	 */
	for(fila = 0; fila < limEspiral; fila ++){
		for(columna = 0; columna < TAMAMATRIZ; columna ++){
			if(columna == limEspiral){
				matriz[fila][columna] = float(sumaColumnas) / limEspiral;
				sumaColumnas = 0;
			}else {
				sumaColumnas += matriz[fila][columna];
			}
		}
	}

	/* Bucle anidado que recorre la matriz de izquierda a derecha y va
	 * almacenando el valor del promedio correspondiente a cada fila.
	 */
	for(columna = 0; columna < limEspiral; columna ++){
		for(fila = 0; fila < TAMAMATRIZ; fila ++){
			if(fila == limEspiral){
				matriz[fila][columna] = float(sumaFilas) / limEspiral;
				sumaFilas = 0;
			}else{
				sumaFilas += matriz[fila][columna];
			}
		}
	}
	imprimirMatriz(matriz);
}

int main(){
	static int opcion	= 0;
 	do{
		opcion = menu();
		
		switch(opcion){
			case 1:
				busPublico();
				break;
			case 2:
				espiral();
				break;
		}
	}while(opcion != 3);
}
