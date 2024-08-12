#include <stdio.h>
#include "SDB.h"
#include "STD.h"


void SDB_action(uint8 choice);
extern SimpleDb Students[10];  //Using extern Keyword To explain that the array is inzialized in another file

void SDB_APP(void){
	int entry=0;
	while(1){
		//User's interface program
		printf("\n");
		printf("1. To Add Entry---------------------->Enter |1\n");
		printf("2. To Get Used Size In The Database-->Enter |2\n");
		printf("3. To Read Student Data-------------->Enter |3\n");
		printf("4. To Get A list of all Students IDs->Enter |4\n");
		printf("5. To check If ID is existing-------->Enter |5\n");
		printf("6. To delete A Student Data---------->Enter |6\n");
		printf("7. To Check is The Database is full-->Enter |7\n");
		printf("8. To Exit The App------------------->Enter |0\n");
		scanf("%d",&entry);
		SDB_action(entry);
		if(entry==0){
			break;
		}
		// Error Handling for user's interface 
		if((int)entry<=0 ||scanf("%d",&entry) !=1){
				printf("Invalid Input \n");
				while (getchar() != '\n');
				fflush(stdout);
			}
	
		
	}
		
}
void SDB_action(uint8 choice){
	
		int id=0;   //Creating 3 id's variables to store users id entry
		int id_1=0;
		int id_2=0;
		int SDB_AddEntry_State=0; // Creating 4 state variables to store thr return value of called functions 
		int IsIdExist_State=0;
		int SDB_IsFull_state=0;
		int SDB_ReadEntry_state=0;
		int used_Size=0;  //varaible to store function database size output
		uint32  list[10]={0}; //creating a list and count variable to store user's count entry and a list to store the id's int the database
		uint8   count=0;
		uint8  *ptr_count=&count;
		
		//Calling the choosed function depending of user's choice from user's interface
		switch(choice){
			case 0:
				break; // Exit the program
			
			case 1:
				SDB_AddEntry_State = SDB_AddEntry(Students);
				printf("%d",SDB_AddEntry_State);
				break;
			case 2:
			
				used_Size=SDB_GetUsedSize(Students);
				printf("USED SIZE : %d || Left : %d",used_Size,(10-used_Size));
				break;
			case 3:
			
				printf("Enter ID \n");
				scanf("%hd",&id_2);
				SDB_ReadEntry_state = SDB_ReadEntry(id_2);
				break;
				
			case 4:
			
			    printf("Enter count \n");
				scanf("%d",ptr_count);
				SDB_GetList(ptr_count ,list);
				break;
				
			case 5:
				
				printf("Enter ID \n");
				scanf("%hd",&id);
				IsIdExist_State=SDB_IsIdExist(id);
				if(IsIdExist_State==1){
					printf("ID is Found");
				}
				else{
					printf("ID Not Found !!");
				}
				break;
			case 6:
				
				printf("Enter ID \n");
				scanf("%hd",&id_1);
				SDB_DeleteEntry(id_1);
				break;
			case 7:
				SDB_IsFull_state=SDB_IsFull();
				if(SDB_IsFull_state==True){
					printf("Database Is Full");
				}
				else{
					printf("Database Not Full");
				}
				break;
				
			
			
			
			
			
		}
		
	
	
}
