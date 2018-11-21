#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <Windows.h> //Windows System Library
#include <Lmcons.h> //Username Library
#include <unistd.h>
#include <dos.h>
#include <dirent.h>
#include <errno.h>

/*Function Proto Type*/
/*Menu GUI(s)*/
void ini();
void menu();
void SysPanel();
void SAPanel();
void choices();
void CustomerPanel();

/*User Login & Registation Functions*/
void login();
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
void etm();

/*Functions*/
int auth(char [], char []);
void startup();
void rw();
void WriteInFile();
void failure();
void getConfig();
int DataCheck(int);
void pret();

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
}Data ;

/*Globes Var*/
int counter = 0, role = 0, rev_value = 0, maintain, tmd, permission;
char appear;
char Normal[] = "Please enter the password", LIF[] = "Authorization Failure, Please try again.";
char username[50], password[50], money[20];

void ini() {
    printf("\t***   Welcome to HKUSPACE Inventory Management and Record System   ***\n\n");
    printf("\t\t***    1819S1    ***\n\n");
    printf("\t*** This system is developed by CCIT4020 Class No. ?L-?? Group No,?? ***\n\n\n");
}

void menu() {
	startup();
	getConfig();
	system("title HKUSPACE IMRS @ MENU CLI (ROLE)");
    char ch1 = 'C';
    /*Check IS Maintain Mode enabled ?*/
    FILE *maintain = fopen("system\\maintain.dat", "r");
    char coden = fgetc(maintain);
    if(atoi(&coden) == 1) {
    	ini();
    	printf("Sorry, Mantain Mode is enabled, Only System Administrator are able to login to IMRS.\n\n");
    	printf("If you think this contain any Error, please contact the System Administrator. Sorry for inconvence.\n\n");
    	printf("You will be redirect to MMD Identification Authorization Cneter.\n");
    	sleep(5);
    	return emm();
	}
    
    /*Get Username
    wchar_t Username[1000];
    DWORD nUsername = sizeof(Username);
    GetUserName((LPWSTR)Username, &nUsername);*/
    /*RSM Menu*/
    /*printf(" ^v^ Welcome " << (TCHAR)Username << " use our IMRS, please select the options. ^v^\n\n");*/
    MENU:
    ini();
    char choice;
	system("cls");
	ini();
	printf("\n>> Authorization Center, User Login / Logon System\n\n");
	printf("a. Sign In (Already have User Account)\n");
	printf("b. Sign Up (Do not have User Account)\n\n");
	printf("Please Select < a / b > for Singn In / Sign Up : ");
	fflush(stdin);
	scanf("%c", &choice);
	switch(choice) {
		case 'a':
		case 'A':
			printf("\n\nYou have selected 'Sign In', You will be redirected to Sign in Session in few sec.");
			sleep(3);
			login();
		case 'b':
		case 'B':
			printf("\n\nYou have selected 'Sign Up', You will be redirected to Registation Session in few sec.");
			sleep(3);
			reg();
		default:
			goto MENU;
	}	
	fflush(stdin);
    
};

/*Main Function*/
int main() {
	login();
}

//Auth. System
void login() {
	system("cls");
	ini();
	if(counter == 5) {
		printf("You have type in the max. no. of wrong password, the program will auto exit in 5 seconds.\n\n");
		sleep(5);
		exit(0);
	}
	printf(">> Status : %s\n\n", (counter == 0) ? Normal : LIF);
	/*UI Section*/
	printf("***    User Login System - Authorization Page     ***\n\n");
	printf(">> Error Login Counter : %d times. You can try %d times\n\n", counter, 6 - counter);
	/*Auth. Center*/
	fflush(stdin);
	printf("You are on LOG-IN Mode, Please enter your account & password !");
	printf("\n\nUsername : ");
	scanf("%s", username);
	printf("\nPassword : ");
	scanf("%s", password);
	if(auth(username, password) != 0) {
		printf("\nAuthorization Failure, Please wait for 3 sec. to return LOG-IN Platform.");
		counter++;
		sleep(3);
		return login();
	}
	printf("\nAuthorization Success, Getting the Permissions from PSCF.\n");
	sleep(1);
	/*Get the permission*/
	char path[] = "userdata\\", file[] = "\\permission.dat";
	strcat(path, username);
	strcat(path, file);
	FILE *getPerm = fopen(path, "r+");
	char coden = fgetc(getPerm);
	permission = atoi(&coden);
	fclose(getPerm);
	if(permission == 0) {
	    printf("\nYou are belongs to >> SYS. Admin. Redirecting to Relative GUI Panel ...\n");
	    sleep(3);
	    return SysPanel();
	} if(permission == 1) {
        printf("\nYou are belongs to >> SHOP Admin. Redirecting to Relative GUI Panel ...\n");
        sleep(3);
        return SAPanel();
	} if(permission == 2) {
	    printf("\nYou are belong to >> Customer. Redirecting to Relative GUI Panel ...");
	    sleep(3);
	    return CustomerPanel();
	} else {
	    printf("\nAn error occur. Auto-fixing ....\n");
	    sleep(2);
	    printf("\nFix FAILURE ... Redirecting\n");
	    sleep(3);
        return failure();
	}
};

void reg() {
	
};

/*Customer Panel & System / Shop Admin. Menu*/
void SysPanel() {
	system("cls");
    int choice;
    ini();
    counter = 0;
    printf("***   Shop Administration Panel   ***\n\n");
    printf(" 1. Add New Item<s>\n");
    printf(" 2. Display Item Record<s>\n");
    printf(" 3. Search Item Information<s>\n");
    printf(" 4. Modify Item Information<s>\n");
    printf(" 5. Delete Item Record<s>\n");
    printf("\n***   System Administration Panel   ***\n\n");
    printf(" 6. Change Users Password\n");
    printf(" 7. Change Permission of Specific Users\n");
    printf(" 8. Enable / Disable Maintain Mode\n");
    printf(" 9. Enable / Disable Test Mode\n");
    printf("\n What is your option <1-9> ? || ");
    scanf("%d", &choice);
    choices(choice);
};

void SAPanel() {
	system("cls");
    int choice;
    ini();
    counter = 0;
    printf("***   Shop Administration Panel   ***\n\n");
    printf(" 1. Add New Item<s>\n");
    printf(" 2. Display Item Record<s>\n");
    printf(" 3. Search Item Information<s>\n");
    printf(" 4. Modify Item Information<s>\n");
    printf(" 5. Delete Item Record<s>\n");
    printf("\n***   Administration Panel   ***\n\n");
    printf(" 6. Change Users Password\n");
    printf("\n What is your option <1-6> ? || ");
    scanf("%d", &choice);
    choices(choice);
};

void CustomerPanel() {

};

void choices(int type) {
    switch (type) {
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
            emm();
            break;
        case 9:
            etm();
            break;
        default:
            printf("No this option < %d >, < 1 - 9 > Only.\n", type);
            sleep(3);
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

};

void display() {

};

void search() {

};

void modify() {

};

void del() {

};

/*Features (Extra)*/
void cpwd() {
	system("cls");
	ini();
	char PW[10], NPWD[10], CNP[10];
    if (counter == 5) {
        printf("\nError attempts lager than 5. To prevent Unauthorised Access, Exit in 5 second!\n\n");
        sleep(5);
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
    	printf("\n Authorization Sucess: \n\n");
    	PwTypo:
    	printf("Please Enter the New Password: ");
    	fflush(stdin);
    	scanf("%s", NPWD);
    	printf("\nPlease Enter it again: ");
    	scanf("%s", CNP);
    	if(strcmp(NPWD, CNP) != 0) {
    		ini();
    		printf("You are required to Enter Again.\n\n");
    		printf("Please wait in few second\n");  
			sleep(2);
			system("cls");
			fflush(stdin);
			goto PwTypo;
		}
	} else {
		counter += 1;
		return cpwd();
	}
	/*Write in "pwd.dat"*/
	char path[] = "userdata\\", pwdfile[] = "\\password.dat";
	strcat(path, username);
	strcat(path, pwdfile);
	FILE *PWD = fopen(path, "w");
	fprintf(PWD, "%s", NPWD);
	fclose(PWD);
	printf("\nPassword Successfully Changed, Return in 5 seconds");
	sleep(5);
	pret();
};

void cperm() {
    char PERM[10], PW[20], IUN[20];
    system("cls");
    ini();
    if(counter >= 5) {
    	printf("Max. Error Attemp ... Exit in few sec.");
    	sleep(3);
    	exit(0);
	}
    printf("***   Authorization Session   ***\n\n");
    printf("** Identification Required **\n");
	printf("\n>> Status : %s\n", (counter == 0) ? Normal : LIF);
    printf("\n>> Error Counter: You still have %d chances for Error tries.\n", 6 - counter);
    printf("\nTo prevent unknown edition of permissions, PAUS established.\n\n");
    printf("\nPlease Enter the authorised password : ");
    scanf("%s", PW);
    if(auth(username, password) != 0) {
    	printf("\nIdentification FAILURE !! Please wait for few Seconds ...");
    	sleep(3);
    	counter++;
    	return cperm();
    }
    printf("\nAuthorization Success ... Wait ...\n\n");
	sleep(3);
    STNP:
    printf("Please enter the username that you want to change the permission : ");
    scanf("%s", IUN);
    char path[] = "userdata\\", permfile[] = "\\permission.dat";
	strcat(path, username); 
	strcat(path, permfile);
    FILE *search = fopen(path, "r");
    if(search == NULL) {
      	printf("\nNo this User : %s", IUN);
       	sleep(5);
       	goto STNP;
	} 
	fclose(search);
    printf("\nPlease enter the New permission for %s : ", username);
    scanf("%s", PERM);

    /*Write in "PERM"*/
    printf("");
    FILE *SPRM = fopen(path, "w");
    fputs(PERM, SPRM);
    fclose(SPRM);
    printf("\n\nPermission Successfully Changed ... Please wait for 3 Second");
    sleep(3);
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
                sleep(5);
                system("cls");
                return menu();
                break;
            case 'n':
            case 'N':
                printf("\nYou have selected < N > in EMM. You will be return to Admin. Panel in few seconds.");
                sleep(3);
                return SysPanel();
                break;
            default:
                return emm();
        }
    } else {
        printf("Are you sure to closed Maintain Mode (Y/N) : ");
        scanf("%c", &choice);
        switch(choice) {
            case 'Y':
            case 'y':
                system("title Note @ Maintain Mode (EMM) disabling");
                FILE *maintain = fopen("system\\maintain.dat", "w");
                fprintf(maintain, "%d", rev_index);
                fclose(maintain);
                printf("\nMaintain Mode is Successfully disabled. To prevent error in IRMS, the program will auto restart in 5 seconds.");
                sleep(5);
                system("cls");
                return menu();
            case 'n':
            case 'N':
                printf("\nYou have selected < N > in EMM. You will be exit the IRMS in few seconds.");
                sleep(3);
                exit(0);
            default:
                return emm();
        }
    }
};

void etm() {
	FILE *IDT = fopen("testmode\\id_tm.dat", "r+");
    if(IDT == NULL) {
        IDT = fopen("testmode\\id_tm.dat", "a");
        if(IDT == NULL) {
            return failure();
        }
        putw(1000, IDT);
        fclose(IDT);
    }
	tmd = 1;
    system("title DANGER @ TEST Mode (ETM) Running");
    fflush(stdin);
    char choice;
    ini();
    printf("\t\t\t\t\t***  You have enter the Test Mode (ETM)  ***\n\n");
    printf(">>> Info: Beware to use Testmod, Error may occur if EMT is insert !\n");
    printf("\t\n***   Test Panel   ***\n");
    printf("\na. Additional Test");
    printf("\nd. Display Test");
    printf("\ns. Search Test");
    printf("\nm. Removal Test");
    printf("\nr. Reset Data in Test Mode Docs.");
    printf("\ne. Exit in Test Mode.\n");
    printf("\nPlease Enter the options < a / d / s / m / r / e > : ");
    scanf("%c", &choice);
    switch(choice) {
    	case 'A':
        case 'a':       	
            rev_value = 1;
            system("cls");
            NEW_Record:
            fflush(stdin);
            printf("\n>> You have enter the Test Mode (ETM) @ Additional Test\n\n");
            printf("Record ID, Item ID will be Auto generated.\n");
            printf("\nFormat: Item Name | CTG | Quantity | Weight | Recipient | Final Dest. | Devl. Stat.\n");
            printf("Please Enter The Record Data : ");
            scanf("%s%s%d%lf%s%s%s", Data.ItemName, Data.category, &Data.quantity, &Data.weight, Data.recip, Data.FinalDest, Data.dev_stat);
            fflush(stdin);
            WriteInFile(Data);
            char choice;
            printf("\nWould you like to input another data? ( Y / N ) : ");
            scanf("%c", &choice);
            if(choice == 'y' || choice == 'Y') {
               goto NEW_Record;
            } else {
                printf("\nYour Record are writing to file, please wait ...");
                sleep(3);
                system("cls");
                return etm();
            }
        case 'D':
        case 'd':
            rev_value = 1;
            char str[1024];
            system("cls");
            printf("'\n\t***  You have enter the Test Mode (ETM) @ Display Test  ***\n\n");
            FILE *display = fopen("testmode\\testmode.dat", "r");
            while(fgets(str, sizeof(str), display)) {
                printf("%s", str);              
            }
            fclose(display);
            
            
        case 'E':
        case 'e':
            printf("\nYou will leave test mode very soon ...\n");
            sleep(2);
            printf("\nSaving your test mode result ...\n");
            sleep(3);
            return SysPanel();            		
    }
};

/*Functions*/
int DataCheck(int type) {
    char TMD[50] = "testmode\\testmode.dat", REL[20] = "stock.txt", TPI[20];
    int return_value;
    FILE *DCT = fopen(((type == 0) ? REL : TMD), "r");
    if(fgets(TPI, sizeof(TPI), DCT) != NULL) {
        return_value = 1;
    }
    return return_value;
};

void WriteInFile(struct Data dataIO, int type) {
    char TMD[50] = "testmode\\testmode.dat", REL[20] = "stock.txt", IDT[20] = "testmode\\id_tm.dat", IDR[20] = "id.dat";
    int dc = (type == 0) ? 0 : 1;
    int max = 1000, min = 1, value = 0;
	
    /*Replace '_' / '@' / '-' to ' '*/
    rw(Data.ItemName);
    rw(Data.recip);
    rw(Data.FinalDest);
    rw(Data.FinalDest);
    FILE *WriteIn = fopen(((type == 0) ? REL : TMD), (((DataCheck(dc) == 0) ? "w+" : "a+")));
    
    /*ID Get F(x)*/
    FILE *IDRE = fopen((tmd == 0) ? IDR : IDT, "r");
    value = getw(IDRE);    
    
    /* ---- WriteIn Started ----*/
    fprintf(WriteIn, "---Start of Record (%d)---\n", value);
    fprintf(WriteIn, "Record ID: %d\n", value);
    fprintf(WriteIn, "Item Name: %s\n", Data.ItemName);
    fprintf(WriteIn, "Item ID: %d\n", value);
    fprintf(WriteIn, "Catagory: %d\n", Data.category);
    fprintf(WriteIn, "Quantity: %d\n", Data.quantity);
    fprintf(WriteIn, "Weight: %.3lf Kg\n", Data.weight);
    fprintf(WriteIn, "Recipient: %s\n", Data.recip);
    fprintf(WriteIn, "Final Destination: %s\n", Data.FinalDest);
    fprintf(WriteIn, "Delivery Status: %s\n", Data.dev_stat);
    fprintf(WriteIn, "--- End of Record (%d)---\n", value);      
    fclose(WriteIn);
    
    FILE *ID = fopen((tmd == 0) ? IDR : IDT, "r");
    value = getw(ID);
    fclose(ID);
    FILE *IDW = fopen((tmd == 0) ? IDR : IDT, "w");
    value++;
    putw(value, IDW);
	fclose(IDW);
};

void rw(char buf[]) {
	int i, length;
	length = strlen(buf);
	for(i = 0; i < length + 1; i++) {
		if(buf[i] == '@' || buf[i] == '_' || buf[i] == '-') {
			buf[i] = ' ';
		}
	}
}

int auth(char un[], char pw[]) {
	/*Path declearation*/
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
	char err = 0;
	/*Check "pwd.dat"*/
	FILE *start_pwd;
	start_pwd = fopen("pwd.dat", "r+");
	if(start_pwd == NULL) {
		start_pwd = fopen("pwd.dat", "a");
		if(start_pwd == NULL) {
			return failure();
		}
		fprintf(start_pwd, "admin");
		fclose(start_pwd);
	} 
	printf("\n System: (pwd.dat) Configuration Successful Loaded\n");
	
	/*Check "spwd.dat"*/
	FILE *start_spwd;
	start_pwd = fopen("spwd.dat", "r+");
	if(start_spwd == NULL) {
		start_spwd = fopen("spwd.dat", "a");
		if(start_spwd == NULL) {
			return failure();
		}
		fprintf(start_spwd, "admin");
		fclose(start_spwd);
	} 
	printf("\n System: (spwd.dat) Configuration Successful Loaded\n");
	
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
	start_config_mat = fopen("system\\maintain.dat", "r+");
	if(start_config_mat == NULL) {
		start_config_mat = fopen("system\\maintain.dat", "a");
		if(start_config_mat == NULL) {
			return failure();
		}
		fprintf(start_config_mat, "0");
		fclose(start_config_mat);
	}
	printf("\n System: (maintain.dat) Configuration Successful Loaded\n");
	printf("\n System: (STU) Configuration Successful Loaded\n");
	
    /*Check "testmode.dat"*/
    FILE *start_tmd = fopen("testmode\\testmode.dat", "r+");
    if(start_tmd == NULL) {
        start_tmd = fopen("testmode\\testmode.dat", "a");
        if(start_tmd == NULL) {
            return failure();
        }
        fclose(start_tmd);
    }
    printf("\n System: (TMD) Configuration Successful Loaded\n");
    
    /*Check "id.dat & id_tm.dat"*/
    FILE *IDR = fopen("id.dat", "r+");
    if(IDR == NULL) {
        IDR = fopen("id.dat", "a");
        if(IDR == NULL) {
            return failure();
        }
        putw(1000, IDR);
        fclose(IDR);
    }
    printf("\n System: (IDR) Configuration Successful Loaded\n");
    
    FILE *IDT = fopen("testmode\\id_tm.dat", "r+");
    if(IDT == NULL) {
        IDT = fopen("testmode\\id_tm.dat", "a");
        if(IDT == NULL) {
            return failure();
        }
        putw(1000, IDT);
        fclose(IDT);
    }
    printf("\n System: (IDT) Configuration Successful Loaded\n");
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
	sleep(5);
	system("title HKUSPACE IMRS @ Successfully loaded");
	sleep(4);
	system("cls");	
};

void failure() {
	system("CLS");
	ini();
	printf("\t\n***   System Initial Failure   ***\n");
	printf("Reason : Disc full or no permission\n\n");
	printf("To prevent further System Error, exit mode in 5 seconds.\n");
	sleep(5);
	exit(0);
};
