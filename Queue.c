#include <stdio.h>
#include <Windows.h>
#include "Queue.h"

int main(){
	Queue queue;
	double value;
	CreateQueue(&queue, 5);
	puts("Enqueue 5 items.");
	for(int x = 0; x < 5;x++){
		Enqueue(&queue,x);
		//printf(" x:%d\n",x);
	}
	puts("Now attempting to enqueue again...");
	Enqueue(&queue, 5);
	DisplayQueue(&queue);
	Dequeue(&queue, &value);
	printf("Retrieved element = %g\n", value);
	DisplayQueue(&queue);
	Enqueue(&queue, 7);
	DisplayQueue(&queue);
	DestroyQueue(&queue);
	system("pause");
	return 0;
}

bool CreateQueue(Queue* queue, int size){
	if(size <= 0)
		return false;
	queue->values = (double*)malloc(sizeof(double)*size);
	queue->front = 0;
	queue->rear = -1;
	queue->counter = 0;
	queue->maxSize = size;
	return true;
}

bool IsEmpty(Queue* queue){
	return(queue->values[0]);
	//return(queue->rear == -1);
}

bool IsFull(Queue* queue){
	return(queue->counter == queue->maxSize);
}

bool Enqueue(Queue* queue, double x){
	if(IsFull(queue)){
		printf("Error: the queue is full.\n");
		return false;
	}
	queue->rear = (queue->rear+1) % queue->maxSize;
	//printf("%d",queue->rear);
	//printf(" %d ",x);
	queue->values[queue->rear] = x;
	//printf(" %d ",queue->values[queue->rear]);
	queue->counter++;
	return true;
}

bool Dequeue(Queue* queue, double* x){
	if(IsEmpty(queue))
		return false;
	*x = queue->values[queue->front];
	queue->front = (queue->front + 1) % queue->maxSize;
	queue->counter--;
	return true;
}

void DisplayQueue(Queue* queue){
	for(int i = 0; i <= queue->counter - 1;i++){
		printf("%s\t\t%g\t\t%s\n",i == queue->front ? "front -->" : "         ",queue->values[i], i == queue->rear ? "<-- rear" : "        ");
	}
}

void DestroyQueue(Queue* queue){
	free(queue);
}
