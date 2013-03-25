//Самостоятельная работа 11. Вариант 1. Яскович Дмитрий (T02-01c). Dimini Inc. (c)2013
#include <stdio.h>//подключение библиотеки ввода/вывода
#include <string.h>//подключение библиотеки работы со строками
#include <stdlib.h>
#include <time.h>

#define NUMBER 21

int search(char *string, int *length); //прототип функции
int fillarray(int *rowf,int *columnf);
int fillfile(int *rowf,int *columnf);
int cleararray(int *rowf, int *columnf);
int readfile(int *rowf,int *columnf);
int maxfind(int *rowf,int *columnf);
long int array[31][21];

int main(void)//главная функция
{
	int length=-1,row,column;//определение переменных
	char string [100000], charmax[100000];
	//int array[31][21];
	fillarray(&row,&column);
	fillfile(&row,&column);
	cleararray(&row,&column);
	readfile(&row,&column);
	printf("%ld %ld",row,column);
	printf("Enter string: ");//запрос ввода
	gets(string);//считывание строки
	search(string,&length);//определение максимальной длины слова
	printf("Long word(s):");//надпись, сопровождающая вывод
	search(string,&length);//поиск и вывод слов с максимальной длиной
	fflush(stdin);//ожидание действий пользователя
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

int search(char *string, int *length)//функция работы со строкой
{
	int i,j=0,l,lmax=0;//определение переменных
	char string1[100000],charword1[100000],symbol;
	memset(charword1,0,sizeof(charword1));//очистка переменной для текущего слова
	strcpy(string1,string);//сброс данных в локальную переменную
	for (i = 0; i < strlen(string1); i++)//цикл прохода введённой строки
	{
		symbol=string1[i];//считывание символа
		if ((strchr(" `~!@#$%^&*()_+{}|:<>?/.,\][-	",symbol))|| (i==(strlen(string1)-1)))//условие конца слова или конца строки
		{
			if (i==(strlen(string1)-1))//действия в случае конца строки
			{
				charword1[i-j]=symbol;//завершение считывания слова
			}
			j=i+1;//изменение переменной отвечающей за место считанного символа в слове
			if (*length==-1)//действия, если не известна максимальная длина
			{
				l=strlen(charword1);//определение длины слова
				if (l>lmax)//условие нового максимального значения
				{
					lmax=l;//присваивание нового максимального значения
				}
				if ((strchr(" `~!@#$%^&*()_+{}|:<>?/.,\][-	",string[i-1]))==0)
				{
					printf("%s\n",charword1);
				}
			}
			else//действия, если известна максимальная длина
			{
				if (strlen(charword1)==*length)//проверка равенства длины слова максимальному значению
				{
					printf(" %s",charword1);//вывод слова
				}
			}
			memset(charword1,0,sizeof(charword1));//сброс переменной со словом
		}
		else//действия, если слово ещё не закончилось
		{
			charword1[i-j]=symbol;//запись символа в переменную для слова
		}
	}
	if (*length==-1)//действия, если не известна максимальная длина
	{
		*length=lmax;//передача максимальной длины в параметр
	}
}
