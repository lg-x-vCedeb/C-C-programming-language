#include <stdio.h>
#include <Windows.h>
#include "hotel.h"
int menu (){
	int code, status;
	printf("\n%s%s\n", STARS, STARS);
	printf("Enter the number of the desired hotel:(The showing price is the price of first day)\n");
	printf("You have 95% discount if your nights exceed 1.\n");
	printf("1)Fairfield Arms $80 \n2)Hotel Olypic $125 \n");
	printf("3)Chertworthy Plaza $155 \n4)The Stockton $200 \n");
	printf("5)quit\n");
	printf("%s%s\n", STARS, STARS);
	while((status = scanf_s("%d",&code))!=1 || (code<1 || code > 5))
	{
		if(status != 1)
			scanf_s("%*s");
		printf("Enter an integer from 1 to 5, please.\n");
	}
	return code;
}
int getnights(){
	int nights;
	printf("How many nights needed?\n");
	while(scanf_s("%d",&nights) != 1)
	{
		scanf_s("%*s");
		printf("Please enter an integer, such as 2.\n");
	}
	return nights;
}
void showprice(double rate, int nights)
{
	int n;
	double total = 0.0;
	double factor = 1.0;
	for(n = 1; n<= nights;n++, factor *= DISCOUNT)
		total += rate * factor;
	printf("The total cost will be $%0.2f.\n",total);
}
