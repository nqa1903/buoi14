#include <stdio.h>
#include <string.h>
int main(){
		struct Book{
			int id;
			char name[50];
			char author[100];
			int price;
		};
		
		struct Book book1 = {
			4, 
			"Anh",
			"Quang",
			140,
		};
		
		struct Book bookList[3] = {
			{1,"book1","author1",100},
			{2,"book2","author2",110},
			{3,"book3","author3",120},
		};
		printf("%s \n",bookList[0].name);
		bookList[1].id;
		bookList[2].price;
		for(int i = 0 ; i < 3 ; i++){
			printf("%s \n",bookList[i].name);
		}
		
		struct Book book2 , book3;
		book2 = book1; // cach 1 su dung phep gan 
		memcpy(&book3 , &book1 , sizeof(struct Book));
		
		printf("Book 2's name = %s \n",book2.name);
		printf("Book 3's name = %s \n",book3.name);
}
