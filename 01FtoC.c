#include <stdio.h>
#include <Windows.h>
int main(){
	float Fahr,Celsius;
	float upper,lower,step;
	upper = 300;
	lower = 0;
	step = 20;
	Fahr = lower;
	printf("The FtoC Chart\n");
	while(Fahr <= upper){
		Celsius = 5 * (Fahr - 32) / 9;
		printf("%0.3f\t\a%0.3f\n\a",Fahr,Celsius);
		Fahr = Fahr + step;
	}
	printf("hello,my first C programming world\\n\n\a");
	system("pause");
	return 0;
}
