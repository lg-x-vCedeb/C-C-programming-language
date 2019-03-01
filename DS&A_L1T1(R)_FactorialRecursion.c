//This is the program to compute factorial
//Author: Douglas 
//Student_ID: l630003039

#include <stdio.h>
#include <Windows.h>

//Using recursion function factR(int n);
long int factR(int n) {

	//-Base, if n=1: factR(1)=1
	if (n == 1) {
		return n;
	}
	//-Step, if n>1: factR(n)=n*factR(n-1);
	if (n > 1) {
		return n * factR(n - 1);
	}
}

int main() {
	int number, result;

	//IO
	printf("Factorial Computation:\n    Please input a positive integer:\n");
	while (true)
	{
		scanf_s("%d", &number);
		if (number <= 0) {
			printf("Warning: You must input a positive integer for factorial computing.\n");
		}
		else
			break;
	}

	result = factR(number);//Computing factorial

	printf("The result is %d\n", result);
	system("pause");//pause the cmd in case the cmd shuts down.
	return 0;
}