//—амосто€тельна€ работа 11. ¬ариант 1. яскович ƒмитрий (T02-01c). Dimini Inc. (c)2013
#include <stdio.h>//подключение библиотеки ввода/вывода
#include <string.h>//подключение библиотеки работы со строками
#include <stdlib.h>
#include <time.h>

#define NUMBER 21

int search(char *string, int *ii); //прототип функции
int fillarray(int *rowf,int *columnf);
int fillfile(int *rowf,int *columnf);
int cleararray(int *rowf, int *columnf);
int readfile(int *rowf,int *columnf);
int maxfind(int *rowf,int *columnf);
int printarray(int *rowf,int *columnf);
long int array[31][21];

int main(void)//главна€ функци€
{
	int length=-1,row,column;//определение переменных
	char string [100000], charmax[100000];
	//int array[31][21];
	fillarray(&row,&column);
	fillfile(&row,&column);
	cleararray(&row,&column);
	readfile(&row,&column);
	maxfind(&row,&column);
	printarray(&row,&column);
	printf("%ld %ld",row,column);
	printf("Enter string: ");//запрос ввода
	gets(string);//считывание строки
	search(string,&length);//определение максимальной длины слова
	printf("Long word(s):");//надпись, сопровождающа€ вывод
	search(string,&length);//поиск и вывод слов с максимальной длиной
	fflush(stdin);//ожидание действий пользовател€
	getchar();
	return 0;
}

int printarray(int *rowf,int *columnf)
{
int i,j;
   for (i = 1; i <=*rowf ; i++) {
	   if (array[i][0]==42) {
	   for (j = 1; j <= *columnf; j++) {
				printf("%8ld",array[i][j]);
	   }
	   }
   }
}
int maxfind(int *rowf,int *columnf)
{
int i,j,max=-2*RAND_MAX,ii;
	 for (i = 1; i <=*rowf ; i++) {
	 for (j = 1; j <= *columnf; j++) {
	   if (array[i][j]>max) {
		max=array[i,j];
		for (ii = 0; ii < i; ii++) {
		 array[ii][0]=0;
		}
		array[i][0]=42;

	   }

     }
     }
}
int readfile(int *rowf,int *columnf)
{
int ii,j,pos,length;
char fullstring[NUMBER*21];
char string[NUMBER];
FILE *filepointer;
  if ((filepointer = fopen("SR11","r"))==NULL) {
printf("Error while opening the file.\n");
exit(1);
}
for (ii = 1; ii <= *rowf; ii++) {
 fgets(fullstring,NUMBER*21,filepointer);
search(fullstring,&ii);   
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
	 fputs("\n",filepointer);
}
fclose(filepointer);
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

int search(char *string, int *ii)//функци€ работы со строкой
{
	int i,j=0,k=1,l,lmax=0;//определение переменных
	char string1[100000],charword1[100000],symbol;
	memset(charword1,0,sizeof(charword1));//очистка переменной дл€ текущего слова
	strcpy(string1,string);//сброс данных в локальную переменную
	for (i = 0; i < strlen(string1); i++)//цикл прохода введЄнной строки
	{
		symbol=string1[i];//считывание символа
		if ((strchr(" ",symbol))|| (i==(strlen(string1)-1)))//условие конца слова или конца строки
		{
			if (i==(strlen(string1)-1))//действи€ в случае конца строки
			{
				charword1[i-j]=symbol;//завершение считывани€ слова
			}
			j=i+1;//изменение переменной отвечающей за место считанного символа в слове
			   //	if (strlen(charword1)==*length)//проверка равенства длины слова максимальному значению
				//{
				   //	printf(" %s",charword1);//вывод слова
				   array[*ii][k]=atol(charword1);
				   k=k+1;
				//}
			memset(charword1,0,sizeof(charword1));//сброс переменной со словом
		}
		else//действи€, если слово ещЄ не закончилось
		{
			charword1[i-j]=symbol;//запись символа в переменную дл€ слова
		}
	}
}
