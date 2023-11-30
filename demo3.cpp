#include <stdio.h>

struct Student{
	char name[50];
	int age;
};

void display (struct Student s);

int main(){
	struct Student s1;
	printf("Enter name : ");
	gets(s1.name);
	
	printf("Enter age : ");
	scanf("%d",&s1.age);
	
	display(s1);
	return 0;
}

void display (struct Student s){
	printf("\n Displaying information \n");
	printf("Name : %s \n",s.name);
	printf("Age : %d",s.age);
}
