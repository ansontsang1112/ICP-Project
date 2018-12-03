#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <windows.h> //Windows System Library
#include <unistd.h>
#include <dos.h>
#include <dirent.h>
#include <errno.h>
#include <limits.h>
#include <time.h>

int main()
{
	FILE *data, *cdata;
	int replace_line, linectr = 0, showlinctr = 0, i, ID;
	char str[999], showstr[999];
	char yn;
	
	data = fopen("stock.txt" ,"r");
	if(data == NULL){
		printf("Unable to open the file!!");
		return 0;
	}
	
	cdata = fopen("nstock.txt", "w");
	if(cdata == NULL){
		printf("Unable to open a writting file!!");
		return 0;
	}
	
	do{
		printf("Please ether the ID for delete:");
		fflush(stdin);
		scanf("%d", &ID);
		
		replace_line = ((ID - 1000) * 12) + 1;
		replace_line++;
		
		printf("\nIt is %d that you need to delete (Y/N):", ID);
		fflush(stdin);
		scanf("%c", &yn);
	}while(yn != 'Y');

	char space[] = "---------------------";
	
	while(!feof(data)){
		strcpy(str, "\0");
		fgets(str, 999, data);
		if(!feof(data)){
			linectr++;
			if(linectr != replace_line && linectr != replace_line + 1 && linectr != replace_line + 2 && linectr != replace_line + 3 && linectr != replace_line + 4 && linectr != replace_line + 5 && linectr != replace_line + 6 && linectr != replace_line + 7 && linectr != replace_line + 8 && linectr != replace_line + 9){
				fprintf(cdata, "%s", str);
			}
			else{
					fprintf(cdata, "%s\n", space);
			}
		}
	}
	
	fclose(data);
	fclose(cdata);
	remove("stock.txt");
	rename("nstock.txt", "abc.txt");
	
	printf("\nThe date of %d had been removed....", ID);
	
	return 0;
}
