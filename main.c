#include <stdio.h>
#include <stdlib.h>
#include "separateChaining.h"
#include "linearProbing.h"

int seperateC(){
	int choice,value;
	
	while(1){
	
		printf("\n------------------------\n");
		printf("What do you want to do?\n");
		printf("1-) ADD A VALUE\n");
		printf("2-) FIND A VALUE\n");
		printf("3-) PRINT THE MAP\n");
		printf("4-) DELETE A VALUE\n");
		printf("5-) EXIT SEPERATE CHAINING\n");
		printf("------------------------\n");
		printf("Make a choice :  ");
	
		scanf("%d",&choice);
	
		switch(choice){
			case 1:
				printf("\nEnter the value:  ");
				scanf("%d",&value);
				addValue(value);
				break;
			
			case 2:
				printf("Enter the value:  ");
				scanf("%d",&value);
				findValue(value);
				break;
			
			case 3: 
				printf("\n");
				print();
				break;
			
			case 4:
				printf("\nEnter the value you want to delete:  ");
				scanf("%d",&value);
				deleteValue(value);	
				break;
					
			case 5: 
				return 0;
			
			default:
				break;			
		}
	
	}
	return 0;	
}


int linearProbing(){
	int choice, value;
	
	while(1){
		printf("\n------------------------\n");
		printf("What do you want to do?\n");
		printf("1-) ADD A VALUE.\n");
		printf("2-) GET A VALUE\n");
		printf("3-) DELETE A VALUE\n");
		printf("4-) PRINT THE HASH\n");
		printf("5-) EXIT LINEAR PROBING\n");
		printf("------------------------\n");
		printf("Make a choice :  ");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				if(elementCount >= SIZE){
					printf("\nReached the maximum size\n");
					break;
				}
				printf("\nEnter the value :  ");
				scanf("%d",&value);
				addValueLP(value);
				break;
			
			case 2:
				printf("\n Enter the value :  ");
				scanf("%d",&value);
				printf("%d\n",getValueLP(value));
				break;
				
			case 3: 
				printf("\nEnter the value :  ");
				scanf("%d",&value);
				deleteLP(value);
				
			case 4:
				printLP();
				break;
			
			case 5:
				return 0;
			
			default:
				break;
		}  
	}
	return 0;
}

int main(){
	
	init();
	initLP();
	while(1){
		int whichHash;
		printf("\n------------------------\n");
		printf("1-) Seperate Chaining\n");
		printf("2-) Linear Probing\n");
		printf("------------------------\n");
		printf("Make a choice :  ");
		scanf("%d", &whichHash);
		
		switch(whichHash){
			case 1:
				seperateC();
				break;
				
			case 2:
				linearProbing();
				break;
		}
	
	}

	
return 0;
}
