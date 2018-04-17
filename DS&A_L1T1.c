//Read in a positive number and compute its factorial using recursion.

#include <stdio.h>
#include <Windows.h>
long factR(int n);

int main(){
	int NumToCpt;//define a number to compute factorial.
	for(;;){
		printf("What number's fatorial you want to compute?\n");
		scanf_s("%d",&NumToCpt,sizeof(NumToCpt));
		if(NumToCpt >= 1){
			printf("The %d's fatorial is %ld.\n",NumToCpt,factR(NumToCpt));//Output the answer.
			break;
		}
		if(NumToCpt < 1)
			printf("Please input positive number.");
	}
	system("pause");
	return 0;
}

long factR(int num){
	int i;
	if(num == 1)
		return 1;
	if(num > 1)
		i = num * factR(num - 1);//Recursive calculation.
	return i;
}

#if 0
long factR(int num){
	return (num == 1)? 1 : num * factR(num - 1);
}
#endif
