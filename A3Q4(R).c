/*
**Write a program to calculate a!+b!+c!. 
**Write a function fac to calculate factorial of a natural number.
*/

#include <stdio.h>
#include <Windows.h>
#include <ctype.h>
#define SETNUM 51
int fac(int n);

int main(){
	int SetOfNum[SETNUM];
	int i = 0;
	long SetOfFac[SETNUM];
	long long TotalFac = 0;


/*
**	Input all the numbers to be calculated.
*/
	while(printf("Please input a few nuber to compute its factorial.(Input '-1' to exit)\n"),scanf_s("%d",&SetOfNum[i],sizeof(SetOfNum[i]))){
		if(isdigit(SetOfNum[i]) && i < SETNUM - 1){
			if(SetOfNum[i] >= 0){
				i++;
				continue;
			}
			else if(SetOfNum[i] == -1){
				SetOfNum[i] = '\0';
				break;
			}
			else
				printf("Please input a positive number or -1 to exit.\n");
		}
		if(i >= 50)
			break;
	}


//	Calculation

	for(int j = 0;SetOfNum[j+2] != '\0';j++){
		if(SetOfNum[j+1] == '\0'){
			SetOfFac[j] = fac(SetOfNum[j]);
			printf("%d = ",SetOfNum[j]);
		}
		else{
			SetOfFac[j] = fac(SetOfNum[j]);
			printf("%d + ",SetOfNum[j]);
		}
		
	}


//	Sum

	for(int k = 0;SetOfFac[k] != '\0';k++){
		if(SetOfFac[k+1] == '\0'){
			printf("%l.\n",SetOfFac[k]);
			TotalFac += SetOfFac[k];
		}
		else{
			printf("%l + ",SetOfFac[k]);
			TotalFac += SetOfFac[k];
		}
	}
	printf("The formular is equal to %ll.\n",TotalFac);
	system("pause");
	return 0;
}

//Fatorial function
int fac(int n){
	int num = 1;
	if(n <= 1)
		return num;
	else
		num *= fac(n-1);
}
