/*Use looping to write a program to print a pattern as follows.*/

#include <stdio.h>
#include <Windows.h>
#include <ctype.h>
#include <stdlib.h>

int main(){
	int NumOfChar,horizonNum;
	do{
		fflush(stdin);
		printf("How many characters you want to show on the first(top) level? \n");
		scanf_s("%d",&NumOfChar);
		horizonNum = NumOfChar;
	}while(NumOfChar <= 0 || isdigit(NumOfChar));
	for(int i = 0;i < NumOfChar;i++){
		for(int j = horizonNum;j > 0;j--){
			printf("%s",j % 2 ? "*":"#");//#
			/*if(j%2)
				printf("*");
			else
				printf("#");*/
		}
		horizonNum--;
		printf("\n");
	}
	system("pause");
	return 0;
}

/* #The reason of why it can use '%s' but not '%c'is not clear. 
	But the ASCII codes of '*' , '#' , 'L' and 'P' are all 16.*/
