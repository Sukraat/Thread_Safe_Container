#include <stdio.h>
#include <pthread.h>
#include "list.h"

struct num{
	int *nums;
	int len;
};

void *operate(void *arg)
{

	pthread_mutex_t insMutex = PTHREAD_MUTEX_INITIALIZER;

	pthread_mutex_lock(&insMutex);
	struct num *NS = (struct num*)arg;
	int *N; 
	N = NS->nums;
	int size = NS->len;

	struct list *lst = getListNode();


	for(int i=0;i<size;++i){
		int no = *(N+i);
		
		insert(lst,no);
	}
	
	printf("\nlist\n");
	traverse(lst);
	pthread_mutex_unlock(&insMutex);
	
}

int main(int argc,char **argv){
	
	pthread_t threads[4];
	int arr1[] = {9,4,6,7,8,3};
	int arr2[] = {91,23,45,67,89};
	int arr3[] = {80,82,83,84};
	int arr4[] = {5,10,15};

	int len1 = (int)sizeof(arr1)/sizeof(arr1[0]);
	int len2 = (int)sizeof(arr2)/sizeof(arr2[0]);
	int len3 = (int)sizeof(arr3)/sizeof(arr3[0]);
	int len4 = (int)sizeof(arr4)/sizeof(arr4[0]);

	struct num nstruct[4];
	struct num *nsptr;
	nstruct[0].nums = arr1;
	nstruct[0].len = len1;
	nstruct[1].nums = arr2;
	nstruct[1].len = len2;
	nstruct[2].nums = arr3;
	nstruct[2].len = len3;
	nstruct[3].nums = arr4;
	nstruct[3].len = len4;

	int p;

	for(int i=0;i<4;++i){
		nsptr = &nstruct[i];
		p = pthread_create(&threads[i],NULL,operate,(void *)(nsptr));	
		if(p<0){
			printf("\n error\n");
		}else{
			printf("\n thread %d starting\n",i+1);
		}

//		pthread_join(threads[i],NULL);
	}

	for(int j=0;j<4;++j){
		pthread_join(threads[j],NULL);
	}
	return 0;
}
