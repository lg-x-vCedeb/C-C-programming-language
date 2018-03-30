#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#define FALSE 0
#define TRUE 1

bool IsEmpty(Node* head){
	if(head == NULL)
		return FALSE;
	else
		return TRUE;
}

//Insertion Part
Node* InsertNode(Node** phead, int index, double x){
	if (index < 0) 
		return FALSE; 


/*
**  Try to locate the code at position index. 
**  If it does not exist, return null.
*/
	int currIndex = 1; 
	Node* currNode = *phead; 
	while (currNode && index > currIndex) 
	{ 
		currNode = currNode->next; 
		currIndex ++; 
	} 
	if (index > 0 && currNode == 0) 
		return FALSE; 


//  Create a new Node.
	Node* newNode = (Node*)malloc(sizeof(Node)); 
	newNode->data = x; 


/*
**	if index is equal to 0, New Node insert as the new head.
**	else insert after currNode
*/
	if (index == 0) 
	{ 
		newNode->next = *phead; 
		*phead = newNode; 
	} 
	else 
	{ 
		newNode->next = currNode->next; 
		currNode->next = newNode; 
	} 
	return newNode;
}

int FindNode(Node* head, double x){
	int position = 1;
	Node* TargetNode = head;
	while(TargetNode){
		if(TargetNode->data != x){
			TargetNode = TargetNode->next;
			position++;
			if(TargetNode->next == NULL){
				position = 0;
				break;
			}
		}
		else
			break;
	}
	//printf("It's in %d position",TargetNode->next ? position : NULL);
	return position;
}

int DeleteNode(Node** phead, double x){
	int position = 0;
	Node* LeaveNode = *phead;
	Node* PreLeaveNode;
	position = FindNode(LeaveNode,x);
	if(position != 0){
		for(int i = 1;i <= position;i++){
			PreLeaveNode = LeaveNode;
			LeaveNode = LeaveNode->next;
		}
		if(LeaveNode->next != NULL){
			PreLeaveNode->next = LeaveNode->next;
			free(LeaveNode);
		}
		else
			free(LeaveNode);
		return position;
	}
	else
		return FALSE;
}

void DisplayList(Node* head){
	Node* ListNode = head;
	printf("That is:\n");
	while(ListNode){
		printf("%f ",ListNode->data);
		ListNode = ListNode->next;
	}
}

void DestroyList(Node* head){
	Node* PreNode;
	while(head->next != NULL){
		PreNode = head;
		head = head->next;
		free(PreNode);
	}
	head = NULL;
}

int NumOfTarget = 0;
int DeleteNodes(Node** phead, double x){
	int position = 0;
	Node* LeaveNode = *phead;
	Node* PreLeaveNode;
	while(position = FindNode(LeaveNode,x),position != 0){
		NumOfTarget++;
		for(int i = 1;i <= position;i++){
			PreLeaveNode = LeaveNode;
			LeaveNode = LeaveNode->next;
		}
		if(LeaveNode->next != NULL){
			PreLeaveNode->next = LeaveNode->next;
			free(LeaveNode);
		}
		else
			free(LeaveNode);
	}
	if(position == 0)
		return FALSE;
	return NumOfTarget;
}
	
void RemoveDuplicates(Node** phead){
	Node* TargetNode = *phead;
	Node* PreNode;
	Node* PrepreNode;
	while(TargetNode->next != NULL){
		PreNode = TargetNode;
		TargetNode = TargetNode->next;
		PrepreNode = PreNode;
		PreNode = PreNode->next;
		if(PreNode->data == TargetNode->data){
			PrepreNode->next = TargetNode->next;
			free(PreNode);
			free(TargetNode);
		}
	}
}
int main(){
	
}
