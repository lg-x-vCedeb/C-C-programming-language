/*Write a program to input a positive integer. If the integer is bigger than 999, then output the
message “The input is too big”; otherwise, calculate the number of digits in this input integer
and output the result.*/

#include <stdio.h>
#include <Windows.h>

int main(){
	float num;
	printf("Please input a positive number in 0 to 999.\n");
	scanf_s("%f",&num);
	while(num < 0){
		printf("Please input again.\n");
		scanf_s("%d",&num);
	}
	while(num > 999){
		printf("It's too big, please input again.\n");
		scanf_s("%d",&num);
	}
	if(num / 100 >= 1)
		printf("There are 3 digits.\n");
	else if(num / 10 >= 1)
		printf("There are 2 digits.\n");
	else
		printf("There is 1 digit.\n");
	system("pause");
	return 0;
}
