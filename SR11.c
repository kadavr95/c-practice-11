//��������������� ������ 11. ������� 1. ������� ������� (T02-01c). Dimini Inc. (c)2013
#include <stdio.h>//����������� ���������� �����/������
#include <string.h>//����������� ���������� ������ �� ��������
#include <stdlib.h>//����������� ����������� ����������
#include <time.h>//����������� ���������� ����/�������

#define NUMBER 21//������� ������������� ����� �������� � ������

int search(char *string, int *ii); //��������� �������
int fillarray(int *rowf,int *columnf);
int fillfile(int *rowf,int *columnf);
int cleararray(int *rowf, int *columnf);
int readfile(int *rowf,int *columnf);
int maxfind(int *rowf,int *columnf);
int printarray(int *rowf,int *columnf);

long int array[31][21];//����������� ����������� �������

int main(void)//������� �������
{
	int row,column;//����������� ����������
	fillarray(&row,&column);//���������� ������� ���������� �������
	fillfile(&row,&column);//���������� ����� ���������� �� �������
	cleararray(&row,&column);//������� �������
	readfile(&row,&column);//���������� �� ����� � ������
	maxfind(&row,&column);//����� ������������ ��������� �������
	printf("Rows, which contain maximum number\n");//��������������� �����
	printarray(&row,&column);//����� ����� ���������� ������������ ��������
	fflush(stdin);//�������� �������� ������������
	getchar();
	return 0;
}

int fillarray(int *rowf,int *columnf)//���������� ������� ���������� �������
{
	int i,j;//����������� ����������
	int stime;
	long int ltime;
	ltime=time(NULL);//�������� ��������� ������������������ �����
	stime=(unsigned) ltime/2;
	srand(stime);
	*rowf=1+30*rand()/RAND_MAX;//������� ���������� ����� �����
	*columnf=1+20*rand()/RAND_MAX;//������� ���������� ����� ��������
	for (i = 1; i <=*rowf ; i++)//���� �� ���� ���������
	{
		for (j = 1; j <= *columnf; j++)
		{
			array[i][j]=-RAND_MAX+2*rand();//���������� �������
		}
	}
}

int fillfile(int *rowf,int *columnf)//���������� ����� ���������� �� �������
{
	int i,j;//����������� ����������
	FILE *filepointer;
	char string[NUMBER];
	if ((filepointer = fopen("SR11","w"))==NULL)//�������� �����
	{
		printf("Error while opening the file.\n");
		exit(1);
	}
	for (i = 1; i <=*rowf ; i++)//���� �� ���� ���������
	{
		for (j = 1; j <= *columnf; j++)
		{
			ltoa(array[i][j],string,10);//������� �� ����� � ������
			fputs(string,filepointer);//������ ����� � ��������� ������� � ����
			fputs(" ",filepointer);
		}
		fputs("\n",filepointer);//������� �� ��������� ������
	}
	fclose(filepointer);//�������� �����
 }

int cleararray(int *rowf, int *columnf)//������� �������
{
	int i,j;//����������� ����������
	for (i = 0; i <=31 ; i++)//���� �� ���� ���������
	{
		for (j = 0; j <=21; j++)
		{
			array[i][j]=0;//��������� ��������
		}
	}
}

int readfile(int *rowf,int *columnf)//���������� �� ����� � ������
{
	int ii,j,pos,length;//����������� ����������
	char fullstring[NUMBER*21];
	char string[NUMBER];
	FILE *filepointer;
	if ((filepointer = fopen("SR11","r"))==NULL)//�������� �����
	{
		printf("Error while opening the file.\n");
		exit(1);
	}
	for (ii = 1; ii <= *rowf; ii++)//���� �� �������
	{
		fgets(fullstring,NUMBER*21,filepointer);//���������� ����������
		search(fullstring,&ii);//����� ��������� ����� � ������
	}
	fclose(filepointer);//�������� �����
}

int search(char *string, int *ii)//����� ��������� ����� � ������
{
	int i,j=0,k=1;//����������� ����������
	char string1[100000],charword1[100000],symbol;
	memset(charword1,0,sizeof(charword1));//������� ���������� ��� �������� �����
	strcpy(string1,string);//����� ������ � ��������� ����������
	for (i = 0; i < strlen(string1); i++)//���� ������� ������
	{
		symbol=string1[i];//���������� �������
		if ((strchr(" ",symbol))|| (i==(strlen(string1)-1)))//������� ����� ����� ��� ����� ������
		{
			if (i==(strlen(string1)-1))//�������� � ������ ����� ������
			{
				charword1[i-j]=symbol;//���������� ���������� �����
			}
			j=i+1;//��������� ���������� ���������� �� ����� ���������� ������� � �����
			array[*ii][k]=atol(charword1);//������� �� ������ � ����� � ������ � ������
			k=k+1;//������� � ���������� �������� �������
			memset(charword1,0,sizeof(charword1));//����� ���������� � ������
		}
		else//��������, ���� ����� ��� �� �����������
		{
			charword1[i-j]=symbol;//������ ������� � ���������� ��� �����
		}
	}
}

int maxfind(int *rowf,int *columnf)//����� ������������ ��������� �������
{
	int i,j,max=-2*RAND_MAX,ii;//����������� ����������
	for (i = 1; i <=*rowf ; i++)//���� �� ���� ���������
	{
		for (j = 1; j <= *columnf; j++)
		{
			if (array[i][j]>max)//���� ������� ������� ������� ������ �������������, ��
			{
				max=array[i][j];//������������ ������������� �������� �������� ��������
				for (ii = 0; ii < i; ii++)//���� �� ������� �� �������
				{
					array[ii][0]=0;//������� ����� � ���������� � ������� ������������� ��������
				}
				array[i][0]=42;//��������� ����� � ���������� � ������ ������������� �������� (*)

		   }
		   if (array[i][j]==max)//���� ������� ������� ������� ����� �������������, ��
		   {
				array[i][0]=42;//��������� ����� � ���������� � ������ ������������� �������� (*)

		   }

		}
	}
}

int printarray(int *rowf,int *columnf)//����� ����� ���������� ������������ ��������
{
	int i,j;//����������� ����������
	for (i = 1; i <=*rowf ; i++)//���� �� �������
	{
		if (array[i][0]==42)//�������� ������� ����� � ������������ ��������
		{
			for (j = 1; j <= *columnf; j++)//���� �� ����� ��������
			{
				printf("%8ld",array[i][j]);//����� �������� ��������
			}
			printf("\n\n");//������� � ��������� ������
		}
	}
}

//(*) 42 - ����� �� ������� ������ �����, ��������� � ����� ������
