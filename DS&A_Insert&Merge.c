#include <stdio.h>
#include <Windows.h>
#include <math.h>
#include <time.h>
#include "T6.h"
#define SIZE_OF_ARRAY 1000

int main(void){
	int mnum;
	double start1,start2,end1,end2;
	int *A1 = (int*)malloc(sizeof(int)*SIZE_OF_ARRAY);
	for(int i = 0;i<SIZE_OF_ARRAY;i++)
		A1[i] = rand() % 100000;
	int *A2 = (int*)malloc(sizeof(int)*SIZE_OF_ARRAY);
	for(int j = 0;j<SIZE_OF_ARRAY;j++){
		mnum = A1[j];
		A2[j] = mnum;
	}

#if 0
	for(int j = 0;j<10;j++)
		printf("%d\t%d\n",A1[j],A2[j]);
#endif

	start1 = clock();
	InsertionSort(A1,SIZE_OF_ARRAY);
	end1 = clock();
	printf("Int list sorted\n");

	start2 = clock();
	MergeSort(A2,0,SIZE_OF_ARRAY-1);
	end2 = clock();
	printf("Mer list sorted\n");
#if 0
	for(int j = 0;j<10;j++)
		printf("%d\t%d\n",A1[j],A2[j]);
#endif
	printf("The time of insert sort is %f\nThe time of merge sort is %f\n",end1-start1,end2-start2);
	system("pause");
	return 0;
}

void InsertionSort(int* A, int n){
	int num;//Transition number
	for(int i = 0; i < n;i++){
		for(int j = 0; j < n;j++){
			if(A[i] < A[j]){
				num = A[i];
				A[i] = A[j];
				A[j] = num;
			}
			else
				continue;
		}
	}
	//printf("list sorted!!\n");
#if 0
	for(int l = 0; l < n - 1;l++)
		printf("%d ",A[l]);
#endif
}

void MergeSort(int* A, int left, int right){
	int num;
	int sign = 0;
	int newleft, newright;
	int center = (right+left)/2;
	if(right - left > 2){
		newright = center;
		newleft = center + 1;
		MergeSort(A,left,newright);
		MergeSort(A,newleft,right);
	}
	else if (right - left == 2 || right - left == 1 || right == left){
		//printf("%d\t%d\n",right,left);
		do{
			for(int j = 0;j <= center - left;j++){
				for(int k = 0;k <= center - left;k++){
					if(A[left + j] > A[right - k]){
						num = A[left + j];
						A[left + j] = A[right - k];
						A[right - k] = num;
						continue;
					}
					else
						continue;
				}
			}
			center = right;
			right += right - left;
		}while(right < SIZE_OF_ARRAY);
	}
}
