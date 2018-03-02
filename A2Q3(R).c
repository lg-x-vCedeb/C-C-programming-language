/*Write a program to calculate the number of digits in a positive integer and decide if this
positive integer is a perfect square.
Note: A perfect square is a number that can be expressed as the product of two equal integers.
E.g., 1=1*1, 4=2*2, 9=3*3, 16=4*4 are perfect squares but 2, 3, 8, 10 are not.*/

#include <stdio.h>
#include <Windows.h>

int main(){
	long testNum;
	int sign = 1;
	printf("Please input an positive integer to test whether it's a perfect square.(Do not over 65535(2^16-1))\n");
	scanf_s("%d",&testNum);
	if(testNum == 1){
		printf("This integer is a perfect square and the square-root is 1\n");
		sign = 0;
	}
	for(int i = 0; i <= testNum / 2;i++){
		if(testNum == i * i){
			printf("This integer is a perfect square and the square-root is %d\n",i);
			sign = 0;
		}
	}
	if(sign)
		printf("This integer is not a perfect square.\n");
	system("pause");
	return 0;
}
