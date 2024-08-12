build : C_project.exe
	gcc -o build C_project.exe
C_project.exe :
	gcc main.c SDB.c SDBAPP.c SDB.h STD.h -o C_project.exe