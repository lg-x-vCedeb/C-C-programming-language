
/*Write a program, to read a sequence of integers which end at -1. Store them in an array. Then
call a sub-function average to calculate the average of the input integers (-1 excluded).
Assume that the number of integers (-1 is not included) is no greater than 50.*/

#include <stdio.h>
#include <Windows.h>
#include <string.h>
#include <ctype.h>
#define SEQLENGTH 51
//float averageSI(int *str);(For tiring code, here is more concise.)

int main(){
	int SeqOfInt[SEQLENGTH];
	int TotalOfInt = 0;
	int NumOfSeqInt = 0;
	for(int i = 0;i < SEQLENGTH;i++){
		printf("Please input a sequence of integers.(Input -1 to end)\n");
		scanf_s("%d",&SeqOfInt[i],sizeof(SeqOfInt[i]));
		if(isalpha(SeqOfInt[i])){
			printf("Be careful: integers!!!\n");
			continue;
		}
		else if(SeqOfInt[i] == -1){
			SeqOfInt[i+1] = '\0';
			break;
		}
		else{
			TotalOfInt += SeqOfInt[i];
			NumOfSeqInt++;
		}
	}
	printf("The average of the integer sequence ");
	for(int j = 0;j < NumOfSeqInt;j++)
		printf("%d,",SeqOfInt[j]);
	printf("is %f",(float)TotalOfInt / (float)NumOfSeqInt);
	system("pause");
	return 0;
}
