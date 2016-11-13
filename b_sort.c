#include <stdio.h>

void bsort(void* base, size_t num, size_t size,
		   int (*compar)(const void*, const void*)) {
	int i, j;
	char* base_char = base;
	// Estos seran nuestro valores actuales en bubble
	char* a;
	char* b;
	// Nuestro auxiliar para hacer el intercambio
	char* aux = (char*) malloc(size);
	for (i = 0; i < num-1; i++) {
		for (j = 0; j < num-1; j++) {
			// Debo admitir que me costó esto
			a = base_char + (j*size);
			b = base_char + ((j+1)*size);
			if (compar(a, b) > 0) {
				// Hacemos el intercambio
				memcpy(aux, a, size);
				memcpy(a, b, size);
				memcpy(b, aux, size);
			}
		}
	}
}
