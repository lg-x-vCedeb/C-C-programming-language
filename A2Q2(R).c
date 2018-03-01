/*Use looping to write a program to calculate 2^n+3^n, which n is a natural number. 
No function is allowed to use in the calculation.*/

#include <stdio.h>
#include <Windows.h>

int main(){
	int a,b,e;
	printf("The calculation is a^e + b^e. Please input a, b, e below.\n");
	printf("a: ");
	scanf_s("%d",&a);
	printf("b: ");
	scanf_s("%d",&b);
	printf("c: ");
	scanf_s("%d",&e);
	for(int i = 1;i < e;i++){
		a *= a;
		b *= b;
	}
	printf("The answer is %d\n",a+b);
	system("pause");
	return 0;
}
