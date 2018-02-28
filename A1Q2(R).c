//Write a program to input an integer and decide if it is an even number or an odd number.
#include <stdio.h>
#include <Windows.h>

int main() {
	int num = 0;
	printf("Please input an integer: \n");
	scanf_s("%d",&num);
	(num % 2)?(printf("It's an odd number.\n")):(printf("It's an even number.\n"));
	printf("It's an %s number.(Junde Yhi)\n", num % 2 ? "odd" : "even");
	system("pause");
	return 0;
}
//Thanks Junde for help
