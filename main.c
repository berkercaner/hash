#include <stdio.h>
#include <stdlib.h>
#include "separateChaining.h"

int main(){

	init();
	int choice,value;
	
	while(1){
	
		printf("\n------Make a choise-----\n");
		printf("1-) ADD A VALUE\n");
		printf("2-) FIND A VALUE\n");
		printf("3-) PRINT THE MAP\n");
		printf("4-) DELETE A VALUE\n");
	
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
		}
	
	}	
return 0;
}
