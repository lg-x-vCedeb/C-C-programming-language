#include <stdio.h>
#include <Windows.h>
void interchange(int * u,int * v);

int main(){
	int x,y;
	printf("Please input two integers.(q to quit)\n");
	while(scanf_s("%d %d",&x,&y) == 2){
		printf("Originally x = %d and y = %d.\n", x, y);
		interchange(&x,&y);
		printf("Now x = %d and y = %d.\n", x, y);
		printf("Please input two integers.(q to quit)\n");
	}
	printf("Bye.\n");
	system("pause");
	return 0;
}

void interchange(int * u,int * v){
	int temp;
	temp = *u;
	*u = *v;
	*v = temp;
}
