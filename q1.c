
#include <pthread.h>		/* For various thread functions */
#include <math.h>		/* For sqrt                     */
#include <stdlib.h>		/* For calloc                   */
#include <assert.h>

typedef struct
{

  pthread_cond_t start_working;

  pthread_mutex_t cond_mutex;

  long max_search;
} thread_parameters_t;

typedef struct
{
  long f[2];
} factor_t;


void
print_factorization (long n, factor_t * azher)
{
  int i;
  if (azher[n].f[0])
    {
      for (i = 0; i < 2; ++i)
	if (azher[n].f[i])
	  print_factorization (azher[n].f[i], azher);
    }
  else
    printf (" %ld ", n);
}

