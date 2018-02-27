/*企业发放的奖金根据利润提成。利润(I)低于或等于10万元时，奖金可提10%；
利润高于10万元，低于20万元时，低于10万元的部分按10%提成，高于10万元的部分，可可提成7.5%；
20万到40万之间时，高于20万元的部分，可提成5%；
40万到60万之间时高于40万元的部分，可提成3%；
60万到100万之间时，高于60万元的部分，可提成1.5%，高于100万元时，
超过100万元的部分按1%提成，从键盘输入当月利润I，求应发放奖金总数？*/

#include <stdio.h>
#include <Windows.h>
#define TEN		100000
#define TWENTITY	200000
#define FOURTY	400000
#define SIXTY	600000
#define HUNDRED	1000000
#define FIRST_LEVEL	0.1
#define SECOND_LEVEL	0.075
#define THIRD_LEVEL	0.05
#define FOURTH_LEVEL	0.03
#define FIFTH_LEVEL	0.015
#define SIXTH_LEVEL 0.01

int main(){
	long int profit;
	printf("How many profit do you earn?\n");
	scanf_s("%lu",&profit,sizeof(profit));
	if(profit <= TEN){
		profit += profit * FIRST_LEVEL;
	}
	else if(profit > TEN && profit <= TWENTITY){
		profit += TEN * FIRST_LEVEL + (profit - TEN) * SECOND_LEVEL;
	}
	else if(profit > TWENTITY && profit <= FOURTY){
		profit += TEN * FIRST_LEVEL + (profit - TEN) * SECOND_LEVEL + (profit - TWENTITY) * THIRD_LEVEL;
	}
	else if(profit > FOURTY && profit <= SIXTY){
		profit += TEN * FIRST_LEVEL + (profit - TEN) * SECOND_LEVEL + (profit - TWENTITY) * THIRD_LEVEL + (profit - FOURTY) * FOURTH_LEVEL;
	}
	else if(profit > SIXTY && profit <= HUNDRED){
		profit += TEN * FIRST_LEVEL + (profit - TEN) * SECOND_LEVEL + (profit - TWENTITY) * THIRD_LEVEL + (profit - FOURTY) * FOURTH_LEVEL + (profit - SIXTY) * FIFTH_LEVEL;
	}
	else if(profit > HUNDRED)
		profit += TEN * FIRST_LEVEL + (profit - TEN) * SECOND_LEVEL + (profit - TWENTITY) * THIRD_LEVEL + (profit - FOURTY) * FOURTH_LEVEL + (profit - SIXTY) * FIFTH_LEVEL + (profit - HUNDRED) * SIXTH_LEVEL;
	printf("The total reward is %lu\n",profit);
	system("pause");
	return 0;
}
