#include <stdio.h>
#include <string.h>

int main(){
	struct Student{
		char name[50];
		int id;
		float avarage_score;
	};
	
	struct Student s1{
		"Anh Quang",
		1223,
		8.5,
	};
	
	printf("Ten sinh vien la : %s \n" , s1.name);
	printf("Ma so sinh vien la : %d \n",s1.id);
	printf("Diem trung binh la : %.2f \n",s1.avarage_score);
	return 0;
}
