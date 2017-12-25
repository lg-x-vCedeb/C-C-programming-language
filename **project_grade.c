#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>

#define MAXNAME       20
#define MAXID         4
#define MAXSTUDENTS   20
#define NUMQUESTION   4
#define NUMASSIGN     5
#define A             4
#define B             3
#define C             2
#define D             1
#define F             0
#define DEFAULT       0

struct Grade {
	char name[MAXNAME];
	char Id[MAXID];
	float Ass[NUMASSIGN];
	//float Ass2;
	//float Ass3;
	//float Ass4;
	//float Ass5;
};

int main(){
//void grade(){
	struct Grade Students[MAXSTUDENTS];//Students 最大人数
	struct Grade *student;
	int ch;//ch 控制 EOF
	int NumofStu = 0;
	int AssNum;
	int sign_ASS = 1;
	char sign_Confirm;
	int sign_Confirm_2;
	char Qmark;
	int sign_Qmark = 1;
	float Assmark = 0;

	FILE *stutxt;
	FILE *grade;

	//检查文件及创建未找到的文件
	if((stutxt = fopen("student.txt","r")) == NULL){
		fprintf(stdout,"Can't open \"student.txt\" file.\n");
		exit(1);
	}
	if((grade = fopen("mark.txt","a+")) == NULL){
		fprintf(stdout,"Can't open \"mark.txt\" file.\n");
		grade = fopen("mark.txt","wt+");
		grade = fopen("mark.txt","a+");
	}
	
	//读入文件
	while(fscanf(stutxt,"%s %s",&Students[NumofStu].name,&Students[NumofStu].Id) != EOF)
		NumofStu++;
	for(int i = 0;i<NumofStu;i++)
		printf("%s %s\n",Students[i].name,Students[i].Id);
	printf("\n");
	
	//grading
	for(int preStu = 1; preStu<NumofStu; preStu++)
	{
		printf("You need to mark the following student's assignments.(Enter 'q' to quit; Enter 'n' to mark the next student's Assignment)");
		printf("%s\t%s\n",Students[0].name,Students[0].Id);
		printf("%s\t%s\n",Students[preStu].name,Students[preStu].Id);
		//选择
		while(sign_ASS == 1){
			//判断是否填完所有的Assignment
			for(int j = 0;j<NUMASSIGN;j++){
				if(Students[preStu].Ass[j] == EOF){
					Students[preStu].Ass[j] = 0;
					sign_ASS = 1;
				}
				else
					sign_ASS = 0;
			}
			printf("Please input 1-5 to choose which assignment you want to mark.\n");
			scanf_s("%d",&AssNum);
			//选择q结束程序//返回主菜单
			if((char)AssNum == 'q')
				exit(0);
			//main();
			//选择n对下一个学生评分
			if((char)AssNum == 'n')
				break;
			while(AssNum>5 || AssNum<1){
				printf("There are only 5 Assignment, choose it in range 1-5.\n");
				printf("Please choose it again.\n");
				scanf_s("%d",&AssNum);
			}
			//计算
			printf("To calculate the total mark of assignment%d, you need to input each mark of the %d questions in assignment%d.\n",Ass,NUMQUESTION,Ass);
			for(int i = 1;i<=NUMQUESTION;i++){
				printf("Question %d is:",i);
				scanf_s("%c",&Qmark,sizeof(Qmark));
				do{
					switch(Qmark){
						case 'A':Assmark += (1/NUMQUESTION)*A;
							break;
						case 'B':Assmark += (1/NUMQUESTION)*B;
							break;
						case 'C':Assmark += (1/NUMQUESTION)*C;
							break;
						case 'D':Assmark += (1/NUMQUESTION)*D;
							break;
						case 'F':Assmark += (1/NUMQUESTION)*F;
							break;
						default:
							printf("Please input A, B, C or D to mark the question.\n");
							sign_Qmark = 1;
							scanf_s("%c",&Qmark,sizeof(Qmark));
					}
				}while(sign_Qmark == 1);
			}
			Assmark = Students[preStu].Ass[AssNum-1];
			
			//预览
			fprintf(grade,"%s\t%s\tAssignment1\tAssignment2\tAssignment3\tAssignment4\tAssignment5\n",Students[0].name,Students[0].Id);
			fprintf(grade,"%s\t%s\t%s\t%s\t%s\t%s\t%s\n",Students[preStu].name,Students[preStu].Id,Students[preStu].Ass[0],Students[preStu].Ass[1],Students[preStu].Ass[2],Students[preStu].Ass[3],Students[preStu].Ass[4]);
			while((ch = getc(grade))!=EOF)
				putchar(ch);
		}
	}
	//最后预览+确认
	while((ch = getc(grade))!=EOF)
				putchar(ch);
	printf("Comfirm? (Enter 'Y' to Confirm or enter 'N' to fix)\n");
	scanf_s("%c",&sign_Confirm,sizeof(sign_Confirm));
	do{
		switch(sign_Confirm){
			//case 'Y':
				//main();
				//printf("Thank you, Sir (Madam)!\n")
				//break;
			//case 'N':
				//Grade();
				//printf("Fighting!!")
				//break;
		default:
			printf("Please enter Y or N. (Enter 'Y' to Confirm or enter 'N' to fix)\n");
			scanf_s("%c",&sign_Confirm,sizeof(sign_Confirm));
			sign_Confirm_2 = 1;
		}
	}while(sign_Confirm_2 == 1);
	//if(sign_Confirm == 'Y')
	//main();
	//student = &Students[0];
	system("pause");
	return 0;
}
