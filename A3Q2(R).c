/*Write a program, using %s to read a string and then find and print out the English letters only.
Assume the number of chars in the string is less than 50.*/

#include <stdio.h>
#include <Windows.h>
#include <string.h>
#include <ctype.h>

int main(){
	char sentence[51];
	int NumOfLetter = 0;
	printf("Please input a sentence.\n");
	scanf_s("%s",&sentence,sizeof(sentence));
	for(int i = 0;i < strlen(sentence);i++){
		if(isalpha(sentence[i])){
			printf("%c",sentence[i]);
			NumOfLetter++;
		}
	}
	printf("\n");
	printf("There %s %d English letter%s\n",NumOfLetter > 1 ? "are" : "is",NumOfLetter,NumOfLetter > 1 ? "s." : ".");
	system("pause");
	return 0;
}
