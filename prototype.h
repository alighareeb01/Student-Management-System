typedef struct xx
{
	char name[30];
	int ID;
	char department[30];

} student;
void stringInput(char str[]);
void menu(void);
void Add_student(void);
void view_all(void);
void search(student *a[]);
void Remove_Student(student *a[]);
void view(student *p);
void modify(student *a[]);
void Mess_ERROR(void);
void Mess_Again(void);
int empty(void);
void free_memory(student *a[]);