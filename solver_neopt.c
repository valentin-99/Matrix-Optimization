/*
 * Tema 2 ASC
 * 2021 Spring
 */
#include "utils.h"

#define MIN(i, j) (((i) < (j)) ? (i) : (j))

/*
 * Add your unoptimized implementation here
 */
double* my_solver(int N, double *A, double* B)
{
	/* 	C = A × B × B_t + A_t × A
		aux1 = A × B
		aux2 = aux1 × B_t
		aux3 = A_t × A
		C = aux2 + aux3
	*/

	int i, j, k;
	double *C = (double *)calloc(N * N, sizeof(double));
	double *aux1 = (double *)calloc(N * N, sizeof(double));
	double *aux2 = (double *)calloc(N * N, sizeof(double));
	double *aux3 = (double *)calloc(N * N, sizeof(double));
	
	// aux1 <- A x B
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			for (k = i; k < N; k++)
			{
				aux1[i * N + j] += A[i * N + k] * B[k * N + j];
			}
		}
	}

	// aux2 <- aux1 × B_t
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			for (k = 0; k < N; k++)
			{
				aux2[i * N + j] += aux1[i * N + k] * B[j * N + k];
			}
		}
	}

	// aux3 <- A_t x A
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			for (k = 0; k <= MIN(i, j); k++)
			{
				aux3[i * N + j] += A[k * N + i] * A[k * N + j];
			}
		}
	}

	// C = aux2 + aux3
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			C[i * N + j] = aux2[i * N + j] + aux3[i * N + j];
		}
	}

	free(aux1);
	free(aux2);
	free(aux3);

	return C;
}
