#include <stdio.h>
#include <windows.h>
int main(){
	int Fahr;
	printf("Fahr\tCelsius\n");
	for(Fahr = 300;Fahr >= 0;Fahr = Fahr - 20){
		int Celsius;
		Celsius = 5 * (Fahr - 32) / 9;
		printf("%d\t%d\n\a",Fahr,Celsius);
	}
	system("pause");
	return 0;
}
