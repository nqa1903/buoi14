#include <stdio.h>

struct Student{
	char name[50];
	int age;
	double phone;
	char email[50];
};

void display(struct Student s);

int main(){
	struct Student s1;
	printf("Nhap ten sinh vien : ");
	gets(s1.name);
	printf("Tuoi sinh vien : ");
	scanf("%d",&s1.age);
	printf("SDT sinh vien : ");
	scanf("%d",&s1.phone);
	fflush(stdin);
	printf("Nhap email : ");
	gets(s1.email);
	display(s1);
	return 0;
}

void display(struct Student s){
	printf("Sinh vien %s co tuoi la %d \n",s.name , s.age);
	printf("SDT sinh vien la %d \n",s.phone);
	printf("Email sinh vien la %s \n",s.email);
}
