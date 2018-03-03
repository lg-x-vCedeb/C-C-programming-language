//Read in a positive number and compute its factorial using recursion.

#include <stdio.h>
#include <Windows.h>
int factR(int n);

int main(){
	int NumToCpt;
	for(;;){
		printf("What number's fatorial you want to compute?\n");
		scanf_s("%d",&NumToCpt,sizeof(NumToCpt));
		if(NumToCpt >= 1){
			printf("The %d's fatorial is %d.\n",NumToCpt,factR(NumToCpt));
			break;
		}
		if(NumToCpt < 1)
			printf("Please input positive number.");
	}
	system("pause");
	return 0;
}

int factR(int num){
	int i;
	if(num == 1)
		return 1;
	if(num > 1)
		i = num * factR(num - 1);
	return i;
}
