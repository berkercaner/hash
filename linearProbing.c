#include <stdio.h>
#include <stdlib.h>
#include "linearProbing.h"

struct element{
	int value;
	int key;
};

struct element* arrayLP[SIZE];

unsigned char elementCount = 0;

void initLP(){
	for(int i = 0; i<SIZE; i++)
		arrayLP[i] = NULL;
}

int hash(int value){
	return value%SIZE;
}
	
int rehash(int value){
	return ((hash(value) + 1)%SIZE);
}

int getValueLP(int value){
	int i = hash(value);
	while(arrayLP[i] != NULL){
		if(arrayLP[i]->value == value)
			return 1;
		i = (hash(i)+1)%SIZE;
	}
	return -1;
}


void addValueLP(int value){
	struct element* node = (struct element*) malloc(sizeof(struct element));
	node->value = value; 
	node->key = hash(value);
	int i = hash(value);
	while(arrayLP[i] != NULL){
		i = (hash(i)+1)%SIZE;
	}
	arrayLP[i] = node;
	elementCount++;
}


void printLP(){
	int i;
	for(i = 0; i<SIZE; i++){
		if(i < oneDigitNumb)
			printf("HASH[%d]\t   =	 ",i);
		else
			printf("HASH[%d]   =	 ",i);
		if(arrayLP[i] == NULL)
			printf("NULL\n");
		else
			printf("%d\n",arrayLP[i]->value);
	}
	printf("\n");
}

void deleteLP(int value){
	int i = hash(value);
	while(arrayLP[i] != NULL){
		if(arrayLP[i]->value == value){
			arrayLP[i] = NULL;
			break;
		}
		else
			i = (hash(i) + 1)%SIZE;
	}
}


























