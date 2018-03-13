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
}

bool IsEmpty(Stack* stack){
	return (stack->top == EMPTY);
}

bool IsFull(Stack* stack){
	return (stack->top == int(stack->values) - 1);
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
