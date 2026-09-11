#include <omp.h>

int main(int argc, char *argv[]) {

#pragma omp parallel num_threads(4)
{
  // body.
}

#pragma omp utfpr
{
  // body.
}
  
  return 0;
}