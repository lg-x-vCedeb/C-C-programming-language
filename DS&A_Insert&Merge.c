#include <stdio.h>
#include <Windows.h>
#include <math.h>
#include <time.h>
#include "T6.h"
#define SIZE_OF_ARRAY 10

int main(void){
	double start1,start2,end1,end2;
	int *A1 = (int*)malloc(sizeof(int)*SIZE_OF_ARRAY);
	for(int i = 0;i<SIZE_OF_ARRAY;i++)
		A1[i] = rand() % 100000;
	int *A2 = A1;

#if 0
	for(int j = 0;j<10;j++)
		printf("%d\t%d\n",A1[j],A2[j]);
#endif

	start1 = clock();
	InsertionSort(A1,SIZE_OF_ARRAY);
	end1 = clock();

	start2 = clock();
	MergeSort(A2,0,SIZE_OF_ARRAY);
	end2 = clock();

	printf("The time of insert sort is %f\nThe time of merge sort is %f\n",end1-start1,end2-start2);
	system("pause");
	return 0;
}

void InsertionSort(int* A, int n){
	int num;//Transition number
	for(int i = 0; i < n - 1;i++){
		if(A[i] > A[i+1]){
			num = A[i];
			A[i] = A[i+1];
			A[i+1] = num;
		}
		else
			continue;
	}
	printf("list sorted!!\n");
}

void MergeSort(int* A, int left, int right){
	int newleft, newright;
	int center = (right-left)/2;
	if(right - left != 1){
		newright = center;
		newleft = center + 1;
		MergeSort(A,left,newright);
		MergeSort(A,newleft,right);
	}
	else if (right - left == 1 || right == left){

	}
}
