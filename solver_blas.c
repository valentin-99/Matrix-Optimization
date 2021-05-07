/*
 * Tema 2 ASC
 * 2021 Spring
 */
#include <cblas.h>
#include "utils.h"

/* 
 * Add your BLAS implementation here
 */
double *my_solver(int N, double *A, double *B)
{
	/* 	C = A × B × B_t + A_t × A
		aux1 = A × B
		aux2 = aux1 × B_t + 0_(NxN)
		aux3 = A_t × A + 0_(NxN)
		C = aux2 + aux3
	*/

	int i, j;
	double *C = (double *)calloc(N * N, sizeof(double));
	double *aux1 = (double *)calloc(N * N, sizeof(double));
	double *aux2 = (double *)calloc(N * N, sizeof(double));
	double *aux3 = (double *)calloc(N * N, sizeof(double));

	// aux1 <- B
	cblas_dcopy(N * N, B, 1, aux1, 1);
	// aux1 <- A x aux1 = A x B
	cblas_dtrmm(CblasRowMajor, CblasLeft, CblasUpper, CblasNoTrans,
				CblasNonUnit, N, N, 1, A, N, aux1, N);

	// aux2 <- aux1 x B_t + 0_(NxN)
	cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasTrans,
				N, N, N, 1, aux1, N, B, N, 0, aux2, N);

	// aux <- A
	cblas_dcopy(N * N, A, 1, aux3, 1);
	// aux3 <- A_t x aux3 = A_t x A
	cblas_dtrmm(CblasRowMajor, CblasLeft, CblasUpper, CblasTrans,
				CblasNonUnit, N, N, 1, A, N, aux3, N);

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
