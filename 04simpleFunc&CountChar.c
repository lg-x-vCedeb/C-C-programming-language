#include <stdio.h>
#include <windows.h>
int FCountchar();
int WCountchar();
int main(){
	int c;
	c = getchar();
	printf("%d\t%d\t%d\n",c,FCountchar(),WCountchar());/*why doesn't it work?*/
	system("pause");
	return 0;
}
int FCountchar(){
	double fcc;
	for(fcc = 0; getchar() != EOF; ++fcc)
		;
	/*printf("%.0f\n",fcc);/*why doesn't it work?*/
	return fcc;
}
int WCountchar(){
	long wcc;
	wcc = 0;
	while(getchar() != EOF)
		++wcc;
	/*printf("%ld\n",wcc);/*why doesn't it work?*/
	return wcc;
}
