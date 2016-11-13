#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*  Crea un arreglo de enteros(en el heap) con números aleatorios
    num indica el tamaño del arreglo
    min indica el mínimo número aleatorio permitido en el arreglo
    max indica el máximo número aleatorio permitido en el arreglo
*/
int* arreglo_int(size_t num, int min, int max) {
	/* time(NULL) regresa el tiempo en segundos a partir de 1/1/1970 */
	srand(time(NULL));

	/* Creamos nuestro arreglo de ints por medio de la función calloc que
	 * lo que hace es nos reserva el tamaño en memoria del tamaño que le
	 * estamos indicando y nos regresa el apuntador al inicio.
	 * Debemos hacer un cast a un apuntador de int para ya que nos regresa
	 * un apuntador void */
	int *arreglo = (int*) calloc(num, sizeof(int));
	int i;
	for (i = 0; i < num; i++) {
		/* Vamos llenando el arreglo con numeros aleatorios.
		 * El módulo lo utilizamos para obtener un número máximo aleatorio, por
		 * eso obtenermos la diferencia entre max y min para y después sumamos
		 * con min para que regrese a ese mismo intervalo */
		arreglo[i] = (rand() % (max-min+1)) + min;
	}
	return arreglo;
}


/*  Crea un arreglo de doubles(en el heap) con números aleatorios
    num indica el tamaño del arreglo
    min indica el mínimo número aleatorio permitido en el arreglo
    max indica el máximo número aleatorio permitido en el arreglo
*/
double* arreglo_double(size_t num, double min, double max) {
	/* Igual que en la función anterior */
	srand(time(NULL));

	/* Ahora creamos el arreglo de doubles */
	double *arreglo = (double*) calloc(num, sizeof(double));
	double diferencia = max-min, division = RAND_MAX / diferencia;
	int i;
	for (i = 0; i < num; i++) {
		/* Obtenemos el aleatorio ahora usando doubles mediante la division
		 * del aleatorio y la suma del min para que entre en el intervalo*/
		arreglo[i] = min + (rand() / division);
	}
	return arreglo;
}
