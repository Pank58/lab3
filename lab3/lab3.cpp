#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE  
#define _CRT_NONSTDC_NO_DEPRECATE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
	char inf[256];  // полезная информация
	/*int prior;*/
	struct node* next; // ссылка на следующий элемент 
};
struct node* head = NULL, * last = NULL, * f = NULL; // указатели на первый и последний элементы списка
char specchar = '+';
int g = 0;

int spstore();
void review(void), del(char* name);

char find_el[256];
struct node* find(char* name); // функция нахождения элемента
struct node* get_struct(void); // функция создания элемента



struct node* get_struct(void)
{
	struct node* p = NULL;
	char s[256];
	int num=0;

	if ((p = (node*)malloc(sizeof(struct node))) == NULL)  // выделяем память под новый элемент списка
	{
		printf("Memory allocation error\n");
		exit(1);

	}

	printf("object name: \n");   // вводим данные
	scanf("%s", s);
	fflush(stdin);
	if (*s == 0)
	{
		printf("No recording was made\n");
		return NULL;
	}
	strcpy(p->inf, s);

	//printf("object priority: \n");   // вводим данные
	//scanf("%d", &num);
	//fflush(stdin);

	//p->prior = num;

	p->next = NULL;
	
	return p;		// возвращаем указатель на созданный элемент
}

/* Последовательное добавление в список элемента (в конец)*/
int spstore()
{
	struct node* p = NULL;
	struct node* struc = head;
	p = get_struct();
	if (head == NULL && p != NULL)	// если списка нет, то устанавливаем голову списка
	{
		head = p;
		last = p;
	}
	else if (head != NULL && p != NULL) // список уже есть, то вставляем в конец 
	{
		p->next=head;
		head = p;
	}
	printf("next? (+ or -)\n");
	scanf(" %c", &specchar);
	getchar();
	if (specchar == '+') {

		g = 1;
	}
	else {
		g = 0;
	}
	
	return (g);
}


/* Просмотр содержимого списка. */
void review(void)
{
	struct node* struc = head;
	if (head == NULL)
	{
		printf("The list is empty\n");
	}
	while (struc)
	{
		printf("name - %s\n", struc->inf);
		struc = struc->next;
	}
	return;
}

/* Поиск элемента по содержимому. */
struct node* find(char* name)
{
	struct node* struc = head;
	if (head == NULL)
	{
		printf("Список пуст\n");
	}
	while (struc)
	{
		if (strcmp(name, struc->inf) == 0)
		{
			return struc;
		}
		struc = struc->next;
	}
	printf("Элемент не найден\n");
	return NULL;
}

/* Удаление элемента по содержимому. */
void del()
{
	struct node* struc = head; // указатель, проходящий по списку установлен на начало списка
	struct node* prev=NULL;
	int flag = 0;      // индикатор отсутствия удаляемого элемента в списке

	if (head == NULL) // если голова списка равна NULL, то список пуст
	{
		printf("Список пуст\n");
		return;
	}

	prev = struc->next;
	head = prev;
	free(struc);

}

int main(){
	
	spstore();

	while (g==1) {
		g=spstore();
	}
	review();
	del();
	printf("Delet objekt\n");
	review();

}
