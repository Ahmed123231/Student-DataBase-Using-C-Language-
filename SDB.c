#include <stdio.h>
#include "SDB.h"




SimpleDb Students[10];// Inzializing array of structs to simulate a data base of 10 students


//Function to return the state of the database either it's full or not 
bool SDB_IsFull(){
	
	if(Students[9].Course3_grade!=0){
		
		return True;
		
	}
	else{
		
		return False;
	}
	
	
}
//function to check how many student's are entered and return the left empty of the data base
uint8 SDB_GetUsedSize(SimpleDb *ptr){
	
	
	
	int count=0;
	for(int i=0;i<9;i++){
		
		if(ptr[i].Student_ID!=0){
			
			count++;
			
		}
		
	}
	return count;	
}
//function to recieve data from the user to store students info
bool SDB_AddEntry(SimpleDb *ptr){
	short int Empty_ID=0;
	int i=-1;
	uint8 Input_1=0;
	uint8 Input_2=0;
	uint8 Input_3=0;
	uint8 Input_4=0;
	uint8 Input_5=0;
	uint8 Input_6=0;
	uint8 Input_7=0;
	uint8 Input_8=0;
	for(i=0;i<10;i++){
		if(ptr[i].Student_ID==0){
			
			Empty_ID=i;
			break;
		}
	}
	if(Empty_ID==-1){
		
		
		printf("Database is full!\n");
		return False;
	}
	short int choice=0;
	while(1){
	printf("Choose Data to Add\n");
	printf("1-Student ID\n");
	printf("2-Student Year\n");
	printf("3-Student Course 1 ID\n");
	printf("4-Student Course 1 Grade\n");
	printf("5-Student Course 2 ID\n");
	printf("6-Student Course 2 Grade\n");
	printf("7-Student Course 3 ID\n");
	printf("8-Student Course 3 Grade\n");
	printf("9-To Go Back\n");
	printf("*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
	printf("NOTE: You Need To Go Back IF You Want to Enter New Student Info \n");
	scanf("%d",&choice);
	if(choice==9){
		break;
	}else if(choice<1||choice>9){
		printf("Invalid Input\n");
		
	}
	
	switch (choice){
		
		case 1:
			printf("Enter Student ID\n");
			scanf("%u",&ptr[Empty_ID].Student_ID);
			if((int)ptr[Empty_ID].Student_ID <=0 ||scanf("%d",&ptr[Empty_ID].Student_ID) !=1){
				printf("Invalid Input \n");
				while (getchar() != '\n');
				fflush(stdout);
			}
			
			break;
		case 2:
			printf("Enter Student Year\n");
			scanf("%d",&ptr[Empty_ID].Student_year);
			if((int)ptr[Empty_ID].Student_year <=0 ||scanf("%d",&ptr[Empty_ID].Student_year)!=1 ){
				printf("Invalid Input \n");
				while (getchar() != '\n'); 
			}
			break;
		case 3:
			printf("Enter Student Course 1 ID\n");
			scanf("%d",&ptr[Empty_ID].Course1_ID);
			if((int)ptr[Empty_ID].Course1_ID <=0 ||scanf("%d",&ptr[Empty_ID].Course1_ID)!=1 ){
				printf("Invalid Input \n");
				while (getchar() != '\n'); 
			}
			break;
		case 4:
			printf("Enter Student Course 1 Grade\n");
			scanf("%d",&ptr[Empty_ID].Course1_grade);
			if((int)ptr[Empty_ID].Course1_grade <=0 ||scanf("%d",&ptr[Empty_ID].Course1_grade)!=1){
				printf("Invalid Input \n");
				while (getchar() != '\n'); 
			}
			break;
		case 5:
			printf("Enter Student Course 2 ID\n");
			scanf("%d",&ptr[Empty_ID].Course2_ID);
			if((int)ptr[Empty_ID].Course2_ID <=0 ||scanf("%d",&ptr[Empty_ID].Course2_ID)!=1){
				printf("Invalid Input \n");
				while (getchar() != '\n'); 
			}
			break;
		case 6:
			printf("Enter Student Course 2 Grade\n");
			scanf("%d",&ptr[Empty_ID].Course2_grade);
			if((int)ptr[Empty_ID].Course2_grade <=0 ||scanf("%d",&ptr[Empty_ID].Course2_grade)!=1){
				printf("Invalid Input \n");
				while (getchar() != '\n'); 
			}
			break;
		case 7:
			printf("Enter Student Course 3 ID\n");
			scanf("%d",&ptr[Empty_ID].Course3_ID);
			if((int)ptr[Empty_ID].Course3_ID <=0 ||scanf("%d",&ptr[Empty_ID].Course3_ID)!=1){
				printf("Invalid Input \n");
				while (getchar() != '\n'); 
			}
			break;
		case 8:
		    printf("Enter Student Course 3 Grade\n");
			scanf("%d",&ptr[Empty_ID].Course3_grade);
			if((int)ptr[Empty_ID].Course3_grade <=0 ||scanf("%d",&ptr[Empty_ID].Course3_grade)!=1){
				printf("Invalid Input \n");
				while (getchar() != '\n'); 
			}
			break;
		default :
			printf("Invalid choice\n");
			return False;
	}

	}
	return True;
}
//function to make the user choose an id of student to delete his related info
void SDB_DeleteEntry(uint32 id){
	
	short int real_id =0;
	for(int i=0;i<10;i++){
		if(id==Students[i].Student_ID){
			real_id=i;
			Students[real_id].Student_ID=0;
			Students[real_id].Student_year=0;
			Students[real_id].Course1_ID=0;
			Students[real_id].Course1_grade=0;
			Students[real_id].Course2_ID=0;
			Students[real_id].Course2_grade=0;
			Students[real_id].Course3_ID=0;
			Students[real_id].Course3_grade=0;
			printf("Data Deleted Succesfully");
			break;
			
		}
		else if (id != Students[i].Student_ID){
			
			printf("ID Not Found Invalid Input !!!");
			break;
		}
		
		
	}
	
	
	

	
}
//function to read the data of given id of the student 
bool SDB_ReadEntry(uint32 id){
	
	short int real_id=0;
	for(int i=0;i<10;i++){
		if(Students[i].Student_ID ==id){
		real_id=i;
		printf("Student ID            : %d\n",Students[real_id].Student_ID);
		printf("Student Year          : %d\n",Students[real_id].Student_year);
		printf("Student Course1_ID    : %d\n",Students[real_id].Course1_ID);
		printf("Student Course1_Grade : %d\n",Students[real_id].Course1_grade);
		printf("Student Course2_ID    : %d\n",Students[real_id].Course2_ID);
		printf("Student Course2_Grade : %d\n",Students[real_id].Course2_grade);
		printf("Student Course3_ID    : %d\n",Students[real_id].Course3_ID);
		printf("Student Course3_Grade : %d\n",Students[real_id].Course3_grade);
		
		return 1;
		break;
			
		}
		
		
	}
	
	return 0;	
}
//function that return a list of the existing id's in the data base 	
void SDB_GetList(uint8 *count, uint32 *list) {
		
	for(int i=0; i<(*count) ;i++){
		list[i]=Students[i].Student_ID;
		
	}
	printf("[");
    for(int j=0;j<(*count);j++){
		
		
		printf(" %d ",list[j]);
		
		
		
	}
	printf("]");
		
	
}	
//function to check if the id given by the user is existing of not 	
bool SDB_IsIdExist (uint32 id){
	
	for(int i=0;i<10;i++){
		
		if(Students[i].Student_ID==id){
			return 1;
			break;
			
			
		}
		
		
	}
	
	return 0;
	
	
}	
