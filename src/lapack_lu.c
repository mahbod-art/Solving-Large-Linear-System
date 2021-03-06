#include "../include/lu_functions.h"

void lapack_lu(double *A, double *B, int n) 
{
    int i;
    int ipiv[n];
    LAPACKE_dgetrf(LAPACK_ROW_MAJOR, n, n, A, n, ipiv);

    for (i = 0; i < n; i++) 
    {
        double tmp = B[ipiv[i] - 1];
        B[ipiv[i] - 1] = B[i];
        B[i] = tmp;
    }
    
    cblas_dtrsv(CblasRowMajor, CblasLower, CblasNoTrans, CblasUnit, n, A, n, B, 1);
    cblas_dtrsv(CblasRowMajor, CblasUpper, CblasNoTrans, CblasNonUnit, n, A, n, B, 1);
}
