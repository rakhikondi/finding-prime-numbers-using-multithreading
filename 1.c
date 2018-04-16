#include<stdio.h>
#include<conio.h>
#include<pthread.h>
int d;
void *primenum(void *a );
void prime(int );
main()
{
 int m;
 int a;
 int flag=0;
 printf("enter the value ");
 scanf("%d",&a);
 int *k=&a;
 d=a;
 pthread_t tid;
 
 while(*k>1)//while loop
 {
   
    pthread_create(&tid,NULL,primenum,(void *)k);
    
pthread_join(tid,NULL);

    *k--;  
}
printf("\nthread created");
int l=a-1;
printf("\nprime numbers less than your number");
while(l>1)
{

	prime(l);
	l--;
}
getch();
}
void  *primenum(void *j)
    {
	
 	int i,flag=0;
 	int *k;
	 k=(int *)j;
	 
 	for(i=2;i<=*k/2;++i)
 	{
 		if(*k%i==0)
 		{
 			flag =1;
 			break;
		}
	 }
    
    if(flag==0)
    {

 	printf("\n\nit  prime number:%d",*k);
    }
    
}

void prime(int k)
{
	int i,flag=0,c;
	

 	for(i=2;i<=k/2;++i)
 	{
 		if(k%i==0)
 		{

 			flag =1;
 			break;
		}
	 }
    
    if(flag==0)
    {
 	printf("\nit is prime number:%d",k);
    }
}

