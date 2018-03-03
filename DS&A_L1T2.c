//Read in and reverse a string using recursion.

#include <stdio.h>
#include <Windows.h>
#include <string.h>
void reverseR(int length, char *str);
//void reverseP(int length, char *str);

//Recursion method:
///*
int main(){
	char TestString[51];
	printf("Please input a string (not over 50 characters)\n");
	scanf_s("%s",&TestString,sizeof(TestString));
	TestString[strlen(TestString)] = '\0';
	printf("%s =>",TestString);
	reverseR(strlen(TestString),TestString);
	printf("%s\n",TestString);
	system("pause");
	return 0;
}

void reverseR(int length, char *str){
	char c;
	length = strlen(str);
	if(length <= 1)
		printf(" *");
	else if(length > 1){
		c = *str;
		*str = *(str + length - 1);
		*(str + length -1) = '\0';
		reverseR(strlen(str + 1),str + 1);
		*(str + length -1) = c;
	}
}
//*/

/*
//Pointers method:
int main(){
	char TestString[51];
	printf("Please input a string (not over 50 characters)\n");
	scanf_s("%s",&TestString,sizeof(TestString));
	TestString[strlen(TestString)] = '\0';
	if(strlen(TestString) <= 1){
		printf("%s=>%s",TestString,TestString);
	}
	if(strlen(TestString) > 1){
		printf("%s => ",TestString);
		reverseP(strlen(TestString),TestString);
		printf("%s\n",TestString);
	}
	system("pause");
	return 0;
}

void reverseP(int length, char *str){
	int i = 0;
	char c;
	length = strlen(str);
	while(i <= length / 2 - 1){
		c = *(str + i);
		*(str + i) = *(str + length - 1 - i);
		*(str + length - 1 - i) = c;
		i++;
	}
}
*/
