#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

void mul(double *m1, double *m2, double *res, int n) 
{   
    int i, j, k;
    for (i = 0; i < n; i++) { 
        for (j = 0; j < n; j++) {
            double dot  = 0;
            for (k = 0; k < n; k++) {
                dot += m1[i*n+k]*m2[k*n+j];
            } 
            res[i*n+j ] = dot;
        }
    }
}

int main() {
    int i, n;
    double *m1, *m2, *res, dtime;

    n=512;
    m1 = (double*)malloc(sizeof(double)*n*n);
    m2 = (double*)malloc(sizeof(double)*n*n);
    res = (double*)malloc(sizeof(double)*n*n);
    for(i=0; i<n*n; i++) { m1[i] = i; m2[i] = i; res[i] = i;}

    dtime = omp_get_wtime();
    mul(m1,m2,res, n);
    dtime = omp_get_wtime() - dtime;
    printf("no OpenMP %f\n", dtime);
    

    return 0;

}


