//transform the decimal into the binary.
#include <stdio.h>
#include <Windows.h>
void to_binary(unsigned long n);

int main(){
	unsigned long decimal;
	printf("Enter an integer (q to quit):\n");
	while(scanf_s("%ul",&decimal) == 1){
		printf("Binary equivalent: ");
		to_binary(decimal);
		//putchar('\n');
		printf("\n");(The consequence is same and the intrinic difference need to research later.)
		printf("Enter an integer(q to quit):\n");
	}
	printf("Done.\n");
	system("pause");
	return 0;
}

void to_binary(unsigned long n){
	int binary;
	binary = n % 2;
	if(n >= 2)
		to_binary(n/2);
	putchar('0'+binary);
	//If r is 0, '0'+r is char '0'; if r is 1, '0'+r is char '1', which depends on the condition that the numberic code of '1' is bigger than '0' in ASCII or EBCDIC.
	//ASCII  (American Standard Code of Information Interchange)
	//EBCDIC (Exitended Binary Coded Demical Interchange Code)
	//printf("%d\n",'0'+binary);(Wrong for they are only need one char.)
}
