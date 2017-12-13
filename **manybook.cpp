#include <stdio.h>
#include <Windows.h>
#include <string.h>
#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 10
struct book{
	char title[MAXTITL];
	char author[MAXAUTL];
	float value;
};
int main(){
	struct book library[MAXBKS];
	char outInstr[]="outList";
	int count = 0;
	int index;
	printf("Pleaase enter the book title.\n");
	//printf("Press [enter] at the state of a line to stop.\n");
	printf("Enter 'outList' to stop.\n");
	while(count < MAXBKS && scanf_s("%s",&library[count].title,sizeof(library[count].title))!=NULL && library[count].title[0] != '\0')
	{
		if(strcmp(outInstr,library[count].title) == 0)
			break;
		printf("Now enter the author.\n");
		scanf_s("%s",&library[count].author,sizeof(library[count].author));
		printf("Now enter the value.\n");
		scanf_s("%f",&library[count].value,sizeof(library[count].value));
		//while(getchar() != '\n')
			//continue;
		if(count < MAXBKS){
			count++;
			printf("Enter the next title.\n");
		}
	}
	if(count>0)
	{
		printf("Here is the list of your books:\n");
		for(index = 0;index<count;index++)
			printf("%s by %s: $%.2f\n",library[index].title,library[index].author,library[index].value);
	}
	else
		printf("No books? Too bad.\n");
	system("pause");
	return 0;
}
