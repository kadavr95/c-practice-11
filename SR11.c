//��������������� ������ 11. ������� 1. ������� ������� (T02-01c). Dimini Inc. (c)2013
#include <stdio.h>//����������� ���������� �����/������
#include <string.h>//����������� ���������� ������ �� ��������
#include <stdlib.h>
#include <time.h>

#define NUMBER 21

int search(char *string, int *length); //�������� �������
int fillarray(int *rowf,int *columnf);
int fillfile(int *rowf,int *columnf);
int cleararray(int *rowf, int *columnf);
int readfile(int *rowf,int *columnf);
int maxfind(int *rowf,int *columnf);
long int array[31][21];

int main(void)//������� �������
{
	int length=-1,row,column;//����������� ����������
	char string [100000], charmax[100000];
	//int array[31][21];
	fillarray(&row,&column);
	fillfile(&row,&column);
	cleararray(&row,&column);
	readfile(&row,&column);
	printf("%ld %ld",row,column);
	printf("Enter string: ");//������ �����
	gets(string);//���������� ������
	search(string,&length);//����������� ������������ ����� �����
	printf("Long word(s):");//�������, �������������� �����
	search(string,&length);//����� � ����� ���� � ������������ ������
	fflush(stdin);//�������� �������� ������������
	getchar();
	return 0;
}


int readfile(int *rowf,int *columnf)
{
int i,j,pos;
char fullstring[NUMBER*25];
char string[NUMBER];
FILE *filepointer;
  if ((filepointer = fopen("SR11","r"))==NULL) {
printf("Error while opening the file.\n");
exit(1);
}
fgets(fullstring,NUMBER*23,filepointer);
for (i = 1; i < *rowf; i++) {
 pos=strchr(fullstring,' ');
}
}
int fillfile(int *rowf,int *columnf)
{
int i,j;
   FILE *filepointer;
   char string[NUMBER];
  if ((filepointer = fopen("SR11","w"))==NULL) {
printf("Error while opening the file.\n");
exit(1);
}
 for (i = 1; i <=*rowf ; i++) {
	 for (j = 1; j <= *columnf; j++) {
	  ltoa(array[i][j],string,10);
	  fputs(string,filepointer);
	  fputs(" ",filepointer);
	 }
	 fputs("\n\n",filepointer);
}
 }

int fillarray(int *rowf,int *columnf)
{
	int i,j;
		int stime;
	long int ltime;
   //	int array[31][21];
	ltime=time(NULL);
	stime=(unsigned) ltime/2;
	srand(stime);
	*rowf=1+30*rand()/RAND_MAX;
	*columnf=1+20*rand()/RAND_MAX;
	for (i = 1; i <=*rowf ; i++) {
	 for (j = 1; j <= *columnf; j++) {
	  array[i][j]=-RAND_MAX+2*rand();
	 }
	}
}

int cleararray(int *rowf, int *columnf)
{
	int i,j;
		for (i = 0; i <=31 ; i++) {
	 for (j = 0; j <=21; j++) {
	  array[i][j]=0;
	 }
	}
}

int search(char *string, int *length)//������� ������ �� �������
{
	int i,j=0,l,lmax=0;//����������� ����������
	char string1[100000],charword1[100000],symbol;
	memset(charword1,0,sizeof(charword1));//������� ���������� ��� �������� �����
	strcpy(string1,string);//����� ������ � ��������� ����������
	for (i = 0; i < strlen(string1); i++)//���� ������� �������� ������
	{
		symbol=string1[i];//���������� �������
		if ((strchr(" `~!@#$%^&*()_+{}|:<>?/.,\][-	",symbol))|| (i==(strlen(string1)-1)))//������� ����� ����� ��� ����� ������
		{
			if (i==(strlen(string1)-1))//�������� � ������ ����� ������
			{
				charword1[i-j]=symbol;//���������� ���������� �����
			}
			j=i+1;//��������� ���������� ���������� �� ����� ���������� ������� � �����
			if (*length==-1)//��������, ���� �� �������� ������������ �����
			{
				l=strlen(charword1);//����������� ����� �����
				if (l>lmax)//������� ������ ������������� ��������
				{
					lmax=l;//������������ ������ ������������� ��������
				}
				if ((strchr(" `~!@#$%^&*()_+{}|:<>?/.,\][-	",string[i-1]))==0)
				{
					printf("%s\n",charword1);
				}
			}
			else//��������, ���� �������� ������������ �����
			{
				if (strlen(charword1)==*length)//�������� ��������� ����� ����� ������������� ��������
				{
					printf(" %s",charword1);//����� �����
				}
			}
			memset(charword1,0,sizeof(charword1));//����� ���������� �� ������
		}
		else//��������, ���� ����� ��� �� �����������
		{
			charword1[i-j]=symbol;//������ ������� � ���������� ��� �����
		}
	}
	if (*length==-1)//��������, ���� �� �������� ������������ �����
	{
		*length=lmax;//�������� ������������ ����� � ��������
	}
}
