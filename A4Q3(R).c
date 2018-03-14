#include <stdio.h>
#include <Windows.h>
#include <ctype.h>

void inverse(int* a);

int main(){
	int NumOfSet = 1;
	int i = 0;
	int *NumSet = (int *)malloc(sizeof(int));
	printf("Please input several integers.(Enter 0 to exit.)\n");
	while(scanf("%d",NumSet)){
		if(isdigit(NumSet[i])){
			if(*NumSet == 0)
				break;
			NumSet = (int *)malloc(1 + i++);
		}
		else{
			printf("Please input integers.\n");
			continue;
		}
	}
#if 0
	inverse(NumSet);
#endif
	system("pause");
	return 0;
}

#if 0
void inverse(int* a){

}
#endif
