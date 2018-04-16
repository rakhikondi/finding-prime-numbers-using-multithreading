#include<stdio.h>
#include<math.h>
#include<pthread.h>
int check_prime(int n)
{
    int flag=1;

     for(int i=2;i<=n/2;i++)
     {
         if(n%i==0)
         {
            flag=0;
            break;
         }
     }
     return flag;
}

void *print_prime(void *n)
{
  int *num=(int *)n;
  for(int i=2;i<*num;i++)
  {
      if(check_prime(i)==1)
         printf("%d ",i);
  }
  pthread_exit(NULL);
}
int main()
{
  int n;
  printf("Enter the value of n :\n");
  scanf("%d",&n);
  pthread_t prime_thread;
  pthread_create(&prime_thread,NULL,print_prime,(void *)&n);
  pthread_join(prime_thread,NULL);
  return 0;
}
