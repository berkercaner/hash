#include <stdio.h>
#include <stdlib.h>

#define HASH_SIZE 10


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
		printf("%d. Index ==>",i);
		while(input){
			printf(" %d ==>",input->value);
			input = input->next;
		}
		printf(" NULL\n");
	}
		
}

int find(int value){
	
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


int main(){

	init();
	
	addValue(11);
	addValue(13);
	addValue(12);
	addValue(21);
	addValue(131);
	addValue(43);
	addValue(399);
	addValue(1);
	addValue(25);
	addValue(66);
	addValue(76);
	addValue(68);
	addValue(69);
	addValue(10);
	addValue(58);
	addValue(65);
	addValue(5);
	print();	
	
	find(0);
	
	
return 0;
}
