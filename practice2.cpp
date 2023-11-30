#include <stdio.h>

struct exam_score{
	int id;
	float math_score;
	float liter_score;
};

void display(struct exam_score s);

int main(){
	struct exam_score s1;
	printf("Nhap ma sinh vien : ");
	scanf("%d",&s1.id);
	printf("Diem toan sinh vien : ");
	scanf("%f",&s1.math_score);
	printf("Diem van sinh vien : ");
	scanf("%f",&s1.liter_score);
	display(s1);
}

void display(struct exam_score s){
	printf("Diem sinh vien co ma so %d la \n",s.id);
	printf("Diem toan %.2f \n",s.math_score);
	printf("Diem van %.2f \n",s.liter_score);
}
