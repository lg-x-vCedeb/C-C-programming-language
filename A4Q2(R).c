/*	 Write a program to check if the input positive integer is a prime number. If it is a prime
**	number, display the message “The input number is a prime number”; otherwise,
**	calculate its biggest divisor (except itself) and output it. For example, if the input is 18, its
**	biggest divisor is 9.
**	Requirements:
**	● The program contains three functions: main, prime, and biggestDivisor.
**	● The main function reads the number and outputs results.
**	● The function prime is to check if a number is prime.
**	● The function biggestDivisor is to calculate the biggest divisor of a number
**	and return it.
*/

#include <stdio.h>
#include <Windows.h>
#include <ctype.h>
bool prime(int a);
int biggestDivisor(int b);

int main(){
	int times = 1;
	int	BDivisor = 1;
	int TestNum;
	while(printf("This is your %d%s time%s to check the numbers.\n",times,times % 10 == 1 ? "st" : times % 10 == 2 ? "nd" : times % 10 > 3 ? "th" : "rd",times > 1 ? "s" : ""))
	{
		scanf_s("%d",&TestNum);
		if(isdigit(TestNum) == 0 && TestNum > 0){
			if(prime(TestNum) == false){
				BDivisor = biggestDivisor(TestNum);
				printf("%d is a not prime number and its biggest divisor is %d.\n",TestNum,BDivisor);
			}
			else
				printf("%d is a prime number.\n",TestNum);
		}
		if(TestNum <= 0){
			printf("POSITIVE NUMBER!\n");
			continue;
		}
		times++;
		printf("The times of checking can not exceed 99.\n");
		if(times >= 100)
			break;
	}
	system("pause");
	return 0;
}

bool prime(int a){
	int sign = 0;
	if(a <= 2)
		return true;
	if(a > 2){
		for(int i = 2;i < a;i++){
			if(a % i == 0){
				sign = 1;
				break;
			}
		}
	}
	return sign == 1 ? false : true;
}

int biggestDivisor(int b){
	int num = 1;
	for(int k = 2;k < b;k++){
		if(b % k == 0)
			num = k;
	}
	return num;
}
