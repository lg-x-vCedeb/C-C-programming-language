//Calculate the fatorial by looping and recursion.
#include <stdio.h>
#include <Windows.h>
long fact(int n);
long recursion(int n);
int main(){
	int num;
	printf("This program calculates fatorials.\n");
	printf("Enter an integer in the range 0-12 (q to quit):\n");
	while(scanf_s("%d",&num) == 1){//*question that (scanf_s("%d %d",&num1,&num2) == 2)??
		if(num<0)
			printf("You must input a positive integer.\n");
		else if(num>12)
			printf("Keep input under 13.\n");
		else{
			printf("loop: %d factorial = %ld\n",num,fact(num));
			printf("recursion: %d fatorial = %ld\n",num,recursion(num));
		}
		printf("Enter an integer in the range 0-12 (q to quit):\n");
	}
	printf("Bye.\n");
	system("pause");
	return 0;
}

long fact(int n){
	long ans;
	for(ans = 1;n > 1; n--)//not to remember {for(int i = 0;i<n;i++)} but for([1];[2];[3]) is equal to ([1 define]; while([2 condition]){~~~~~(at the end)[3 preparing for the next loop]})
		ans *= n;
	return ans;
}

long recursion(int n){
	long ans;
	if(n>0)
		ans = n *recursion(n-1);
	else
		ans = 1;//dont need many if loop but use more else recursion
	return ans;
}
