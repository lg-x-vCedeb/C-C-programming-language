#include <stdio.h>
#include <windows.h>
#define LOWER 0
#define UPPER 300
#define STEP 20
int main(){
	int Fahr;
	printf("Fahr\tCelsiuss\b \n");/*\b和\n空格问题未知，必须有空格？？*//*\b for printf is equal to "Backspace"*/
	for (Fahr = LOWER; Fahr <= UPPER; Fahr = Fahr + STEP){
		int Celsius;
		Celsius = 5 * (Fahr - 32) / 9;
		printf("%d\t%d\n",Fahr,Celsius);
	}
	system("pause");
	return 0;
}
