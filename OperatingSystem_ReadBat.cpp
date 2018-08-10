#include"conio.h"
#include"stdio.h"
#include"string.h"
#include"stdlib.h"

main()
{
char w[255];
FILE *f=fopen("hello.bat","rt");
if(f==NULL)
	{
	printf("\nError while open file.");
	getch();
	exit(1);
	}
else
	{
	while(!feof(f))
		{
		fgets(w,255,f);
		printf(""); 
		system(w);
		}
	fclose(f);
	//printf("\nDoc thanh cong.\n");
	}
getch();
}
