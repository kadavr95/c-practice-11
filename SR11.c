//��������������� ������ 11. ������� 1. ������� ������� (T02-01c). Dimini Inc. (c)2013
#include <stdio.h>//����������� ���������� �����/������
#include <string.h>//����������� ���������� ������ �� ��������
#include <stdlib.h>
#include <time.h>

int search(char *string, int *length); //�������� �������
int fillarray(int *(int *(A+i)+j)));

int main(void)//������� �������
{
	int length=-1,row,column;//����������� ����������
	char string [100000], charmax[100000];
	int array[31][21];
	FILE *fp;

	fillarray(&array[31][21]);
if ((fp = fopen("test","w"))==NULL) {
printf("������ ��� �������� �����.\n");
exit(1);
}
	printf("Enter string: ");//������ �����
	gets(string);//���������� ������
	search(string,&length);//����������� ������������ ����� �����
	printf("Long word(s):");//�������, �������������� �����
	search(string,&length);//����� � ����� ���� � ������������ ������
	fflush(stdin);//�������� �������� ������������
	getchar();
	return 0;
}

int fillarray(int *(int *(A+i)+j)))
{
	int i,j,rowf,columnf;
		int stime;
	long int ltime;
   //	int array[31][21];
	ltime=time(NULL);
	stime=(unsigned) ltime/2;
	srand(stime);
	rowf=1+30*rand()/RAND_MAX;
	columnf=1+20*rand()/RAND_MAX;
	for (i = 1; i <=rowf ; i++) {
	 for (j = 1; j <= columnf; j++) {
	   *(*(A+i)+j))=-RAND_MAX+2*rand();
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

