#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
/* Data modify*/

int main()
{
	int record_id_ans, line_num, j = 0;
//	int modifynum;
//	char item, cata, delivery;
//	float price;
	char str[1000]; 
	FILE *modify;
    FILE *cmodify;
    modify = fopen("stock.txt", "r");
    cmodify = fopen("cstock.txt", "w");
    
	enterRecord:
	printf("Please input the record ID: ");
	scanf("%d", &record_id_ans);
	fflush(stdin);
	
	/* Input checking */
	if(record_id_ans < 1000){
		printf("Input valid too small. Please input again!");
		Sleep(1500);
		system("cls");
		goto enterRecord;}
		else if(record_id_ans > 10000){
			printf("Input valid too large. Please input again!");
			Sleep(1500);
			system("cls");
			goto enterRecord;}
		
	line_num = ((record_id_ans - 1000) * 12) + 1;
	line_num++;
	
	while (!feof(modify))
        {
        	strcpy(str, "\0");
        	fgets(str, 1000, modify);
            if (!feof(modify))
            {
                j++;
                if(j == line_num && j == line_num + 1 && j == line_num + 2 && j == line_num + 3 && j == line_num + 4 && j == line_num + 5 && j == line_num + 6 && j == line_num + 7 && j == line_num + 8 && j == line_num + 9)
                {	printf("%s\n", str);}
            }}

	
	/* Tell user which function they can use */
/*	printf("You are allowed to modify the content of 'Item name', 'Price', 'Catagory', 'Delivery Status'!");
	enterans:
	printf("\nModify 'Item name' press<1>, 'Price' press<2>, 'Catagory' press<3>, 'Delivery Status' press<4>: ");
	scanf("%d", &modifynum);
	
	// Data validation
	if(modifynum != 1 || modifynum != 2 || modifynum != 3 || modifynum != 4){
		printf("Incorrect input. Please input again!");
		Sleep(1500);
		system("cls");
		goto enterans;}	
		else if(modifynum == 1){
			printf("Item name: ");
        	fflush(stdin);
        	scanf("%d", &item);
        	fprintf(cmodify, "%d\n", item);}
        	else if(modifynum == 2){
					printf("Prices: ");
        			fflush(stdin);
        			scanf("%d", &price);
        			fprintf(cmodify, "%d\n", price);}
        		else if(modifynum == 3){
						printf("Catagory: ");
        				fflush(stdin);
        				scanf("%d", &cata);
        				fprintf(cmodify, "%d\n", cata);}
        			else if(modifynum == 1){
							printf("Delivery Status: ");
        					fflush(stdin);
        					scanf("%d", &item);
        					fprintf(cmodify, "%d\n", delivery);}
    	 
*/	

    fclose(modify);
/*	remove("stock.txt");
	rename("cstock.txt", "stock.txt");*/
	return 0;
}
