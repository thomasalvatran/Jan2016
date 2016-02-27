#include <pthread.h>
#include <stdio.h>
/* Prints x’s to stderr.  The parameter is unused.  Does not return. */
  int i, count = 1200;
void* print_xs (void* unused)
{
  printf("Thread\n");
  while (1){
  // for (i = 0; i < count; ++i)
    // fputc ('x', stderr);
     printf("Thread");
    }
    //  return NULL;
}
/* The main program.  */
int main ()
{

  pthread_t thread_id;
  /* Create a new thread. The new thread will run the print_xs
     function. */
  pthread_create (&thread_id, NULL, &print_xs, NULL);
  /* Print o’s continuously to stderr. */
  while (1)
    //{} wait for nothing
  // for (i = 0; i < count; ++i)
      //  fputc ('o', stderr);
        printf("Loop");
     return 0;

}
