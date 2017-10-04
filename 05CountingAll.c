#include <stdio.h>
#include <Windows.h>
#define IN 1
#define OUT 0
int CharsCounting();
int RowsCounting();
int SpacesCounting();
int TabsCounting();
int WordsCounting();
int main(){
	int c;
	c = getchar();
	while(getchar() != EOF)
		printf("The number of chars is %d \n The number of rows is %d \n The number of spaces is %d \n The number of tabs is %d \n The number of words is %d \n",CharsCounting(),RowsCounting(),SpacesCounting(),TabsCounting(),WordsCounting());
	system("pause");
	return 0;
}
int CharsCounting(){
	int Cc;
	Cc = 0;
	while(getchar() != EOF)
		++Cc;
	return Cc;
}
int RowsCounting(){
	int Rc,Rw;
	Rw = 0;
	while((Rc = getchar()) != EOF)
		if(Rc == '\n')
			++Rw;
	return Rw;
}
int SpacesCounting(){
	int Sc,Sw;
	Sw = 0;
	while((Sc = getchar()) != EOF) 
		if (Sc == '\n')
			++Sw;
	return Sw;
}
int TabsCounting(){
	int Tc,Tw;
	Tw = 0;
	while((Tc = getchar()) != EOF) 
		if (Tc == '\t')
			++Tw;
	return Tw;
}
int WordsCounting(){
	int Wc,Ww,State;
	State = OUT;
	Ww = 0;
	while((Wc = getchar()) != EOF)
		if(Wc == ' '||Wc == '\n'||Wc == '\t')
			State = OUT;
		else if (State == OUT){
			State = IN;
			++Ww;
		}
	return Ww;
}
