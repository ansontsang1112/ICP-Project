#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <Windows.h> //Windows System Library
#include <Lmcons.h> //Username Library
#include <dos.h>

/*Function Proto Type*/
/*Menu GUI(s)*/
void ini();
void menu();
void SysAuth();
void SysAdm();
void ShopAuth();
void ShopAdm();
void CustomerAuth();
void CustomerPanel();

/*Functions*/
void add();
void display();
void search();
void modify();
void delete();

/*Extra*/
void csa();
void csa2();
void emm();
void etm();

/*Functions*/
int auth(char [], int);
void startup();
void WriteInFile();
void failure();
void getConfig();

/*Structs Part*/
struct Data {
    int rid;
    char ItemName[50];
    int id;
    char category[50];
    int quantity;
    double weight;
    char recip[50];
    char FinalDest[50];
    char dev_stat[50];
};

/*Globes Var*/
int counter = 0, ret_counter = 0, role = 0, maintain;
char appear;
char Normal[] = "Please enter the password", LIF[] = "Authorization Failure, Please try again.";

void ini() {
    printf("\t\t\t***   Welcome to HKUSPACE Inventory Management and Record System   ***\n\n");
    printf("\t\t\t\t\t\t***    1819S1    ***\n\n");
    printf("\t\t\t*** This system is developed by CCIT4020 Class No. ?L-?? Group No,?? ***\n\n\n");
}

void menu() {
	startup();
	getConfig();
	system("title HKUSPACE IMRS @ MENU CLI (ROLE)");
    ini();
    char ch1;
    /*Get Username
    wchar_t Username[1000];
    DWORD nUsername = sizeof(Username);
    GetUserName((LPWSTR)Username, &nUsername);*/
    /*RSM Menu*/
    /*printf(" ^v^ Welcome " << (TCHAR)Username << " use our IMRS, please select the options. ^v^\n\n");*/
	printf("~ <Please select the ROLE you are : > ~ \n\n");
    printf(" A: System Administrator\n\n");
    printf(" B: Shop Administrator\n\n");
    printf(" C: Customer\n\n");
    printf("**>> Please remind that you have the permission to login to relative sections. <<**\n\n");
    printf("|| Please insert your Role option <A/B/C> || : ");
    scanf("%c", &ch1);
    switch (ch1) {
        case 'A':
        case 'a':
            printf("\nYou have selected System Administrator Role, You will be redirect to Authorization pages. Please wait for 5 seconds\n");
            system("timeout 5");
            SysAuth();
            break;
        case 'B':
        case 'b':
            printf("\nYou have selected Shop Administrator Role, You will be redirect to Authorization pages. Please wait for 5 seconds\n");
            system("timeout 5");
            ShopAuth();
            break;
        case 'C':
        case 'c':
            printf("\nYou have selected Customer Role, You will be redirect to customer selection page.\n");
            system("timeout 5");
            CustomerAuth();
            break;
        default:
            printf("\nOnly A / B / C are valid options, system will return to RSM in 3 second.\n");
            system("timeout 3");
            system("cls");
            return menu();
    }
};

int main() {
    SysAuth();
}

//Auth. System
void SysAuth() {
	system("cls");
	char pw[20];
	int cls = 0;		
	role = 0;
	system("CLS");
	ini();
	if(counter == 5) {
		printf("You have type in the max. no of wrong password, the program will auto exit in 5 seconds.\n\n");
        system("timeout 5");
        exit(0);	
	}
	printf(">> Status : %s\n\n", (counter == 0) ? Normal : LIF);
	/*UI Section*/
	printf("***   System Administrator Authorization Page   ***\n\n");
	printf("|Error Login Counter :  %d  times. You can try %d times\n\n", counter, 6 - counter);
	/*System Administrtor Auth.*/
	printf("Please type in the System Administrator's Password : ");
	scanf("%s", &pw);
	printf("\n%d", auth(pw, 0));
};

void ShopAuth() {

};

void CustomerAuth() {

};

/*Customer Panel & System / Shop Admin. Menu*/
void SysAdm() {

};

void ShopAdm() {

};

void CustomerPanel() {

};


/*Features (Original)*/
void add() {

};

void display() {

};

void search() {

};

void modify() {

};

void delete() {

};

/*Features (Extra)*/
void csa() {

};

void csa2() {

};

void emm() {
    char choice;
    system("title NOTE >> Maintain Mode (EMM) Running");
    ini();
    printf("Are you sure to open the Maintain Mode (Y / N) : ");
    scanf("%c", &choice);
    switch(choice) {
        case 'Y':
        case 'y':
            break;
        case 'n':
        case 'N':
            break;
    }

};

void etm() {
    system("title DANGER >> TEST Mode (ETM) Running");
    char ch4;
    ini();
    printf("'\n\t***  You have enter the Test Mode (ETM)  ***\n\n");
    printf("*Info: Beware to use Testmod, Error may occur if EMT is insert !\n");
    printf("***   Shop Administration Panel   ***\n\n");
    printf("Please Enter the options < 1 - 9 > : ");
    scanf("%c", &ch4);
};

/*Functions*/
void WriteInFile() {
	
};

void replace(char buf[]) {
	int i, length;
	length = strlen(buf);
	for(i = 0; i < length + 1; i++) {
		if(buf[i] == '@' || buf[i] == '_' || buf[i] == '-') {
			buf[i] = ' ';
		}
	}
}

int auth(char pw[], int cls) {
	/*"pwd.dat" Password Exports*/
	char file_name[256] = "pwd.dat", tmp[20];
	int local_counter = 0, result = 0;
	FILE *extract_pwd_1 = fopen(file_name, "r");
	
	while(fgets(tmp, sizeof(tmp), extract_pwd_1) != NULL) {
		local_counter++;
		if(local_counter == cls) {
			int i = 0;
			for(i = 0; i < sizeof(tmp); i++) {
				if(tmp[i] == '\n') {
					tmp[i] = ' ';
				} else {
					continue;
				}
			}
		}
	}
	fclose(extract_pwd_1);
	
	result = strcmp(pw, tmp);
	
	printf("%s", tmp);
	
	return result;
}

void startup() {
	char err = 0;
	/*Check "pwd.dat"*/
	FILE *start_pwd;
	start_pwd = fopen("pwd.dat", "r+");
	if(start_pwd == NULL) {
		start_pwd = fopen("pwd.dat", "a");
		if(start_pwd == NULL) {
			return failure();
		}
		fprintf(start_pwd, "admin\nadmin");
		fclose(start_pwd);
	} 
	printf("\n System: (pwd.dat) Configuration Successful Loaded\n");
	/*Check "stock.txt"*/
	FILE *start_stock;
	start_stock = fopen("stock.txt", "r+");
	if(start_stock == NULL) {
		start_stock = fopen("stock.txt", "a");
		if(start_stock == NULL) {
			return failure();
		}
		fclose(start_stock);
	}
	/*Check "maintain.dat"*/
	FILE *start_config_mat;
	start_config_mat = fopen("maintain.dat", "r+");
	if(start_config_mat == NULL) {
		start_config_mat = fopen("maintain.dat", "a");
		if(start_config_mat == NULL) {
			return failure();
		}
		fprintf(start_config_mat, "0");
		fclose(start_config_mat);
	}
	printf("\n System: (maintain.dat) Configuration Successful Loaded\n");
	printf("\n System: (STU) Configuration Successful Loaded\n");
};

void getConfig() {
	/*"maintain.dat" Exports*/
	char file_name[256] = "maintain.dat", mt_confg[2];
	FILE *extract_mcg = fopen(file_name, "r");
	if(extract_mcg != NULL) {
		while (fgets(mt_confg, sizeof(mt_confg), extract_mcg) != NULL) {
			printf("\n System: (MCG) Successful Loaded\n");
		}
		maintain = atoi(mt_confg);
	} 
	fclose(extract_mcg);
	system("title HKUSPACE IMRS @ Initialising");
	printf("\n The System are keep laoding, please wait ....... \n");
	sleep(6);
	system("title HKUSPACE IMRS @ Sucessfully loaded");
	printf("\n Welcome to HKUSPACE Inventory Management and Record System (IMRS) \n");
	sleep(4);
	system("cls");
		
};

void failure() {
	system("CLS");
	ini();
	printf("\t\n***   System Initial Failure   ***\n");
	printf("Reason : Disc full or no permission\n\n");
	printf("To prevent further System Error, exit mode in 5 seconds.\n");
	system("timeout 5");
	exit(0);
}


