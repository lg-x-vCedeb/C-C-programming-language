/*Write a program to read one character and decide if it is a digit, an English letter or others.
Give the corresponding display message.*/

#include <stdio.h>
#include <Windows.h>
#include <ctype.h>

int main(){
	char test;
	printf("Please input a character: \n");
	scanf_s("%c",&test,sizeof(test));
	if(isalpha(test)){
		printf("%c is an English letter.\n",test);
	}
	else if(isdigit(test)){
		printf("%c is a digit.\n",test);
	}
	else
		printf("It's an another type of character.\n");
	system("pause");
	return 0;
}

/*Loop method:
int main(){
	char test;
	printf("Please input a character: \n");
	scanf_s("%c",&test,sizeof(test));
	if(test >= 48 && test <= 57){
		printf("%c is a digit.\n",test);
	}
	else if((test >= 65 && test <=90) || (test >= 97 && test <= 122)){
		printf("%c is an English letter.\n",test);
	}
	else
		printf("It's an another type of character.\n");
	system("pause");
	return 0;
}*/
