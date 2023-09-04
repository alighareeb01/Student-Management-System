#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "prototype.h"

#define MAX_NUM_OF_STUDENTS 100


int OptionMenu;
int id_remove;
int count = 0;
int NumOfStudentToAdd;				  // num of student in the system
student *person[MAX_NUM_OF_STUDENTS]; // arr to hold max num of student that can be enrolled


int id_search; // variable to search for by id
char name_search[30];
char department_search[30];

student Search; // varaiable for the return from the search fun

int SearchKey; // key to choose wheter to search by name or id

char YesOrNo[5];

enum menu{ADD = 1, SEARCH = 2, VIEW_ALL = 3, MODIFY = 4,REMOVE = 5, EXIT = 6};

void stringInput(char str[])
{
	fflush(stdin);
	char ch = 0;
	int i = 0;
	while (1)
	{
		scanf("%c", &ch);
		if (ch == '\n')
			break;
		str[i++] = ch;
	}
	str[i] = '\0';
}

void menu(void)
{

	printf("\t\tStudent Managment Stystem\n");
	printf("\t-----------------------------------------\n");
	printf("-----\n");
	printf("Menu:\n");
	printf("-----\n");
	printf("\t\t1. Add Student\n");
	printf("\t\t2. Search for a student\n");
	printf("\t\t3. View All students\n");
	printf("\t\t4. Modify Student\n");
	printf("\t\t5. Remove Student\n");
	printf("\t\t6. Exit\n");
	printf("\t-----------------------------------------\n");
	printf("Enter Your Choice: ");
	scanf("%d", &OptionMenu);
	printf("-----------------------\n");
}
// to take string from user

void Add_student(void)
{

	student temp;
	printf("Enter number of studens to add: ");
	scanf("%d", &NumOfStudentToAdd);
	for (int i = 0; i < NumOfStudentToAdd; i++)
	{
		printf("student[%d]\n", count + 1);
		printf("------------\n");
		person[count] = (student *)malloc(sizeof(student)); // Allocate memory
		printf("\tID: ");
		scanf("%d", &temp.ID);

		printf("\tStudent Name: ");
		stringInput(temp.name);

		printf("\tDepartment : ");
		stringInput(temp.department);
		*person[count] = temp;
		count++;
	}
}

void view(student *p)
{

	printf("---Student ID: %d\n", p->ID);
	printf("---Student Nam: %s\n", p->name);
	printf("---Student Department: %s\n", p->department);
	printf("---------------------------\n");
}

void view_all(void)
{
	if (count != 0)
	{
		for (int i = 0; i < count; i++)
		{
			view(person[i]);
		}
	}
	else
	{
		printf("No one is enrolled to be shown\n");
		printf("-----------------------------------------\n");
	}
}

void search(student *a[])
{
	if (empty() == 1)
	{
		printf("Enter The ID You Want: ");
		scanf("%d", &id_search);
		int flag_id = 0;
		for (int i = 0; i < count; i++)
		{
			if (a[i]->ID == id_search)
			{
				printf("\n");
				printf("----------Found-------\n");
				view(a[i]);
				flag_id = 1;
			}
		}
		if (!flag_id)
		{
			printf("\n");
			printf("----------Not Found-------\n");
		}
	}
	else
	{
		printf("No one is enrolled to be shown\n");
		printf("-----------------------------------------\n");
	}
}

void Remove_Student(student *a[])
{
	if (empty() == 1)
	{
		printf("Enter the ID You Want To Remove: ");
		scanf("%d", &id_remove);
		int flag_remove = 0;
		int pos;
		for (int i = 0; i < count; i++)
		{
			if (a[i]->ID == id_remove)
			{
				a[i] = a[i + 1];
				count--;
				flag_remove = 1;
				printf("Student Removed Successfully.\n");
			}
		}
		if (!flag_remove)
		{
			printf("You Entered The Wrong ID.\n");
		}
	}
	else
	{
		printf("No one is enrolled to be shown\n");
		printf("-----------------------------------------\n");
	}
}

void modify(student *a[])
{
	student temp;
	int id_mod;
	char name_mod[30];
	char dep_mod[30];
	int pos;
	int flag = 0;
	int mod;
	if (empty() == 1)
	{
		printf("Enter The ID You Want To Modify: ");
		scanf("%d", &id_search);
		for (int i = 0; i < count; i++)
		{
			if (a[i]->ID == id_search)
			{
				pos = i;
				flag = 1;
				break;
			}
		}
		if (!flag)
		{
			printf("You Entered The Wrong ID.\n");
		}

		if (flag)
		{
			printf("What Do You Want To Modify: ");
			printf("1-ID, 2-Name, 3-Department: ");
			scanf("%d", &mod);
			// first search by name to modify
			switch (mod)
			{
			case 1:
				printf("Enter The New ID: ");
				scanf("%d", &id_mod);
				a[pos]->ID = id_mod;
				printf("Student After Modification: \n");
				printf("---------------------------\n");
				view(a[pos]);
				break;
			case 2:
				printf("Enter The New Name: ");
				stringInput(name_mod);
				strcpy(a[pos]->name, name_mod);
				printf("Student After Modification: \n");
				printf("---------------------------\n");
				view(a[pos]);
				break;
			case 3:
				printf("Enter The New Department: ");
				stringInput(dep_mod);
				strcpy(a[pos]->department, dep_mod);
				printf("Student After Modification: \n");
				printf("---------------------------\n");
				view(a[pos]);
				break;
			}
		}
	}
	else
	{
		printf("No one is enrolled to be shown\n");
		printf("-----------------------------------------\n");
	}
}
void Mess_ERROR(void)
{
	printf("\t-----------------------------\n");
	printf("\tYou Entered The Wrong Number\t\n");
	printf("\t-----------------------------\n");
}
void Mess_Again(void)
{
	printf("do you want the menu again: ");
	printf("Enter y/Y for yes and n/N for no: ");
	scanf("%s", YesOrNo);
	system("cls");
}
void free_memory(student *a[])
{

	for (int i = 0; i < count; i++)
	{
		free(person[i]);
	}
	// system("cls");
}
int empty(void)
{
	if (count == 0)

	{
		return 0;
	}
	else
	{
		return 1;
	}
}
