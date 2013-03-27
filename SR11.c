//Самостоятельная работа 11. Вариант 1. Яскович Дмитрий (T02-01c). Dimini Inc. (c)2013
#include <stdio.h>//подключение библиотеки ввода/вывода
#include <string.h>//подключение библиотеки работы со строками
#include <stdlib.h>//подключение стандартной библиотеки
#include <time.h>//подключение библиотеки даты/времени

#define NUMBER 21//задание максимального числа символов в числах

int search(char *string, int *ii); //прототипы функций
int fillarray(int *rowf,int *columnf);
int fillfile(int *rowf,int *columnf);
int cleararray(int *rowf, int *columnf);
int readfile(int *rowf,int *columnf);
int maxfind(int *rowf,int *columnf);
int printarray(int *rowf,int *columnf);

long int array[31][21];//определение глобального массива

int main(void)//главная функция
{
	int row,column;//определение переменных
	fillarray(&row,&column);//заполнение массива случайными числами
	fillfile(&row,&column);//заполнение файла элементами из массива
	cleararray(&row,&column);//очистка массива
	readfile(&row,&column);//считывание из файла в массив
	maxfind(&row,&column);//поиск максимальных элементов массива
	printf("Rows, which contain maximum number\n");//вспомогательный вывод
	printarray(&row,&column);//вывод строк содержащих максимальные элементы
	fflush(stdin);//ожидание действий пользователя
	getchar();
	return 0;
}

int fillarray(int *rowf,int *columnf)//заполнение массива случайными числами
{
	int i,j;//определение переменных
	int stime;
	long int ltime;
	ltime=time(NULL);//создание случайной последовательности чисел
	stime=(unsigned) ltime/2;
	srand(stime);
	*rowf=1+30*rand()/RAND_MAX;//задание случайного числа строк
	*columnf=1+20*rand()/RAND_MAX;//задание случайного числа столбцов
	for (i = 1; i <=*rowf ; i++)//цикл по всем элементам
	{
		for (j = 1; j <= *columnf; j++)
		{
			array[i][j]=-RAND_MAX+2*rand();//заполнение массива
		}
	}
}

int fillfile(int *rowf,int *columnf)//заполнение файла элементами из массива
{
	int i,j;//определение переменных
	FILE *filepointer;
	char string[NUMBER];
	if ((filepointer = fopen("SR11","w"))==NULL)//создание файла
	{
		printf("Error while opening the file.\n");
		exit(1);
	}
	for (i = 1; i <=*rowf ; i++)//цикл по всем элементам
	{
		for (j = 1; j <= *columnf; j++)
		{
			ltoa(array[i][j],string,10);//перевод из числа в строку
			fputs(string,filepointer);//запись числа в строковом формате в файл
			fputs(" ",filepointer);
		}
		fputs("\n",filepointer);//переход на следующую строку
	}
	fclose(filepointer);//закрытие файла
 }

int cleararray(int *rowf, int *columnf)//очистка массива
{
	int i,j;//определение переменных
	for (i = 0; i <=31 ; i++)//цикл по всем элементам
	{
		for (j = 0; j <=21; j++)
		{
			array[i][j]=0;//обнуление значений
		}
	}
}

int readfile(int *rowf,int *columnf)//считывание из файла в массив
{
	int ii,j,pos,length;//определение переменных
	char fullstring[NUMBER*21];
	char string[NUMBER];
	FILE *filepointer;
	if ((filepointer = fopen("SR11","r"))==NULL)//открытие файла
	{
		printf("Error while opening the file.\n");
		exit(1);
	}
	for (ii = 1; ii <= *rowf; ii++)//цикл по строкам
	{
		fgets(fullstring,NUMBER*21,filepointer);//построчное считывание
		search(fullstring,&ii);//поиск отдельных чисел в строке
	}
	fclose(filepointer);//закрытие файла
}

int search(char *string, int *ii)//поиск отдельных чисел в строке
{
	int i,j=0,k=1;//определение переменных
	char string1[100000],charword1[100000],symbol;
	memset(charword1,0,sizeof(charword1));//очистка переменной для текущего числа
	strcpy(string1,string);//сброс данных в локальную переменную
	for (i = 0; i < strlen(string1); i++)//цикл прохода строки
	{
		symbol=string1[i];//считывание символа
		if ((strchr(" ",symbol))|| (i==(strlen(string1)-1)))//условие конца числа или конца строки
		{
			if (i==(strlen(string1)-1))//действия в случае конца строки
			{
				charword1[i-j]=symbol;//завершение считывания числа
			}
			j=i+1;//изменение переменной отвечающей за место считанного символа в числе
			array[*ii][k]=atol(charword1);//перевод из строки в число и запись в массив
			k=k+1;//переход к следующему элементу массива
			memset(charword1,0,sizeof(charword1));//сброс переменной с числом
		}
		else//действия, если число ещё не закончилось
		{
			charword1[i-j]=symbol;//запись символа в переменную для числа
		}
	}
}

int maxfind(int *rowf,int *columnf)//поиск максимальных элементов массива
{
	int i,j,max=-2*RAND_MAX,ii;//определение переменных
	for (i = 1; i <=*rowf ; i++)//цикл по всем элементам
	{
		for (j = 1; j <= *columnf; j++)
		{
			if (array[i][j]>max)//если текущий элемент массива больше максимального, то
			{
				max=array[i][j];//присваивание максимальному значение текущего элемента
				for (ii = 0; ii < i; ii++)//цикл по строкам до текущей
				{
					array[ii][0]=0;//очистка меток о содержании в строках максимального элемента
				}
				array[i][0]=42;//установка метки о содержании в строке максимального элемента (*)

		   }
		   if (array[i][j]==max)//если текущий элемент массива равен максимальному, то
		   {
				array[i][0]=42;//установка метки о содержании в строке максимального элемента (*)

		   }

		}
	}
}

int printarray(int *rowf,int *columnf)//вывод строк содержащих максимальные элементы
{
	int i,j;//определение переменных
	for (i = 1; i <=*rowf ; i++)//цикл по строкам
	{
		if (array[i][0]==42)//проверка наличия метки о максимальном значении
		{
			for (j = 1; j <= *columnf; j++)//цикл по числу столбцов
			{
				printf("%8ld",array[i][j]);//вывод текущего элемента
			}
			printf("\n\n");//переход к следующей строке
		}
	}
}

//(*) 42 - ответ на главный вопрос жизни, вселенной и всего такого
