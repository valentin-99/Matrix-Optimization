/*
 * Tema 2 ASC
 * 2021 Spring
 */
#include "utils.h"

#define MIN(i, j) (((i) < (j)) ? (i) : (j))

/*
 * Add your optimized implementation here
 */
double* my_solver(int N, double *A, double* B)
{
	/* 	C = A × B × B_t + A_t × A
		aux1 = A × B
		aux2 = aux1 × B_t
		aux3 = A_t × A
		C = aux2 + aux3
	*/

	register int i, j, k;
	register int size = N;
	register double *C = (double *)calloc(size * size, sizeof(double));
	register double *aux1 = (double *)calloc(size * size, sizeof(double));
	register double *aux2 = (double *)calloc(size * size, sizeof(double));
	register double *aux3 = (double *)calloc(size * size, sizeof(double));
	
	// aux1 <- A x B
	for (i = 0; i < size; i++)
	{
		for (k = i; k < size; k++)
		{
			for (j = 0; j < size; j++)
			{
				aux1[i * size + j] += A[i * size + k] * B[k * size + j];
			}
		}
	}

	// aux2 <- aux1 × B_t
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			for (k = 0; k < size; k++)
			{
				aux2[i * size + j] += aux1[i * size + k] * B[j * size + k];
			}
		}
	}

	// aux3 <- A_t x A
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			for (k = 0; k <= MIN(i, j); k++)
			{
				aux3[i * size + j] += A[k * size + i] * A[k * size + j];
			}
		}
	}

	// C = aux2 + aux3
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			C[i * size + j] = aux2[i * size + j] + aux3[i * size + j];
		}
	}

	free(aux1);
	free(aux2);
	free(aux3);

	return C;
}
