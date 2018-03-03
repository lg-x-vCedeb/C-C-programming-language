/*Read in and compute the greatest common
divisor (GCD) of two natural numbers using
recursion.
• GCD(x, y) is the greatest natural number which
divides both x and y
– GCD(6, 7) = 1
– GCD(6, 9) = 3
– GCD(6, 0) = 6
• Note that your program should contain
– a main function, which does IO
– and a recursive function, int GCD(int x, int y), which
computes the GCD of x and y.*/


#include <stdio.h>
#include <Windows.h>
int GCD(int x,int y);

int main(){
	int x,y;
	int answer;
	for(;;){
		printf("Please input two nature numbers below.(The front is bigger)\n");
		printf("Big: ");
		scanf_s("%d",&x,sizeof(x));
		printf("Small: ");
		scanf_s("%d",&y,sizeof(y));
		if(x>=y)
		{
			answer = GCD(x,y);
			printf("GCD(%d,%d) = %d\n",x,y,answer);
			break;
		}
		if(x<y)
			printf("Please pay attention to the requests.\n");
	}
	system("pause");
	return 0;
}

int GCD(int x,int y){
	int i;
	if(y == 0)
		return x;
	if(y > 0)
		return GCD(y, x%y);
}
