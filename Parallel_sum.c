#include<stdio.h>
#include<omp.h>
int main()
{
	int result[6];
	#pragma omp parallel num_threads(6) 
	{
		int k=omp_get_thread_num();
		int a=100*k;
		int b=100*(k+1)-1;
		int sum_s=0;
		for(a;a<=b;a++)
		{
			sum_s+=a*a; 
		}
		result[k]=sum_s; 
		printf("Thread [%d] = %d\n",k,result[k]); 
	}
	int j;
	int sum=0;
	for(j=0;j<6;j++)
	{
		sum+=result[j];  
    }
    printf("sum of the result = %d\n",sum); 
	return 0;
}

