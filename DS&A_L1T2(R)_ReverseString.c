//This is a program to reverse the string.
//Author: Douglas
//Student_ID: l630003039


#include <stdio.h>
#include <Windows.h>
#include <string.h>

//the chars in *str are reversed when this function completes
void reverseR(int length, char *str) {
	//length: the number of chars in *str
	char s;
	length = strlen(str);
	if (length <= 1) {
		//printf("%s", str); Doing nothing;
	}
	else if (length > 1) {
		s = *str;							//Using variable s to store the FIRST element in str[];
		*str = *(str + length - 1);			//Using tge front element to store the hind element;
		*(str + length - 1) = '\0';			//Using '\0' to cover the hind element;
		reverseR(strlen(str + 1), str + 1);	//Move the addresses of the elements to recursively calculate;
		*(str + length - 1) = s;			//Put back all the FIRST element to the hind of the first '\0'.
	}
}

int main() {
	char S_ToReverse[51];
	char S_Store[51];//String to store the source string.

	//IO
	printf("Reverse the String:\n    Please input a string (Plalindrome (Length of string is greater than 1) is not allow)\n");
	while (true)
	{
		scanf_s("%s", &S_ToReverse, sizeof(S_ToReverse));
		S_ToReverse[strlen(S_ToReverse)] = '\0';
		for (int i = 0; i <= strlen(S_ToReverse); i++) {
			S_Store[i] = S_ToReverse[i];
		}
		S_Store[strlen(S_Store)] = '\0';
		
		
		if (strlen(S_ToReverse) > 1) {

			reverseR(strlen(S_ToReverse), S_ToReverse);//Using the recursion function.

			//Checking if the string is plalindrome.
			if (strcmp(S_Store, S_ToReverse) == 0) {
				printf("Warning: Plalindrome is not allow.\nPlease input a string again.\n");
			}
			else
				break;
		}
		else
			break;
	}

	printf("String Reversed:\n%s ==> %s\n", S_Store, S_ToReverse);
	system("pause");//Pause the cmd in case the cmd shuts down immediately.
	return 0;
}