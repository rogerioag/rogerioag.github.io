/* Compilar:
 * gcc variaveis-omp-03.c -o variaveis-omp-03.exe -fopenmp
 * ou 
 * make omp-03
 */
#include <stdio.h>
#include <pthread.h>
#ifdef _OPENMP
#include <omp.h>
#else
#define omp_get_thread_num() 0
#endif

int main() {
  int i;
  int omp_np;  /* Número de Processadores.  */
  int omp_nt;  /* Número de threads OpenMP. */
  int omp_tid; /* Id da Thread OpenMP.      */

  /* Teste 1 */
  printf("Teste 1: Sem Região Paralela ------------------------------------------------------------------------\n");
  /* Recupera os parâmetros do OpenMP utilizando as funções. */
  omp_np  = omp_get_num_procs();    /* Recupera o número de processadores. */
  omp_nt  = omp_get_num_threads();  /* Recupera o número de threads. */
  omp_tid = omp_get_thread_num();   /* recupera o id da thread OpenMP. */

  printf("OpenMP thread id: %2d, pthread id: %lu, Num. Processadores: %2d,  Num. OpenMP Threads: %2d\n", omp_tid, (long int) pthread_self(), omp_np, omp_nt);
  
  /* Teste 2 */
  printf("Teste 2: Região Paralela Padrão ---------------------------------------------------------------------\n");
  #pragma omp parallel
  {
    omp_np  = omp_get_num_procs();   /* Recupera o número de processadores. */
    omp_nt  = omp_get_num_threads(); /* Recupera o número de threads. */
    omp_tid = omp_get_thread_num();  /* recupera o id da thread OpenMP.*/
  
    printf("OpenMP thread id: %2d, pthread id: %lu, Num. Processadores: %2d,  Num. OpenMP Threads: %2d\n", omp_tid, (long int) pthread_self(), omp_np, omp_nt);
  }
  /* Teste 3 */
  printf("Teste 3: Região Paralela com num_threads(8) ---------------------------------------------------------\n");
  #pragma omp parallel num_threads(8)
  {
    omp_np  = omp_get_num_procs();   /* Recupera o número de processadores. */
    omp_nt  = omp_get_num_threads(); /* Recupera o número de threads. */
    omp_tid = omp_get_thread_num();  /* recupera o id da thread OpenMP. */
  
    printf("OpenMP thread id: %2d, pthread id: %lu, Num. Processadores: %2d,  Num. OpenMP Threads: %2d\n", omp_tid, (long int) pthread_self(), omp_np, omp_nt);
  }

  printf("Fim --------------------------------------------------------------------------------------------------\n");

  return 0;
}
