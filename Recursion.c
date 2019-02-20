#include <stdio.h>
#include <Windows.h>

//Recursion Function.
int Recursion(int num) {
	if (num == 0) //The condition to break the recursion.
		return num;
	return num + Recursion(num - 1);
}

int main() {
	int Input_num, result;

	printf("Input a maximun (positive integer) to accumulate:\n");

	//Enter the maximun and check it whether is positive number or not.
	while (1) {
		scanf_s("%d", &Input_num);

		if (Input_num <= 0) {
			printf("Please input a positive integer.\n");
		}

		else
			break;
	}

	result = Recursion(Input_num);
	printf("The result is %d\n", result);
	system("pause");

	return 0;
}