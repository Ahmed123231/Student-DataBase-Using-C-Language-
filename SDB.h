#ifndef _SDB_H_
#define _SDB_H_

#include "STD.h"

typedef struct {
	
	uint32 Student_ID;
	uint32 Student_year;
	uint32 Course1_ID;
	uint32 Course1_grade;
	uint32 Course2_ID;
	uint32 Course2_grade;
	uint32 Course3_ID;
	uint32 Course3_grade;
}SimpleDb;




bool SDB_IsFull(void);

uint8 SDB_GetUsedSize(SimpleDb *ptr);
bool SDB_AddEntry(SimpleDb *ptr);
void SDB_DeleteEntry(uint32 id);
bool SDB_ReadEntry(uint32 id);
void SDB_GetList(uint8 *count ,uint32 *list);
bool SDB_IsIdExist(uint32 id);
void SDB_APP(void);


#endif //_SDB_H_