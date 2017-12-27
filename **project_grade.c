#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <string.h>

#define MAXNAME		20
#define MAXID		5
#define MAXSTUDENTS 20
//#define NUMQUESTION 4.00
#define NUMASSIGN	6
#define A			4.00
#define B			3.00
#define C			2.00
#define D			1.00
#define F			0.00

struct Grade {
	char name[MAXNAME];
	char Id[MAXID];
	double Ass[NUMASSIGN];
};

int main(){
//void grade(){
	struct Grade Students[MAXSTUDENTS];//Students 最大人数
	//struct Grade *student;
	int ch = 0;//ch 控制 EOF
	int NumofStu = 0;
	int NumofQues = 1;
	int AssNum = 0;
	int sign_ASS = 1;
	char sign_Confirm = 0;
	//int sign_Confirm_2;
	char sign_Id[MAXID];
	char Qmark[21] = {0};
	double Assmark = 0;

	FILE *stutxt;
	FILE *grade;

	//检查文件及创建未找到的文件
	if((stutxt = fopen("student.txt","a+")) == NULL){
		fprintf(stdout,"Can't open \"student.txt\" file.\n");
		exit(1);
	}
	if((grade = fopen("mark.txt","w+")) == NULL){
		fprintf(stdout,"Can't open \"mark.txt\" file.\n");
		grade = fopen("mark.txt","wt+");
		grade = fopen("mark.txt","a+");
		//exit(2);
	}


	
	//读入文件及初始化数组字符串
	while(fscanf(stutxt,"%s %s",Students[NumofStu].name,Students[NumofStu].Id) != EOF){
		Students[NumofStu].name[strlen(Students[NumofStu].name)] = '\0';
		Students[NumofStu].Id[MAXID - 1] = '\0';
		Students[NumofStu].Ass[NUMASSIGN - 1] = '\0';
		NumofStu++;
	}
	
	for(int i = 0;i<NumofStu;i++)
		printf("%s %s\n",Students[i].name,Students[i].Id);
	printf("\n");

	
	//grading
	for(int preStu = 1; preStu<NumofStu; preStu++)
	{
		printf("You need to mark the following student's assignments.(Enter 'q' to quit; Enter 'n' to mark the next student's Assignment; Enter 'c' to choose the student)\n");
		printf("%s\t%s\n",Students[0].name,Students[0].Id);
		printf("%s\t%s\n",Students[preStu].name,Students[preStu].Id);
		
		//初始化Ass数组-2
		for (int m = 0; m<NUMASSIGN-1;m++)
		{
			Students[preStu].Ass[m] = -1;
		}

		//选择
		while(sign_ASS == 1){
			printf("\nPlease input 1-5 to choose which assignment you want to mark.(Enter 'q' to quit; Enter 'n' to mark the next student's Assignment; Enter 'c' to choose the student)\n");
			setbuf(stdin, NULL);
			scanf_s("%c",&AssNum);
			//printf("%c", AssNum);
			//选择q结束程序//返回主菜单
			if (AssNum == 'q')
				exit(0);
			//main();
			//选择n对下一个学生评分
			if (AssNum == 'n')
				//printf("%c", AssNum);
				break;

			//指定一位学生
			if (AssNum == 'c') {
				printf("Enter the student's Id below.(It's only 4 numbers in the formal of Id)\n");
				setbuf(stdin, NULL);
				scanf_s("%s", &sign_Id, sizeof(sign_Id));
				sign_Id[MAXID - 1] = '\0';
				for (int p = 1; p < NumofStu; p++) {
					if (strcmp(sign_Id, Students[p].Id) == 0)
						preStu = p - 1;
				}
				break;
			}
			while((AssNum>'5' || AssNum<'1') && (AssNum != 'n' || AssNum != 'q')){
				printf("There are only 5 Assignment, choose it in range 1-5.\n");
				printf("Please choose it again.\n");
				setbuf(stdin, NULL);
				scanf_s("%c",&AssNum);
			}
			//计算
			printf("How many questions in this assignment%d? Please enter.\n",AssNum);
			scanf_s("%d",&NumofQues);
			printf("To calculate the total mark of assignment%d, you need to input each mark of the questions in assignment%d.\n",AssNum,AssNum);
			for(int g = 1;g<=NumofQues;g++){

				printf("Question %d is:",g);
				setbuf(stdin, NULL);
				scanf_s("%c",&Qmark[g-1],sizeof(Qmark[g-1]));
				if (Qmark[g - 1] < 'A' || Qmark[g - 1]>'D' || Qmark[g - 1] == 'F') {
					Qmark[g - 1] = '\0';
					break;
				}
			}
			for(int k = 0;k<NumofQues;k++){
					switch(Qmark[k]){
						case 'A':
							Assmark += (1.00/((float)NumofQues))*A;
							break;
						case 'B':
							Assmark += (1.00/((float)NumofQues))*B;
							break;
						case 'C':
							Assmark += (1.00/((float)NumofQues))*C;
							break;
						case 'D':
							Assmark += (1.00/((float)NumofQues))*D;
							break;
						case 'F':
							Assmark += (1.00/((float)NumofQues))*F;
							break;
						default:
							printf("Please input A, B, C or D to mark the question.\n");
					}
			}
			NumofQues = 1;
			//printf("%.2f\n",Assmark);
			AssNum = (int)AssNum - 48;//char 位变化
			Students[preStu].Ass[(int)AssNum - 1] = Assmark;
			//printf("%.2f\n", Students[preStu].Ass[(int)AssNum - 1]);
			Assmark = 0;
			
			//判断是否填完所有的Assignment
			for (int j = 1; j<NUMASSIGN-1; j++) {
				
				if (Students[preStu].Ass[j] < 0.00 || Students[preStu+1].Ass[j] < 0.00) {
					//Students[preStu].Ass[j] = 0;
					sign_ASS = 1;
					//printf("%d\n",j);
					//printf("%.2f\n",Students[preStu].Ass[j]);
				}
				else
					sign_ASS = 0;
			}


			//预览
			fprintf(grade,"%s\t%s\tAssignment1\tAssignment2\tAssignment3\tAssignment4\tAssignment5\n",Students[0].name,Students[0].Id);
			fprintf(grade,"%s\t%s\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\n",Students[preStu].name,Students[preStu].Id,Students[preStu].Ass[0],Students[preStu].Ass[1],Students[preStu].Ass[2],Students[preStu].Ass[3],Students[preStu].Ass[4]);
			printf("%s\t%s\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\n", Students[preStu].name, Students[preStu].Id, Students[preStu].Ass[0], Students[preStu].Ass[1], Students[preStu].Ass[2], Students[preStu].Ass[3], Students[preStu].Ass[4]);
			while((ch = fgetc(grade)) != EOF){
				if ((int)(ch = fgetc(grade)) == 0xcd)
					break;
				putc(ch,stdout);
				//rewind(grade);
			}
			fclose(grade);
			grade = fopen("mark.txt", "a+");
		}
		if (preStu == NumofStu - 1) {
			printf("You have completed the marking.(And remember to enter 'c' to choose the student expediently)\n");
		}
	}
	//最后预览+确认
	grade = fopen("mark.txt", "w+");
	fprintf(grade, "%s\t%s\tAssignment1\tAssignment2\tAssignment3\tAssignment4\tAssignment5\n", Students[0].name, Students[0].Id);
	for (int EachStu = 1; EachStu < NumofStu; EachStu++)
		fprintf(grade, "%s\t%s\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\n", Students[EachStu].name, Students[EachStu].Id, Students[EachStu].Ass[0], Students[EachStu].Ass[1], Students[EachStu].Ass[2], Students[EachStu].Ass[3], Students[EachStu].Ass[4]);
	while((ch = getc(grade))!=EOF)
		putc(ch, stdout);
	printf("Comfirm? (Enter 'Y' to Confirm or enter 'N' to fix)\n");
	setbuf(stdin, NULL);
	scanf_s("%c",&sign_Confirm,sizeof(sign_Confirm));
	
	if (sign_Confirm == 'Y') {
		printf("Thank you, Sir (Madam)!\n");
		//main();
	}
	else if (sign_Confirm == 'N') {
		printf("Fighting!!");
		//grade();
	}
	system("pause");
	return 0;
}
