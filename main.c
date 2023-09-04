#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include "Imp.h"


int main()
{

	do
	{
		system("cls");
		menu();
		switch (OptionMenu)
		{
		case ADD: // ADD
			Add_student();

			break;

		case SEARCH: // search
			search(person);
			break;

		case VIEW_ALL: // view all
			view_all();
			break;

		case MODIFY: // modify
			modify(person);
			break;

		case REMOVE: // remove
			Remove_Student(person);

			break;

		case EXIT:

			return 0;
			system("cls");
		default:
			Mess_ERROR();
		}
		Mess_Again();

	} while ((!strcmp(YesOrNo, "y")) || (!strcmp(YesOrNo, "Y")));
	free_memory(person);
}

