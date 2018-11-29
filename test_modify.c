#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
/* Data modify*/

int main()
{
	char store[10000];
	int record_id_ans, record_no_ans;
	char ans[1024];
	int n1 = 0, n2 = 0, n3 = 0, n4 = 0, n5 = 0, n6 = 0, n7 = 0, n8 = 0, n9 = 0, n10 = 0, line[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; 
	FILE *modify = fopen("stock.txt", "w");
	enterRecord:
	printf("Please input the record ID: ");
	scanf("%d", &record_id_ans);
	fflush(stdin);
	
	/* Input checking */
	while(record_id_ans < 1000){
		printf("Invaild input. Please input again!");
		Sleep(1000);
		system("cls");
		goto enterRecord;}
	
	record_id_ans = atoi(record_id_ans);
	record_no_ans = (record_id_ans - 1000) * 12 + 1;
	while(fgets(ans, sizeof(ans), modify) != NULL){
		printf("Data from the file:\n");
				  if(n1 == line[0]) {
                    /* Display Item Name*/
                    printf("\n%s", store);
                } if(n2 == line[1]) {
                    /* Display Item ID*/
                    printf("%s", store);
                } if(n3 == line[2]) {
                	/* Display Item ID*/
                    printf("%s", store);
                } if(n4 == line[3]) {
                	/* Display Item ID*/
                    printf("%s", store);
                } if(n5 == line[4]) {
                	/* Display Item ID*/
                    printf("%s", store);
                } if(n6 == line[5]) {
                	/* Display Item ID*/
                    printf("%s", store);
                } if(n7 == line[6]) {
                	/* Display Item ID*/
                    printf("%s", store);
                } if(n8 == line[7]) {
                	/* Display Item ID*/
                    printf("%s", store);
                } if(n9 == line[8]) {
                	/* Display Item ID*/
                    printf("%s", store);
                } if(n10 == line[9]) {
                	/* Display Item ID*/
                    printf("%s", store);
	printf("You are allow to modify the content of 'Item name', 'Price', 'Catagory', 'Delivery Status'!");
	}
    fclose(modify);
	getch();
	return 0;
}
}
