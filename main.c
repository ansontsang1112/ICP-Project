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


/*Function Proto Type*/
/*Menu GUI(s)*/
void ini();
void au_ini();
void menu();
void SysPanel();
void SAPanel();
void choices();
void CustomerPanel();

/*User Login & Registation Functions*/
void reg();

/*Functions*/
void addition();
void display();
void search();
void modify();
void del();

/*Extra*/
void cpwd();
void cperm();
void emm();
void sd();
void buyanitem();

/*Functions*/
void DisplayFile();
void deleteARecord();
int auth(char [], char []);
void startup();
void rw();
void WriteInFile();
void failure();
void getConfig();
int DataCheck();
void pret();

/*Structure Part*/
struct Data {
    int rid;
    char ItemName[50];
    int id;
    float price;
    char category[50];
    int quantity;
    float weight;
    char recip[50];
    char FinalDest[50];
    char dev_stat[50];
}Data;

/*Globes Var*/
int counter = 0, role = 0, rev_value = 0, maintain, tmd, permission, money;
char appear;
char Normal[] = "Please enter the password", LIF[] = "Authorization Failure, Please try again.";
char username[50], password[50];

void ini() {
    printf(" *** Welcome to HKUSPACE Inventory Management and Record System ***\n\n");
    printf("\t***    1819S1    ***\n\n");
    printf("*** This system is developed by CCIT4020 Class No. ?L-?? Group No,?? ***\n\n");
}

void au_ini() {
    char pvtopd[50];
    printf("Welcome, < %s >, You have already login to HKUSPACE IRMS, Profile below [] ", username);
    printf("\n\nLogin Name : %s\n", username);
    printf("Password (IVALUE) : %d\n", (int)password);
    printf("Money (Coins) : %d\n\n", money);
}

void menu() {
    if(rev_value == 1000){
        goto SKIPUP;
    }
	startup();
	getConfig();
	SKIPUP:
	system("title HKUSPACE IMRS @ LOG-IN Menu");
    char ch1 = 'C';
    /*Check IS Maintain Mode enabled ?*/
    FILE *maintain = fopen("system\\maintain.dat", "r");
    char Mcoden = fgetc(maintain);
    fclose(maintain);
    if(atoi(&Mcoden) == 1) {
    	ini();
    	system("title HKUSPACE IMRS @ Maintain Menu");
    	printf("Sorry, Maintain Mode is enabled, Only System Administrator are able to login to IMRS.\n\n");
    	printf("If you think this contain any Error, please contact the System Administrator. Sorry for inconvence.\n\n");
    	printf("You will be redirect to MMD Identification Authorization Cneter.\n");
    	Sleep(5000);
    	return emm();
	}
    MENU:
    system("cls");
    ini();
    char choice;
	if(counter == 5) {
		printf("You have type in the max. no. of wrong password, the program will auto exit in 5 seconds.\n\n");
		Sleep(5000);
		exit(0);
	}
	printf(">> Status : %s\n\n", (counter == 0) ? Normal : LIF);
	/*UI Section*/
	printf("***    User Login Panel || Authorization System     ***\n\n");
	printf(">> Error LOG-IN Counter : %d times. You can try %d times\n\n", counter, 6 - counter);
	/*Auth. Center*/
	fflush(stdin);
	printf("Please Enter your Username & Password. If you do not have an account, please enter 'REGISTER' to get an account.");
	printf("\n\nUsername : ");
	scanf("%s", username);
	if(username == "REGISTER") {
		return reg();
	}
	printf("\nPassword : ");
	scanf("%s", password);
	if(auth(username, password) != 0) {
		printf("\nAuthorization Failure, Please wait for 3 sec. to return LOG-IN Platform.");
		counter++;
		Sleep(3000);
		goto MENU;
	}
	printf("\nAuthorization Success, Getting the Permissions from PSCF.\n");
	Sleep(1000);

    /*Get the Money*/
	char path_m[] = "userdata\\", file_m[] = "\\money.dat";
    strcat(path_m, username);
	strcat(path_m, file_m);
	FILE *getMoney = fopen(path_m, "r+");
	money = getw(getMoney);
	fclose(getMoney);

	/*Get the permission*/
	char path[] = "userdata\\", file[] = "\\permission.dat";
	strcat(path, username);
	strcat(path, file);
	FILE *getPerm = fopen(path, "r+");
	char Pcoden = fgetc(getPerm);
	permission = atoi(&Pcoden);
	fclose(getPerm);
	if(permission == 0) {
	    printf("\nYou are belongs to >> SYS. Admin. Redirecting to Relative GUI Panel ...\n");
	    Sleep(2000);
	    return SysPanel();
	} if(permission == 1) {
        printf("\nYou are belongs to >> SHOP Admin. Redirecting to Relative GUI Panel ...\n");
        Sleep(2000);
        return SAPanel();
	} if(permission == 2) {
	    printf("\nYou are belong to >> Customer. Redirecting to Relative GUI Panel ...");
	    Sleep(2000);
	    return CustomerPanel();
	} else {
	    printf("\nAn error occur. Auto-fixing ....\n");
	    Sleep(2000);
	    printf("\nFix FAILURE ... Redirecting\n");
	    Sleep(2000);
        return failure();
	}
	fflush(stdin);
};

/*Main Function*/
int main(int argc, char **argv){
	menu();
}

void reg() {

};

/*Customer Panel & System / Shop Admin. Menu*/
void SysPanel() {
	system("title HKUSPACE IMRS @ SYS. Admin. Panel");
	system("cls");
    int choice;
    ini();
    au_ini();
    counter = 0;
    printf(" 0. Logout\n");
    printf(" 1. Add New Item<s>\n");
    printf(" 2. Display Item Record<s>\n");
    printf(" 3. Search Item Information<s>\n");
    printf(" 4. Modify Item Information<s>\n");
    printf(" 5. Delete Item Record<s>\n");
    printf(" 6. Change Users Password\n");
    printf(" 7. Change Permission of Specific Users\n");
    printf(" 8. Enable / Disable Maintain Mode\n");
    printf(" 9. Enable Self Destruction Mode\n");
    printf("\n What is your option <1-10> ? || ");
    scanf("%d", &choice);
    choices(choice);
};

void SAPanel() {
	system("title HKUSPACE IMRS @ SHOP Admin. Panel");
	system("cls");
    int choice;
    ini();
    au_ini();
    counter = 0;
    printf(" 0. Logout\n");
    printf(" 1. Add New Item<s>\n");
    printf(" 2. Display Item Record<s>\n");
    printf(" 3. Search Item Information<s>\n");
    printf(" 4. Modify Item Information<s>\n");
    printf(" 5. Delete Item Record<s>\n");
    printf(" 6. Change Users Password\n");
    printf("\n What is your option <0-6> ? || ");
    fflush(stdin);
    scanf("%d", &choice);
    if(choice > 6) {
    	printf("\nYou are only allow to enter 0 - 6, %d are not allowed !", choice);
    	Sleep(2000);
    	return SAPanel();
	}
    choices(choice);
};

void CustomerPanel() {
	system("title HKUSPACE IMRS @ Customer Panel");
	system("cls");
	int choice;
    ini();
    au_ini();
    printf(" 0. Logout\n");
    printf(" 1. Add New Item<s>\n");
    printf(" 2. Display Item Record<s>\n");
    printf(" 3. Search Item Information<s>\n");
    printf(" 4. Modify Item Information<s>\n");
    printf(" 5. Delete Item Record<s>\n");
    printf(" 6. Change Users Password\n");
    printf("10. Buy / Transfer Item form market\n");
    printf("\n What is your option <0-6> ? || ");

};

void choices(int type) {
    switch (type) {
    	case 0:
        	printf("\nYou have selected Logout, Exiting Session ...\n");
        	Sleep(3000);
        	printf("\nThankyou for using HKUSPACE IMRS ^v^");
        	Sleep(2000);
        	rev_value = 1000;
        	menu();
        case 1:
            addition();
            break;
        case 2:
            display();
            break;
        case 3:
            search();
            break;
        case 4:
            modify();
            break;
        case 5:
            counter == 0;
            del();
            break;
        case 6:
        	counter == 0;
            cpwd();
            break;
        case 7:
        	counter == 0;
            cperm();
            break;
        case 8:
            counter == 0;
            emm();
            break;
        case 9:
            counter == 0;
            sd();
            break;
        case 10:
        	buyanitem();
        default:
            printf("No this option < %d >, < 1 - 10> Only.\n", type);
            Sleep(3000);
            system("cls");
            /*0 = SYS / 1 = SHOP / 2 = Customer*/
            if(permission == 0) {
                return SysPanel();
			} if(permission == 1) {
                return SAPanel();
            } if(permission == 2) {
                return CustomerPanel();
            }
	}
};


/*Features (Original)*/
void addition() {
    system("cls");
    ini();
    printf("\n>> You have enter the Additional Mode\n\n");
    NEW_Record:
    fflush(stdin);
    printf("Record ID, Item ID will be Auto Generated.\n");
    printf("\nFormat: Item Name | Price per quantity | Category | Quantity | Weight | Final Destination\n");
    printf("\nPlease Enter The Record Data : ");
    scanf("%s%f%s%d%f%s", Data.ItemName, &Data.price, Data.category, &Data.quantity, &Data.weight, Data.FinalDest);
    char storage[] = "Storage";
    strcat(Data.dev_stat, storage);
    strcat(Data.recip, storage);
    WriteInFile(Data);
    fflush(stdin);
    char choice;
    printf("\nWould you like to enter another data? ( Y / N ) : ");
    scanf("%c", &choice);
    if(choice == 'y' || choice == 'Y') {
        goto NEW_Record;
    } else {
        printf("\nYour Record are writing to file, please wait ...");
        Sleep(3000);
        system("cls");
        return pret();
    }

};

void display() {
    char option;
    system("cls");
    ini();
    au_ini();
    fflush(stdin);
    printf("Are you sure to display all items in our Stock System ? ( Y / N ) : ");
    scanf("%c", &option);
    fflush(stdin);
    switch(option) {
    case 'N':
    case 'n':
        printf("\nYou have selected 'N', you will be return back to GUI Panel ...");
        Sleep(2000);
        pret();
    case 'Y':
    case 'y':
        printf("\nYou have selected 'Y', Loading Stock System ... Please wait ...");
        Sleep(2000);
        rev_value = 0; //0 = Return Back Display Sec. || 1 = Return back SRC
        DisplayFile();
    }
};

void search() {
    system("cls");
    char pcid, itemID[20], buff[10240];
    int maxLoop = 12, dLine = 0, line[maxLoop], loop = 0, i = 0;
    ini();
    au_ini();
    fflush(stdin);
    printf("You are going to search an item ...\n");
    printf("\nDo you know the Product Code (Item ID) ? ( Y / N ): ");
    scanf("%c", &pcid);
    fflush(stdin);
    if(pcid == 'N' || pcid == 'n') {
        printf("\nRecords will be display ... Please wait ...");
        rev_value = 1;
        Sleep(3000);
        DisplayFile();
    }
    EnterID:
    printf("\nPlease enter the Item ID : ");
    scanf("%s", itemID);
    fflush(stdin);
    if(atoi(itemID) < 1000) {
        printf("\nUnexpected error : Wrong Input Data\n");
        Sleep(2000);
        goto EnterID;
    }
    int initLine = atoi(itemID) - 1000;
    while(loop < maxLoop) {
        line[loop] = loop + initLine * 11 + initLine;
        loop++;
    }
    FILE *fileIO = fopen("stock.txt", "r");
    while(fgets(buff, sizeof(buff), fileIO) != NULL) {
        for(i = 0; i < maxLoop; i++) {
            if(i == maxLoop) {
                if(dLine == line[maxLoop]) {
                    printf("%s\n", buff);
                }
            } else {
                if(dLine == line[i]) {
                    printf("%s", buff);
                }
            }
        }
        dLine++;
    }
    printf("\nThat is the result on ID = %s, Go back GUI Panel by typing 'ANY KEY'\n", itemID);
    fclose(fileIO);
    system("pause");
    pret();
};

void modify() {

};

void del() {
    char passAuth[50], choice;
    system("cls");
    ini();
    au_ini();
    if(counter > 5) {
        printf("You have attempt the maximun password checking ... auto logout");
        Sleep(2000);
        exit(0);
    }
    printf("You have SELECTED Delete an Item !! To prevent unknown access, authentication required ...\n");
    printf("\nYou must use the password of user = < %s > !!\n", username);
    printf("\nYou have %d chance left (Password Retry)!!\n", 5 - counter);
    printf("\nEnter the PASSWD of user = < %s > : ", username);
    scanf("%s", passAuth);
    fflush(stdin);
    if(auth(username, passAuth) != 0) {
        printf("Authentication Failure !! Please try again ....\n");
        counter++;
        Sleep(2000);
        del();
    }
    printf("\nDo you know the Item ID of the Item that you wise to Delete ? ( Y / N ) : ");
    scanf("%c", &choice);
    if(choice != 'Y' && choice != 'y') {
        printf("\nYou are redirecting to Stock Display System, please wait ...\n");
        Sleep(3000);
        rev_value = 3;
        DisplayFile();
    }
    deleteARecord();
};

/*Features (Extra)*/
void cpwd() {
	system("cls");
	ini();
	char PW[10], NPWD[10], CNP[10];
    if (counter == 5) {
        printf("\nError attempts lager than 5. To prevent Unauthorised Access, Exit in 5 second!\n\n");
        Sleep(5000);
        system("CLS");
        exit(0);
    }
    printf("\nYou have selected the option 6 : Change the Password.\n\n");
    printf("*** Identification Authorization System ***\n\n");
    printf(">> Status : %s\n", (counter == 0) ? Normal : LIF);
    printf("\n>> Error Login Counter :  %d  times. You can try %d times\n\n", counter, 6 - counter);
    printf("To prevent unknown edition of Password, PAUS established.\n\n");
    printf("Please Enter the Old User Password: ");
    fflush(stdin);
    scanf("%s", PW);
    if(auth(username, PW) == 0) {
    	printf("\n Authorization Success: \n\n");
    	PwTypo:
    	printf("Please Enter the New Password: ");
    	fflush(stdin);
    	scanf("%s", NPWD);
    	printf("\nPlease Enter it again: ");
    	scanf("%s", CNP);
    	if(strcmp(NPWD, CNP) != 0) {
            system("cls");
    		ini();
    		au_ini();
    		printf("You are required to Enter Again.\n\n");
    		printf("Please wait in few second\n");
			Sleep(2000);
			system("cls");
			fflush(stdin);
			goto PwTypo;
		}
	} else {
		counter += 1;
		return cpwd();
	}

	char path[] = "userdata\\", pwdfile[] = "\\password.dat";
	strcat(path, username);
	strcat(path, pwdfile);
	FILE *PWD = fopen(path, "w");
	fprintf(PWD, "%s", NPWD);
	fclose(PWD);
	printf("\nPassword Successfully Changed, Return in 5 seconds");
	Sleep(5000);
	pret();
};

void cperm() {
    char PERM[10], PW[20], IUN[20];
    system("cls");
    ini();
    if(counter >= 5) {
    	printf("Max. Error Attemp ... Exit in few sec.");
    	Sleep(3000);
    	exit(0);
	}
    printf("***   Authorization Session   ***\n\n");
    printf("** Identification Required **\n");
	printf("\n>> Status : %s\n", (counter == 0) ? Normal : LIF);
    printf("\n>> Error Counter: You still have %d chances for Error tries.\n", 6 - counter);
    printf("\nTo prevent unknown edition of permissions, PAUS established.\n\n");
    printf("\nPlease Enter the authorised password : ");
    scanf("%s", PW);
    if(auth(username, PW) != 0) {
    	printf("\nIdentification FAILURE !! Please wait for few Seconds ...");
    	Sleep(3000);
    	counter++;
    	return cperm();
    }
    printf("\nAuthorization Success ... Wait ...\n");
	Sleep(3000);
    STNP:
    system("cls");
    ini();
    printf("\nPlease enter the username that you want to change the permission : ");
    scanf("%s", IUN);
    char path[] = "userdata\\", permfile[] = "\\permission.dat", UN[10];
    strcpy(UN, IUN);
	strcat(path, IUN);
	strcat(path, permfile);
    FILE *search = fopen(path, "r");
    if(search == NULL) {
      	printf("\nNo this User : %s", UN);
       	Sleep(5000);
       	goto STNP;
	}
	fclose(search);
    printf("\nPlease enter the New permission for %s : ", UN);
    scanf("%s", PERM);

    /*Write in "PERM"*/
    printf("");
    FILE *SPRM = fopen(path, "w");
    fputs(PERM, SPRM);
    fclose(SPRM);
    printf("\n\nPermission Successfully Changed ... Please wait for 3 Second");
    Sleep(3000);
    pret();
}

void emm() {
	system("cls");
    system("title Note @ Maintain Mode (EMM) Selecting");
    char choice = 'N', mc;
    int index = 1, rev_index = 0;
    FILE *extract_mc = fopen("system\\maintain.dat", "r");
    mc = fgetc(extract_mc);
    ini();
    if(atoi(&mc) == 0) {
        printf("Are you sure to open the Maintain Mode (Y / N) : ");
        scanf("%c", &choice);
        switch(choice) {
            case 'Y':
            case 'y':
                system("title Note @ Maintain Mode (EMM) Enabling");
                FILE *maintain = fopen("system\\maintain.dat", "w");
                fprintf(maintain, "%d", index);
                fclose(maintain);
                printf("\nMaintain Mode is Successfully enabled. To prevent error in IRMS, the program will auto restart in 5 seconds.");
                Sleep(5000);
                system("cls");
                return menu();
                break;
            case 'n':
            case 'N':
                printf("\nYou have selected < N > in EMM. You will be return to Admin. Panel in few seconds.");
                Sleep(3000);
                return SysPanel();
                break;
            default:
                return emm();
        }
    } else {
    	MDS:
    	printf("");
    	char auth_un[10], auth_pw[10];
    	system("cls");
    	ini();
    	printf("To Ensure you have permission to closed M-Mode. Please user authorised account to unlock M-Mode.\n");
    	printf(">> ELC : %d || Reminder : %d", counter, 6 - counter);
    	printf("\nPlease enter the account and password!\n\n");
    	printf("// Username : ");
    	scanf("%s", auth_un);
    	printf("// Password : ");
    	scanf("%s", auth_pw);
    	Sleep(1000);
    	printf("\nAuthorising ...\n" );
    	Sleep(2000);
    	if(auth(auth_un, auth_pw) != 0) {
    		printf("\nAuthentication FAILURE, Please enter it again ...\n");
    		counter++;
    		Sleep(2000);
    		goto MDS;
		}
		printf("\nPermission Check is on-going ...\n");
		Sleep(2000);
		/*Check if the permission is accepted (Perm == 0)*/
		char path[] = "userdata\\", file[] = "\\permission.dat";
		strcat(path, auth_un);
		strcat(path, file);
		FILE *getPerm = fopen(path, "r");
		char Pcoden = fgetc(getPerm);
		fclose(getPerm);
		if(atoi(&Pcoden) != 0) {
			printf("\nYou do not have enough permission to closed the M-Mode ...\n");
			printf("\nProgram will be shutdown automatically ...\n");
			Sleep(5000);
			exit(0);
		}
		printf("\nAuthentication Success ... Redirecting ...\n");
    	Sleep(3000);

    	/*Start to close MMODE*/
    	off:
    	fflush(stdin);
        printf("\nAre you sure to closed Maintain Mode (Y/N) : ");
        scanf("%c", &choice);
        switch(choice) {
            case 'Y':
            case 'y':
                system("title Note @ Maintain Mode (EMM) disabling");
                FILE *maintain = fopen("system\\maintain.dat", "w");
                fprintf(maintain, "%d", rev_index);
                fclose(maintain);
                printf("\nMaintain Mode is Successfully disabled. To prevent error in IRMS, the program will auto restart in 5 seconds.");
                Sleep(5000);
                system("cls");
                return menu();
            case 'n':
            case 'N':
                printf("\nYou have selected < N > in EMM. You will be exit the IRMS in few seconds.");
                Sleep(3000);
                exit(0);
            default:
                goto off;
        }
    }
};

void sd() {
	char tmp_usr[25], tmp_pwd[25];
	system("title HKUSPACE IMRS Danger @ Self Destruction Mode");
	system("cls");
	ini();
	if(counter >= 3) {
		printf("\nAuthentication Failure > 3, Redirecting ....\n");
		Sleep(3000);
		pret();
	}
	printf("DANGEROUS : You have enter SELF DESTRUCTION Mode authentication center.\n");
	printf("\nAuthentication Required ! | REMC : %d\n", 2 - counter);
	printf(">> Password : ");
	scanf("%s", tmp_pwd);
	printf("\nAuthorising ...\n" );
	Sleep(2000);
	if(auth(username, tmp_pwd) != 0) {
		printf("\nAuthentication Failure, Please enter again\n");
		counter++;
		Sleep(1000);
		return sd();
	}
	printf("\nAuthentication Success, Please Wait ...\n");
	VC:
	printf("");
	int arg = (999999 - 111111 + 1) + 111111;
	int vc = rand() % arg, vci = 0;
	printf("\nPlease enter the Verification code -> < %d > : ", vc);
	scanf("%d", &vci);
	if(vci != vc) {
		printf("\nVerification Failure ...\n");
		Sleep(2000);
		goto VC;
	}
	char choice;
	fflush(stdin);
	printf("\nAre you sure to active SELF DESTRUCTION Mode ? ( Y / N ) : ");
	scanf("%c", &choice);
	switch(choice) {
		case 'N':
		case 'n':
			printf("\nSELF DESTRUCTION Mode >> Off, Redirecting");
			Sleep(3000);
			return SysPanel();
		case 'y':
		case 'Y':
			printf("\nSELF DESTRUCTION Mode >> On ... Please Wait.");
			Sleep(3000);
			printf("\nAll Data will be erased ...\n");
			FILE *fileIO = fopen("stock.txt", "w");
			fprintf("stock.txt", "%s", "SD MODE enabled. NULL Data ...");
			fileIO = fopen("system\\id.dat",  "w");
			fprintf("system\\id.dat", "%s", "SD MODE enabled. NULL Value ...");
			system("rmdir userdata /s");
			printf("\nYour computer will shutdown in 3 seconds.");
			fclose(fileIO);
			Sleep(2000);
			system("shutdown -r -t 0");
	}
};

void buyanitem() {
    /*Var*/
    char buff[10240], *data_cmp, item_id[20], choice;
    search:
    printf("");
    int return_vaule = 0;
    system("cls");
    ini();
    au_ini();
    printf("You have enter Shopping Center. You can only buy the ITEM that store in Storage.\n");
    printf("\nPlease enter the Item ID of the Item : ");
    scanf("%s", item_id);
    if(atoi(item_id) < 1000) {
        goto ERR1;
    }
    fflush(stdin);
    /*Check if the item exist*/
    FILE *searchIO = fopen("stock.txt", "r+");
    while(fscanf(searchIO, "%s", buff) != EOF) {
        if(strcmp(item_id, buff) == 0) {
            fflush(stdout);
            return_vaule = 1;
        }
    }
    fclose(searchIO);
    ERR1:
    if(return_vaule != 1) {
        char choice;
        int h = 0, i = 0, j = 0, line[3];
        line[0] = 2, line[1] = 3, line[2] = 4;
        system("cls");
        ini();
        au_ini();
        printf("We cannot find your inserted Item ID, Would you like to retry or display all the Items ? ");
        printf("\n\nPlease enter your choice (r = retry / d = display) : ");
        scanf("%c", &choice);
        printf("\n");
        fflush(stdin);
        if(choice == 'r' || choice == 'R') {
            goto search;
        } else if(choice == 'd' || choice == 'D'){
            FILE *displayIO = fopen("stock.txt", "r");
            while(fgets(buff, sizeof(buff), displayIO) != NULL) {
                if(h == line[0]) {
                    /* Display Item Name*/
                    printf("%s", buff);
                    line[0] += 11;
                } if(i== line[1]) {
                    /* Display Item ID*/
                    printf("%s", buff);
                    line[1] += 11;
                } if(j == line[2]) {
                    printf("%s\n", buff);
                    line[2] += 11;
                } else {
                    h++;
                    i++;
                    j++;
                }
            }
            fclose(displayIO);
            printf("If you have remember and choose what you wanna buy, please type 'ANYKEY' to re-type the ID.\n");
            system("pause");
            goto search;
        }
    }
    printf("\nItem ID < %s > has found ... Loading the info ...\n", item_id);
    fflush(stdout);
    Sleep(2000);
    FILE *search2 = fopen("stock.txt", "r+");
    int init_value = atoi(item_id) - 1000;
    int init_line, k = 0;
    if(init_value == 0) {
        init_line = 0;
    } else {
        init_line = init_value + init_value * 11 - 1;
    }
    int term_line = init_line + 11;
    while(fgets(buff, sizeof(buff), search2) != NULL) {
        if(k == init_line) {
            printf("%s", buff);
            init_line++;
            if(init_line >= term_line) {
                break;
            }
        }
        k++;
    }
    fclose(search2);
    fflush(stdin);
    printf("\nWould You like to buy this Item ? <ID = %s> ( Y / N ): ", item_id);
    scanf("%c", &choice);
    fflush(stdin);
    if(choice != 'Y' && choice != 'y') {
        printf("\nWe hope you will enjoy your shopping Journey !! ^v^ !!");
        Sleep(2000);
        pret();
    }
    /*Check if money are equal. or more then the shop required*/
    FILE *moneyAPI = fopen("stock.txt", "r");
    /* Get the money inside */
    int init_pd_line = atoi(item_id) - 1000, init_price_line, priceCmp = 0, x = 0;
    if(init_pd_line == 0) {
    	init_price_line = 4;
	} else {
		init_price_line = init_pd_line * 11 + 4 + init_pd_line;
	}
	while(fgets(buff, sizeof(buff), moneyAPI) != NULL) {
		if(x == init_price_line) {
            prw(buff);
			priceCmp = atoi(buff);
		}
		x++;
	}
	fclose(moneyAPI);
	if(priceCmp != money && priceCmp > money) {
        char choice;
	    system("cls");
	    ini();
	    au_ini();
        printf("\nFor Item ID = %d, You do not have enough money to buy / transfer it...\n", atoi(item_id));
        printf("\nYou do not have enough money to buy this item.\n");
        printf("\nFind another item ? (y / n) : ");
        scanf("%c", &choice);
        fflush(stdin);
        if(choice == 'y' || choice == 'Y') {
            buyanitem();
            return;
        } else {
            pret();
        }
	}
	/* Replace the File POS */
    FILE *org, *tmp;
    int line, linectr = 0;
    int value = atoi(item_id) - 1000;
    char str[1024];
    char tmpFile[] = "temp.txt";
    char writtenLine[] = "Recipient: ";
    org = fopen("stock.txt", "r");
    tmp = fopen(tmpFile, "w");
	strcat(writtenLine, username);
    line = value + value * 11 + 8; //Find the REF. Line//
    line++; //n + 1//
    if (!tmp) {
        fclose(org);
        failure();
    }
    while (!feof(org)) {
        strcpy(str, "\0");
        fgets(str, 1024, org);
        if (!feof(org)) {
            linectr++;
            if (linectr != line) {
                fprintf(tmp, "%s", str);
            } else {
                fprintf(tmp, "%s\n", writtenLine);
            }
        }
    }
    fclose(org);
    fclose(tmp);
    remove("stock.txt");
    rename("temp.txt", "stock.txt");
    /* Deduct Money from Money System */
    int orgMoney;
    char path[] = "userdata\\", file[] = "\\money.dat";
    strcat(path, username);
    strcat(path, file);
    money -= priceCmp;
    FILE *moneyIO = fopen(path, "w");
    orgMoney = money;
    putw(orgMoney, moneyIO);
	fclose(moneyIO);
	printf("\nPurchases Successful ... Redirecting ...\n");
	Sleep(4000);
	pret();
}

/*Functions*/
void DisplayFile() {
    char message[10240], option;
	int v1 = 0, v2 = 0, v3 = 0, v4 = 0, v5 = 0, v6 = 0, v7 = 0, v8 = 0, v9 = 0, v0 = 0, line[10];
        line[0] = 1, line[1] = 2, line[2] = 3, line[3] = 4, line[4] = 5, line[5] = 6, line[6] = 7, line[7] = 8; line[8] = 9, line[9] = 10, line[10] = 11;
	FILE *display = fopen("stock.txt", "r");
	printf("\nThe product record has display below: \n", "stock.txt");
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
        } else {
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
	CONFIRM:
	printf("\nIt's that contain any problem ? If not, please type < k > to go back : ");
	scanf("%c", &option);
	fflush(stdin);
	if(option != 'k' && option != 'K') {
        printf("\nOption < %c > rejected ....\n", option);
        Sleep(2000);
        goto CONFIRM;
	}
	printf("\nConfirmation Accepted ! Please wait ...");
	Sleep(3000);
	if(rev_value == 0) {
        pret();
	} if(rev_value == 1) {
	    search();
	} if(rev_value == 3) {
	    del();
	}
	if (rev_value != 0 || rev_value != 1 || rev_value != 3) {
	    printf("\nR_Value get error ... System Failure ...");
	    Sleep(2000);
	    failure();
	}
}

int DataCheck() {
    char TPI[20];
    int return_value;
    FILE *DCT = fopen("stock.txt", "r");
    if(fgets(TPI, sizeof(TPI), DCT) != NULL) {
        return_value = 1;
    }
    return return_value;
};

void WriteInFile(struct Data dataIO) {
    int max = 1000, min = 1, value = 0;

    /*Replace '_' / '@' / '-' to ' '*/
    rw(Data.ItemName);
    rw(Data.recip);
    rw(Data.FinalDest);
    rw(Data.dev_stat);

    /*ID Get F(x)*/
    FILE *IDRE = fopen("system\\id.dat", "r");
    value = getw(IDRE);

	FILE *WriteIn = fopen("stock.txt", (((DataCheck() == 0) ? "w+" : "a+")));

	float finalPrice = Data.price * Data.quantity;
    /* ---- WriteIn Started ----*/
    fprintf(WriteIn, "---Start of Record (%d)---\n", value);
    fprintf(WriteIn, "Record ID: %d\n", value);
    fprintf(WriteIn, "Item Name: %s\n", Data.ItemName);
    fprintf(WriteIn, "Item ID: %d\n", value);
    fprintf(WriteIn, "Prices: %f\n", finalPrice);
    fprintf(WriteIn, "Catagory: %s\n", Data.category);
    fprintf(WriteIn, "Quantity: %d\n", Data.quantity);
    fprintf(WriteIn, "Weight: %.3f Kg\n", Data.weight);
    fprintf(WriteIn, "Recipient: %s\n", Data.recip);
    fprintf(WriteIn, "Final Destination: %s\n", Data.FinalDest);
    fprintf(WriteIn, "Delivery Status: %s\n", Data.dev_stat);
    fprintf(WriteIn, "--- End of Record (%d)---\n", value);
    fclose(WriteIn);

    char PATH[] = "system\\id.dat";
    FILE *ID = fopen(PATH, "r");
    value = getw(ID);
    ID = fopen(PATH, "w");
    value++;
    putw(value, ID);
	fclose(ID);
};

void deleteARecord() {
	int deleteLine, linectr = 0, showlinctr = 0, i, itemID;
	char str[10240], showstr[10240];
	char choice;

	FILE *fileIO = fopen("stock.txt" ,"r");
	FILE *DataIO = fopen("temp.dat", "w");
	if(DataIO == NULL){
        failure();
	}
	/* Element Insert */
	INPUT:
	printf("Please ether the ID for delete: ");
	fflush(stdin);
	scanf("%d", &itemID);

	deleteLine = ((itemID - 1000) * 12) + 1;
	deleteLine++;

	printf("\nIs that < ID = %d > that you need to delete ? ( Y / N ) : ", itemID);
	fflush(stdin);
	scanf("%c", &choice);

	if(choice != 'Y' && choice != 'y') {
        goto INPUT;
	}

	char space[] = "----NULL----";

	while(!feof(fileIO)){
		strcpy(str, "\0");
		fgets(str, 10240, fileIO);
		if(!feof(fileIO)){
			linectr++;
			if(linectr != deleteLine && linectr != deleteLine + 1 && linectr != deleteLine + 2 && linectr != deleteLine + 3 && linectr != deleteLine + 4 && linectr != deleteLine + 5 && linectr != deleteLine + 6 && linectr != deleteLine + 7 && linectr != deleteLine + 8 && linectr != deleteLine + 9){
				fprintf(DataIO, "%s", str);
			}
			else{
					fprintf(DataIO, "%s\n", space);
			}
		}
	}

	fclose(DataIO);
	fclose(fileIO);
	remove("stock.txt");
	rename("temp.dat", "stock.txt");
	printf("\nFile Removing ...\n");
	Sleep(2000);
	printf("\nThe Item Record = < %d > has been removed ... Redirecting ...", itemID);
	Sleep(2000);
	pret();
}

void rw(char buf[]) {
	int i, length;
	length = strlen(buf);
	/* For Data enter by Administrator */
	for(i = 0; i < length + 1; i++) {
		if(buf[i] == '@' || buf[i] == '_' || buf[i] == '-') {
			buf[i] = ' ';
		}
	}
}

void prw(char buf[]) {
	int i, length;
	length = strlen(buf);
    /* For replace "Prices :" -> "0" */
    for(i = 0; i < length; i++) {
		if(buf[i] == 'P' || buf[i] == 'r' || buf[i] == 'i' || buf[i] == 'c' || buf[i] == 'e' || buf[i] == 's' || buf[i] == ':' || buf[i] == ' ') {
			buf[i] = '0';
		}
	}
}

int auth(char un[], char pw[]) {
	/*Path de-clearation*/
	char path_acc[] = "userdata\\", path_pw[] = "userdata\\", acc[] = "\\username.dat", pwd[] = "\\password.dat";
	int c1 = 0, c2 = 0, r1 = 0, r2 = 0, result = -1;
	char match_ac[50], match_pw[50];
	/*Export Account*/
	strcat(path_acc, un);
	strcat(path_acc, acc);
	FILE *extract_ac = fopen(path_acc, "r");
	fgets(match_ac, sizeof(match_ac), extract_ac);
	fclose(extract_ac);
	/*Export Password*/
	strcat(path_pw, un);
	strcat(path_pw, pwd);
	FILE *extract_pwd = fopen(path_pw, "r");
	fgets(match_pw, sizeof(match_pw), extract_pwd);
	fclose(extract_pwd);

	r1 = strcmp(un, match_ac);
	r2 = strcmp(pw, match_pw);
	if(r1 == 0 && r2 == 0) {
		result = 0;
	} else {
		result = 1;
	}

	return result;
}

void pret() {
	if(permission == 0) {
		return SysPanel();
	} if(permission == 1) {
		return SAPanel();
	} if(permission == 2) {
		return CustomerPanel();
	} else {
	    return failure();
	}
}

void startup() {
	char err = 0, d1[50], d2[50], PATH[] = "\\userdata", SPATH[] = "\\system";
	/*Check "userdata"*/
	getcwd(d1, sizeof(d1));
	strcat(d1, PATH);
	DIR* dir = opendir(d1);
	if(dir) {
		closedir(dir);
	} else {
		system("mkdir userdata");
	}
	printf(" Initiator : userdata (folder) initate successfully.\n");
	Sleep(500);

	/*Check "system"*/
	getcwd(d2, sizeof(d2));
	strcat(d2, SPATH);
	DIR *sdir = opendir(d2);
	if(sdir) {
		closedir(sdir);
	} else {
		system("mkdir system");
	}
	printf("\n Initiator : system (folder) initate successfully.\n");
	Sleep(500);

	/*Check "userdata\\udc.dll"*/
	char PATH1[] = "userdata\\udc.dll";
	FILE *start_udc = fopen(PATH1, "r+");
	if(start_udc == NULL) {
		start_udc = fopen(PATH1, "a");
		if(start_udc == NULL) {
			return failure();
		}
		fprintf(start_udc, "userdata (folder) exsist & No error have occured.");
		fclose(start_udc);
	}
	fclose(start_udc);
	printf("\n FILE Initiator: (udc.dll) Configuration Successful Loaded\n");
	Sleep(500);

	/*Check "system\\sdc.dat"*/
	char PATH2[] = "system\\sdc.dat";
	FILE *start_sdc = fopen(PATH2, "r+");
	if(start_sdc == NULL) {
		start_sdc = fopen(PATH, "a");
		if(start_sdc == NULL) {
			return failure();
		}
		fprintf(start_sdc, "system (folder) exsist & No error have occured.");
		fclose(start_sdc);
	}
	fclose(start_sdc);
	printf("\n FILE Initiator: (sdc.dll) Configuration Successful Loaded\n");
	Sleep(500);

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
	fclose(start_stock);
	printf("\n Record Initiator: (stock.txt) Configuration Successful Loaded\n");
	Sleep(500);

	/*Check "maintain.dat"*/
	FILE *start_config_mat;
	start_config_mat = fopen("system\\maintain.dat", "r+");
	if(start_config_mat == NULL) {
		start_config_mat = fopen("system\\maintain.dat", "a");
		if(start_config_mat == NULL) {
			return failure();
		}
		fprintf(start_config_mat, "0");
		fclose(start_config_mat);
	}
	fclose(start_config_mat);
	printf("\n Maintain System: (maintain.dat) Configuration Successful Loaded\n");
	Sleep(500);
	printf("\n Maintain System: (STU) Configuration Successful Loaded\n");
	Sleep(500);

    /*Check "id.dat"*/
    FILE *IDR = fopen("system\\id.dat", "r+");
    if(IDR == NULL) {
        IDR = fopen("system\\id.dat", "a");
        if(IDR == NULL) {
            return failure();
        }
        putw(1000, IDR);
        fclose(IDR);
    }
    fclose(IDR);
    printf("\n System: (IDR) Configuration Successful Loaded\n");
    Sleep(500);
}

void getConfig() {
	/*"maintain.dat" Exports*/
	char file_name[256] = "system\\maintain.dat", mt_confg[2];
	FILE *extract_mcg = fopen(file_name, "r");
	if(extract_mcg != NULL) {
		while (fgets(mt_confg, sizeof(mt_confg), extract_mcg) != NULL) {
			printf("\n System: (MCG) Successful Loaded\n");
		}
		maintain = atoi(mt_confg);
	}
	fclose(extract_mcg);
	system("title HKUSPACE IMRS @ Initialising");
	printf("\n The System are keep loading, please wait .... \n");
	Sleep(1000);
	system("title HKUSPACE IMRS @ Successfully loaded");
	printf("\n HKUSAPCE Inventory Management and Record System is Sucessfully Loaded");
	Sleep(1000);
	system("cls");
};

void failure() {
    extern int errno;
	system("CLS");
	ini();
	printf("\t\n***   System Failure   ***\n");
	printf("Value of Error: %d\n", errno);
	printf("Reason : %s\n\n", strerror(errno));
	printf("To prevent further System Error, exit mode in 5 seconds.\n");
	Sleep(5000);
	exit(0);
}
