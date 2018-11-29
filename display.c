#include<stdio.h>
#include<stdlib.h>

int main()
{
	char message[512];
	int v1 = 0, v2 = 0, v3 = 0, v4 = 0, v5 = 0, v6 = 0, v7 = 0, v8 = 0, v9 = 0, v0 = 0, line[10];
        line[0] = 1, line[1] = 2, line[2] = 3, line[3] = 4, line[4] = 5, line[5] = 6, line[6] = 7, line[7] = 8; line[8] = 9, line[9] = 10, line[10] = 11;
	FILE *display = fopen("stock.txt", "r");
	printf("The product record has display below: \n", "stock.txt");
	while(fgets(message, sizeof(message), display) != NULL) {
                if(v1 == line[0]) {
                    /* Display Item Name*/
                    printf("\n%s", message);
                    line[0] += 11;
                } if(v2 == line[1]) {
                    /* Display Item ID*/
                    printf("%s", message);
                    line[1] += 11;
                } if(v3 == line[2]) {
                    printf("%s", message);
                    line[2] += 11;
                } if(v4 == line[3]) {
                    printf("%s", message);
                    line[3] += 11;
                } if(v5 == line[4]) {
                    printf("%s", message);
                    line[4] += 11;
                } if(v6 == line[5]) {
                    printf("%s", message);
                    line[5] += 11;
                } if(v7 == line[6]) {
                    printf("%s", message);
                    line[6] += 11;
                } if(v8 == line[7]) {
                    printf("%s", message);
                    line[7] += 11;
                } if(v9 == line[8]) {
                    printf("%s", message);
                    line[8] += 11;
                } if(v0 == line[9]) {
                    printf("%s", message);
                    line[9] += 11;
                }else {
                    v1++;
                    v2++;
                    v3++;
                    v4++;
                    v5++;
                    v6++;
                    v7++;
                    v8++;
                    v9++;
                    v0++;
                }
            }
	fclose(display);
	
	return 0;
}
