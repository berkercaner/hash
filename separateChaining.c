#include <stdio.h>
#include <stdlib.h>
#include "separateChaining.h"

struct node{
	int value;
	struct node* next;
};

struct node* array[HASH_SIZE];

void init(){

	int i;
	for(i = 0; i < HASH_SIZE; i++)
		array[i] = NULL;
}

int hash(int value){

	return value % HASH_SIZE;
}


void addValue(int value){
	
	struct node* newNode = (struct node*) malloc(sizeof(struct node));
	newNode->value = value;
	newNode->next = NULL;
	int i = hash(value);
	
	if(array[i] == NULL)
		array[i] = newNode;
	else{
		struct node* temp = array[i];
		while(temp->next)
			temp = temp->next;
		
		temp->next = newNode;
	}	
}

void print(){
	
	int i;
	
	for(i = 0; i < HASH_SIZE; i++){
		struct node* input = array[i];
		printf("HASH[%d] = ",i);
		while(input){
			printf(" %d ==>",input->value);
			input = input->next;
		}
		printf(" NULL\n");printf("\n");
	}
		
}

int findValue(int value){
	
	int i = hash(value);
	int x = 0;
	struct node* temp = array[i];
	while(temp != NULL){
		if(temp->value == value){
			printf("\n%d exists at (%d,array[%d])\n",value,x,i);
			return 1;
		}
		temp = temp->next; 
		x++;
	}
	printf("\n%d doesnt exist\n",value);
	return 0;
}

void deleteValue(int value){
	
	int i = hash(value);
	struct node* temp = array[i];
	struct node* holdFollowing;
	
	if(array[i]->value == value){
		array[i] = array[i]->next;
		free(temp);
		return;
	}
	
	while(temp->next != NULL){
		holdFollowing = temp->next;
		if(holdFollowing->value == value){
			temp->next = holdFollowing->next;
			free(holdFollowing);
			break;
		}
		temp = temp->next;
	}
	
}	

