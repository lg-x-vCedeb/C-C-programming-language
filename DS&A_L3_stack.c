#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include "stack.h"
#define EMPTY -1
/*
typedef struct{
	double* values;
	int top;
	int maxTop;
}Stack;
*/
bool CreateStack(Stack *stack, int size);
bool IsEmpty(Stack* stack);
bool IsFull(Stack* stack);
bool Top(Stack* stack, double* x);
bool Push(Stack* stack, double x);
bool Pop(Stack* stack, double* x);
void DisplayStack(Stack* stack);
void DestoryStack(Stack* stack);

bool CreateStack(Stack *stack, int size){
	if(size < 0)
		return false;
	stack->values = (double*)malloc(sizeof(double)*size);
	stack->top = EMPTY;
	stack->maxTop = size - 1;
	return true;
}

bool IsEmpty(Stack* stack){
	return (stack->top == EMPTY);
}

bool IsFull(Stack* stack){
	return (stack->top == int(stack->values) - 1);
}

bool Top(Stack* stack, double* x){
	if(stack){
		stack->values = x;
		return true;
	}
	else
		return false;
}
bool Push(Stack* stack, double x){
	if(!IsFull(stack)){
		stack->values[++stack->top] = x;
		return true;
	}
	else
		return false;
}

bool Pop(Stack* stack, double* x){
	if(!IsEmpty(stack)){
		stack->top--;
		x = stack->values;
		return true;
	}
	else
		return false;
}

void DisplayStack(Stack* stack){
	for(int i = int(stack->top);i > -1;i--){
		printf("%s |		%f		|\n",stack->top == stack->maxTop ? "      " : "top-->",stack->values[i]);
	}
	printf("       ------------------\n");
}
/*
void DestoryStack(Stack* stack){
	if(stack){
		free(stack);
	}
}*/

//#include <stdio.h>
//#include "stack.h"
int main(void) {
	Stack stack;
	double val;
	CreateStack(&stack, 5);
	Push(&stack, 5);
	Push(&stack, 6.5);
	Push(&stack, -3);
	Push(&stack, -8);
	DisplayStack(&stack);
	if(Top(&stack, &val))
		printf("Top: %g", val);
	Pop(&stack, &val);
	if(Top(&stack, &val))
		printf("Top: %g", val);
	while(!IsEmpty(&stack))
	Pop(&stack, &val);
	DisplayStack(&stack);
	//DestroyStack(&stack);
	system("pause");
	return 0;
}
