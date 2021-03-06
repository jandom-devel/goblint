#include<stdio.h>
#include<pthread.h>
#include<assert.h>

int glob;
pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER; 

void *t_fun(void *arg) {
  pthread_mutex_lock(&m);
  glob++; // NOWARN!
  pthread_mutex_unlock(&m);
  return NULL;
}

int main() {
  int i;
  pthread_t id;

  // Create the thread
  pthread_create(&id, NULL, t_fun, NULL);
  
  printf("Do the work? ");
  if (i) 
    pthread_mutex_lock(&m);
  printf("Now we do the work..\n");
  if (i) 
    glob++; // NOWARN!
  printf("Work is completed...");
  if (i) 
    pthread_mutex_unlock(&m);

  return 0;
}
