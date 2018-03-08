/*		Read a line of sentence of English words and change the first letter of each word to
**	upper case and then output the changed sentence. Assume that the number of	
**	characters in the sentence is less than 100. The program includes a function which does
**	the case change for a sentence.
**	The words in the sentence are separated by a space. A sample input is as follows:
**					the Quick fox jumps over the Lazy DOG
**	And the corresponding output is:
**					The Quick Fox Jumps Over The Lazy DOG
*/

#include <stdio.h>
#include <Windows.h>
#include <string.h>
#include <ctype.h>
#define SETCHAR 101

int main(){
	char Sentence[SETCHAR];
	printf("Please input a sentence to change its words' first lowercases.\n");
	scanf_s("%[^\n]",Sentence,sizeof(Sentence));
	Sentence[strlen(Sentence)] = '\0';
	//printf("%d\n",strlen(Sentence));
	//printf("%s\n",Sentence);
	for(int i = 0;i < strlen(Sentence);i++){
		if(isalpha(Sentence[0]) && (Sentence[0] >= 'a' && Sentence[0] <= 'z'))
			Sentence[0] -= (char)32;
		if(Sentence[i - 1] == ' ' && isalpha(Sentence[i]) && (Sentence[i] >= 'a' && Sentence[i] <= 'z'))
			Sentence[i] -= (char)32;
		printf("%c",Sentence[i]);
	}
	system("pause");
	return 0;
}
