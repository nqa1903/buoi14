#include <stdio.h>

int main(){
	struct Student{
		char name[50];
		int age;
		double phone;
		char email[50];
	};
	
	struct Student s = {
		"Ngo Quang Anh",
		20,
		65819,
		"ngoquanganh2003a@gmail.com",
	};
	printf("Sinh vien %s co tuoi la %d \n",s.name , s.age);
	printf("SDT sinh vien la %d \n",s.phone);
	printf("Email sinh vien la %s \n",s.email);
}
