#include <stdio.h>
#include <Windows.h>
#include <string.h>
#define EG "eg"
#define OK "ok"

int main() {
	int NumOfNums = 0;
	char OkOrEg[5];
	char things1, things2, things3, things4;
	char H, T, O;
	printf("Please input 4 possible char.(Or input 'eg' to browse the sample)\n");
	printf("Ok? (if ok please input 'ok' or input 'eg').\n");
	scanf_s("%s", &OkOrEg, sizeof(OkOrEg));
	if (strcmp(OkOrEg, EG) == 0) {
		for (int i = 1; i < 5; i++) 
			for (int k = 1; k < 5; k++) 
				for (int j = 1; j < 5; j++)
				{
					if (i != k&&k != j&&j != i) {
						printf("%d%d%d\n", i, k, j);
						NumOfNums++;
					}
				}
		printf("%d", NumOfNums);
	}
	if (strcmp(OkOrEg, OK) == 0) {
		scanf_s("c", &things1, sizeof(things1));
		scanf_s("c", &things2, sizeof(things2));
		scanf_s("c", &things3, sizeof(things3));
		scanf_s("c", &things4, sizeof(things4));

	}
}
