/*There is an array with sorted values {3, 10, 15, 30, 55, 77}. Please write a program to read an
integer from keyboard, insert this value into proper place of the array and output the
updated sorted array values.*/

#include <stdio.h>
#include <Windows.h>

int main(){
	int sorted_array[51] = {3,10,15,30,55,77};
	int insect_num,arrayLen;
	int x;
	int sign = 1;
	printf("Insect an integer to the sorted array values.\n");
	scanf_s("%d",&insect_num);
	for(int b = 0;sorted_array[b] != NULL;b++){
		if(sorted_array[b+1] == NULL)
			arrayLen = b + 1;
	}
	//printf("%d",arrayLen);
	for(int i = 0; sorted_array[i] != NULL;i++){
		if(insect_num <= sorted_array[i]){
			for(int j = arrayLen;j > i;j--){
				x = sorted_array[j];
				sorted_array[j] = sorted_array[j - 1];
				sorted_array[j + 1] = sorted_array[j - 1];
				//sorted_array[j] = sorted_array[j - 1];
			}
			sorted_array[i] = insect_num;
			sorted_array[arrayLen + 1] = '\0';
			sign = 0;
		}
	}
	if(sign == 1){
		sorted_array[arrayLen] = insect_num;
		sorted_array[arrayLen + 1] = '\0';
	}
	for(int i = 0; sorted_array[i] != NULL;i++)
		printf("%d ",sorted_array[i]);
	system("pause");
	return 0;
}
//Need research.
