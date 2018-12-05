#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <dirent.h>
#include <limits.h>
#include <unistd.h>

void ini() {
    printf("***   HKUSPACE IRMS MoneyAPI System   ***\n\n");
}

int main() {
    int money;
    system("title HKUSPACE IRMS MoneyAPI System");
    printf("Please Enter Money : ");
    scanf("%d", &money);
    FILE *fileIO = fopen("money.api", "w+");
    putw(money, fileIO);
    fclose(fileIO);

    /*
    switch(confirm_1) {
        case 'N':
        case 'n':
            printf("\nReturn and Re-enter the Data(s) in few second.\n");
            sleep(3);
            return main();
        case 'Y':
        case 'y':
            printf("\nFile and Folders will be created simultaneously ... Please wait ...\n");
            char usrpath[] = "\\userdata", current_dir[100], current_dir2[100], path[512];
            if(getcwd(current_dir, sizeof(current_dir)) == NULL) {
                perror("Error In Detecting Current Dir");
                sleep(2);
                exit(0);
            }
            getcwd(current_dir, sizeof(current_dir));
            strcpy(current_dir2, current_dir);

            strcat(path, current_dir);
            strcat(path, usrpath);
            strcat(path, data.username);

            printf("%s", path);
    }
    */

    return 0;
}
