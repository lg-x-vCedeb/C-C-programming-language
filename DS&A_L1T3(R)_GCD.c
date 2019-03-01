//This is to compute the greatest common divisor (GCD) of two natural numbers 
//using recursion.
//Author: Douglas
//Student_ID: l630003039

#include <stdio.h>
#include <Windows.h>

int GCD(int x, int y) {

	//-Base, if y = 0: GCD(x, 0) = x;
	if (y == 0) {
		return x;
	}

	//Step, if y > 0: GCD(x, y) = GCD(y, x%y);
	if (y > 0) {
		return GCD(y, x%y);
	}
}

int main() {
	int x, y, m_number, GCD_result;//m_number is the middle_number as x deliver to y
	
	//IO
	printf("The greatest common divisor (GCD) computation:\n    Please input two natural numbers.\n");
	while (true)
	{
		scanf_s("%d", &x);
		printf("and\n");
		scanf_s("%d", &y);
		if (x < 0 || y < 0) {
			printf("Warning: Please input two natural numbers.\n");//detect whether they are the natural numbers.
		}
		else
			break;
	}

	//Given x >= y
	if (x < y) {
		m_number = x;
		x = y;
		y = m_number;
	}

	//Using recursion function
	GCD_result = GCD(x, y);

	printf("The greatest common divisor of %d and %d is %d.\n", x, y, GCD_result);
	system("pause");
	return 0;
}
