#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <dirent.h>
#include <limits.h>
#include <unistd.h>

struct DATA {
    char username[50];
    char passsword[50];
    int permission;
    int money;
} data;

void ini() {
    printf("***   HKUSPACE IRMS User Account Creation System   ***\n\n");
}

int main() {
	char RP[50] = "Root Permission || System Administrator", SA[50] = "SA Permission || Shop Administrator", CA[50] = "CA Permission || Customer";
    char permission_type[50];
	ini();
    system("title HKUSPACE IRMS User Account Creation System");
    printf("Please Enter following parameter : Username, Password, Permission, Money\n");
    printf("\nUsername: ");
    gets(data.username);
    printf("\nPassword: ");
    gets(data.passsword);
    printf("\nPermission: ");
    scanf("%d", &data.permission);
    printf("\nINI Money: ");
    scanf("%d", &data.money);

    if(data.permission == 0) {
        strcpy(permission_type, RP);
    } if(data.permission == 1) {
        strcpy(permission_type, SA);
    } if(data.permission == 2) {
       strcpy(permission_type, CA);
    }

    /*Confirm Data*/
    char confirm_1;
    system("cls");
    ini();
    printf("Please confirm the following information(s) :\n\n");
    printf("Username : %s\n", data.username);
    printf("Password : %s\n", data.passsword);
    printf("Permission ID : %d\n", data.permission);
    printf("Permission Type : %s\n", permission_type);
    printf("Initiated Money : %d\n\n", data.money);
    printf("Do you confirm the following data ? ( Y / N ) : ");
    scanf("%c", &confirm_1);
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
