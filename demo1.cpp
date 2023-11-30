#include <stdio.h>

int main(){
	struct Address{
		int suite;
		char ward[50];
		char district[50];
		char province[50];
	};
	
	struct Student{
		int id;
		char name[50];
		struct Address address;
	};
	
	struct Student s1 = {
		1,
		"Anh Quang",
		{205 , "Duong quyen" , "Pho vang" , "Ha noi"},
	};
	printf("%d",s1.address.suite);
	return 0;
}
