#include<stdio.h>
#include<stdlib.h>
int main()
{
FILE *fptr1,*fptr2;
char filename[30],c;
printf("enter the name of the file to be opened for reading:\n");
scanf("%s",filename);
fptr1=fopen(filename,"r");
if(fptr1==NULL)
{
	printf("unable to open the file %s",filename);
	exit(0);
}
printf("enter the name of the file to be opened for writing:\n");
scanf("%s",filename);
fptr2=fopen(filename,"w");
if(fptr2==NULL)
{
	printf("unable to open the file %s",filename);
	exit(0);
}
c=fgetc(fptr1);
while(c!=EOF)
{
	fputc(c,fptr2);
	c=fgetc(fptr1);
}
printf("content copied\n");
fclose(fptr1);
fclose(fptr2);
return 0;
}