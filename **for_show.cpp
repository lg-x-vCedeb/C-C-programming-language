#include <stdio.h>
#include <Windows.h>

int main(){
	int num = 0;
	for(printf("Keep entering numbers.\n");num != 6;)
		scanf_s("%d",&num);
	printf("That's the one I want!\n");
	system("pause");
	return 0;
}
