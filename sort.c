#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>
int array_ptr[10];
int b[10];
int c[5],d[5];
int low=0,high=9,high1=4;
void *run(void *array_ptr);
void *run1(void *array_ptr);



void merge1(int low, int mid, int high1) {
   int l1, l2, i;

   for(l1 = low, l2 = mid + 1, i = low; l1 <= mid && l2 <= high1; i++) {
      if(c[l1] <= c[l2])
        d[i] = c[l1++];
      else
         d[i] = c[l2++];
   }
   
   while(l1 <= mid)    
      d[i++] = c[l1++];

   while(l2 <= high1)   
      d[i++] = c[l2++];

   for(i = low; i <= high1; i++)
     {
	   c[i] = d[i];
  }
	  
}

void mergesort1(int low,int high1) {
   int mid;
   	int *elements = (int*)c; 
   	
   if(low < high1) {
      mid = (low + high1) / 2;
      mergesort1(low, mid);
      mergesort1(mid+1, high1);
      merge1(low, mid, high1);
   } else { 
      return;
   }   
}
int c1[5],d1[5];

void *merging(void * array_ptr)
{
	        int i = 0;

       int j = 0;
int k=0;
 int m=5,n=5;

        while (i < m && j < n) 

        {

            if (c1[i] <d1[j]) 

            {

                b[k] = c1[i];

                i++;

            }

 

            else 

            {

                b[k] = d1[j];

                j++;

            }

            k++;

        }

 

        if (i >= m) 

        {

            while (j < n) 

            {

                b[k] = d1[j];

                j++;

                k++;

            }

        }
        if (j >= n) 

        {

            while (i < m)

            {

                b[k] = c1[i];

                i++;

                k++;

            }

        }
        printf("\n After merging: \n");
		for (i = 0; i < m + n; i++) 
        {
            printf("\n%d", b[i]);

        }

    }

int main()
{
		int n = 10; 
printf(" 10 elements you want to enter\n");
	for(int i=0;i<n;i++)
	{
	scanf("%d",&array_ptr[i]);
	}
	for(int i=0;i<5;i++)
	{
	c[i]=array_ptr[i];
	}
	
	  printf("\n 2 sorted subarray are:\n ");

	
		pthread_t t1,t2,t3;
		pthread_create(&t1, NULL, run, (void *)c);
 pthread_join( t1,NULL);

      for(int i=0;i<5;i++)
 {printf("%d\t",c[i]);
 c1[i]=c[i];
 }
  printf("\n");

 for(int i=0;i<5;i++)
	{
		c[i]=array_ptr[i+5];
	}
 	pthread_create(&t2, NULL, run, (void *)c);
 pthread_join( t2,NULL);
     for(int i=0;i<5;i++)
 {printf("%d\t",c[i]);
 d1[i]=c[i];
 }

 
 	pthread_create(&t3, NULL, merging,(void*)array_ptr);
 pthread_join( t3,NULL);
 
 
}
void *run(void *c)
{
	mergesort1(low,high1);
}