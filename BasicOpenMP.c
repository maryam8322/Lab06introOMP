#include <stdio.h>
#include <omp.h>

int main(int argc, char const* argv[]){
    int nthreads, thread_id;
     
    /*Step1.. check the parallel region scope? */
    #pragma omp parallel 
    {
      printf("Step1.. check the parallel region scope? \n");
      nthreads = omp_get_num_threads();
      thread_id = omp_get_thread_num();
      printf("I have %d thread(s) and my thread id is %d\n", nthreads, thread_id);
    }
    printf("--------\n");
    
    /*Step2.. check the parallel region scope? */
    #pragma omp parallel 
    printf("Step2.. check the parallel region scope? \n");
    nthreads = omp_get_num_threads();
    thread_id = omp_get_thread_num();
    printf("I have %d thread(s) and my thread id is %d\n", nthreads, thread_id);
    printf("--------\n");
    
    
    return 0;
}

