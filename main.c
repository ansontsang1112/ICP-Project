#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <Windows.h> //Windows System Library
#include <Lmcons.h> //Username Library

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
void startup();
void write();
void failure();

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
int counter = 0, ret_counter = 0, Maintain = 0, role = 0;
char appear;
char Normal[] = "Please enter the password", LIF[] = "Authorization Failure, Please try again.";

void ini() {
    printf("\t\t\t***\tWelcome to HKUSPACE Inventory Management and Record System\t***\n\n");
    printf("\t\t\t\t\t\t***    1819S1    ***\n\n");
    printf("\t\t\t*** This system is developed by CCIT4020 Class No. ?L-?? Group No,?? ***\n\n\n");
}

void menu() {
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
	startup();
    menu();
}

//Auth. System
void SysAuth() {
	/*"pwd.dat" Password Exports*/
	char file_name[256] = "pwd.dat", correct_pw[512], buf[20];
	int local_counter = 0;
	FILE *extract_pwd_1 = fopen(file_name, "r");
	if(extract_pwd_1 != NULL) {
		while (fgets(correct_pw, sizeof(correct_pw), extract_pwd_1) != NULL) {
			strcpy(buf, correct_pw); //correct_pw
		}
	} 
	fclose(extract_pwd_1);	
	
	role = 0;
	system("CLS");
	ini();
	char pw[20] = {0};
	if(counter == 5) {
		printf("You have type in the max. no of wrong password, the program will auto exit in 5 seconds.\n\n");
        system("timeout 5");
        exit(0);	
	}
	printf("%s", correct_pw);
	printf(">> Status : %s\n\n", (counter == 0) ? Normal : LIF);
	/*UI Section*/
	printf("***   System Administrator Authorization Page   ***\n\n");
	printf("|Error Login Counter :  %d  times. You can try %d times\n\n", counter, 6 - counter);
	/*System Administrtor Auth.*/
	printf("Please type in the System Administrator's Password : ");
	scanf("%s", pw);
	
	
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

};

void etm() {

};

/*Functions*/
void write() {
	
};

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


