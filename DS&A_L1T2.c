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
	reverseR(strlen(TestString),TestString);//Using resursive function.
	printf("%s\n",TestString);
	system("pause");
	return 0;
}

void reverseR(int length, char *str){
	char c;
	length = strlen(str);
	if(length <= 1)
		printf(" *");				//Cover the final '\0'
	else if(length > 1){				
		c = *str;				//Using variable c to store the FIRST element in str[].
		*str = *(str + length - 1);		//Using the front element to store the hind element.
		*(str + length -1) = '\0';		//Using '\0' to cover the hind element.
		reverseR(strlen(str + 1),str + 1);	//Move the addresses of the elements to recursively calculate.
		*(str + length -1) = c;			//put back all the FIRST elements to the hind of the first '\0'. 
	}
}
//*/

#if 0
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
#endif
