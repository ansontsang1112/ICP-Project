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
void SysAuth();
void SysAdm();
void ShopAuth();
void ShopAdm();
void CustomerAuth();
void CustomerPanel();

/*Functions*/
void addition();
void display();
void search();
void modify();
void del();

/*Extra*/
void csa();
void csa2();
void emm();
void etm();

/*Functions*/
int auth(char [], int);
void startup();
void rw();
void WriteInFile();
void failure();
void getConfig();
int DataCheck(int);

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
int counter = 0, role = 0, rev_value = 0, maintain, tmd;
char appear;
char Normal[] = "Please enter the password", LIF[] = "Authorization Failure, Please try again.";

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
    	printf("You will be redirect to System Administrator Identification Authorization Cneter.\n");
    	sleep(5);
    	return SysAuth();
	}
    
    /*Get Username
    wchar_t Username[1000];
    DWORD nUsername = sizeof(Username);
    GetUserName((LPWSTR)Username, &nUsername);*/
    /*RSM Menu*/
    /*printf(" ^v^ Welcome " << (TCHAR)Username << " use our IMRS, please select the options. ^v^\n\n");*/
    MENU:
    ini();
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
            system("cls");
            goto MENU;
    }
};

int main() {
	menu();
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
	if(auth(pw, 0) == 0) {
		printf("\nAuthorization Success, You will be redirect to System Menu in few seconds.\n");
        sleep(3);
        system("cls");
        return SysAdm();
	} else {
        counter = counter + 1;
        system("CLS");
        return SysAuth();
    }
};

void ShopAuth() {
	system("cls");
	char pw[20];		
	system("CLS");
	ini();
	if(counter == 5) {
		printf("You have type in the max. no of wrong password, the program will auto exit in 5 seconds.\n\n");
        system("timeout 5");
        exit(0);	
	}
	printf(">> Status : %s\n\n", (counter == 0) ? Normal : LIF);
	/*UI Section*/
	printf("***   Shop Administrator Authorization Page   ***\n\n");
	printf("|Error Login Counter :  %d  times. You can try %d times\n\n", counter, 6 - counter);
	/*System Administrtor Auth.*/
	printf("Please type in the Shop Administrator's Password : ");
	scanf("%s", &pw);
	if(auth(pw, 1) == 0) {
		printf("\nAuthorization Success, You will be redirect to System Menu in few seconds.\n");
        sleep(3);
        system("cls");
        return ShopAdm();
	} else {
        counter = counter + 1;
        system("CLS");
        return ShopAuth();
    }
};

void CustomerAuth() {

};

/*Customer Panel & System / Shop Admin. Menu*/
void SysAdm() {
	system("cls");
    int ch2;
    ini();
    counter = 0;
    printf("***   Shop Administration Panel   ***\n\n");
    printf(" 1. Add New Item<s>\n");
    printf(" 2. Display Item Record<s>\n");
    printf(" 3. Search Item Information<s>\n");
    printf(" 4. Modify Item Information<s>\n");
    printf(" 5. Delete Item Record<s>\n");
    printf("\n***   System Administration Panel   ***\n\n");
    printf(" 6. Change System Administrator's Password\n");
    printf(" 7. Change Shop Administrator's Password\n");
    printf(" 8. Enable Maintain Mode\n");
    printf(" 9. Enable Test Mode\n");
    printf("\n What is your option <1-9> ? || ");
    scanf("%d", &ch2);
    switch (ch2) {
        case 1:
            role = 0;
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
            csa();
            break;
        case 7:
            role = 0;
            csa2();
            break;
        case 8:
            emm();
            break;
        case 9:
            etm();
            break;
        default:
            printf("No this option < %d >, < 1 - 9 > Only.\n", ch2);
            sleep(3);
            system("cls");
            return SysAdm();
    }
};

void ShopAdm() {
	system("cls");
    int ch2;
    ini();
    counter = 0;
    printf("***   Shop Administration Panel   ***\n\n");
    printf(" 1. Add New Item<s>\n");
    printf(" 2. Display Item Record<s>\n");
    printf(" 3. Search Item Information<s>\n");
    printf(" 4. Modify Item Information<s>\n");
    printf(" 5. Delete Item Record<s>\n");
    printf("\n***   Administration Panel   ***\n\n");
    printf(" 6. Change Shop Administrator's Password\n");
    printf("\n What is your option <1-6> ? || ");
    scanf("%d", &ch2);
    switch (ch2) {
        case 1:
            role = 1;
            ;
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
            role = 1;
            csa2();
            break;
        case 7:
            csa2();
            break;
        default:
            printf("No this option < %d >, < 1 - 6 > Only.\n", ch2);
            sleep(3);
            system("cls");
            return ShopAdm();
    }
};

void CustomerPanel() {

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
void csa() {
	system("cls");
	ini();
	char file[10], PW[10], NPWD[10], CNP[10];
    if (counter > 5) {
        printf("\nError attempts lager than 5.\n\n");
        system("timeout 5");
        system("CLS");
        return SysAdm();
    }
    printf("\nYou have selected the option 6 : Change the Sys. Admin. Password.\n\n");
    printf("*** Identification Authorization System ***\n\n");
    printf("Status : %s\n", (counter == 0) ? Normal : LIF);
    printf("\nError Login Counter :  %d  times. You can try %d times\n\n", counter, 6 - counter);
    printf("To prevent unknown edition of Sys. Admin. Password, PAUS established.\n\n");
    printf("Please Enter the Old Administration Password: ");
    scanf("%s", PW);
    if(auth(PW, 0) == 0) {
    	printf("\n Authorization Sucess: \n\n");
    	PwTypo:
    	printf("Please Enter the New Administration Password: ");
    	scanf("%s", NPWD);
    	printf("\nPlease Enter it again: ");
    	scanf("%s", CNP);
    	if(strcmp(NPWD, CNP) != 0) {
    		ini();
    		printf("You are required to Enter Again.\n\n");
    		printf("Please wait in few second\n");  
			sleep(5);
			system("cls");
			goto PwTypo;
		}
	} else {
		counter += 1;
		return csa();
	}
	/*Write in "pwd.dat"*/
	FILE *PWD = fopen("pwd.dat", "w");
	fprintf(PWD, "%s", NPWD);
	fclose(PWD);
	printf("\n Password Successfully Changed, Return in 5 seconds");
	sleep(5);
	return SysAdm();
};

void csa2() {
    char PW[10], NPWD[10], CNP[10];
    system("cls");
    ini();
    printf("***   Shop Administrator Authorization Page   ***\n\n");
    /*System Administrator Parts*/
    if(role == 0) {
        printf("\nPlease enter the New Shop Administrator's Password : ");
        scanf("%s", NPWD);
        printf("\nPlease enter the New Shop Administrator's Password again : ");
        scanf("%s", CNP);
        if(strcmp(NPWD, CNP) != 0) {
            return csa2();
        }
        goto WriteIn;
    } else {
        printf("\n** Identification Authorization Required **");
        printf("\nStatus : %s\n", (counter == 0) ? Normal : LIF);
        printf("\nError Counter: You still have %d chances for Error tries.\n", 6 - counter);
        printf("\nTo prevent unknown edition of Shop Admin. Password, PAUS established.\n\n");
        printf("\nPlease Enter the Old Shop Administration's Password: ");
        scanf("%s", PW);
        if(auth(PW, 1) == 0) {
            printf("\n Authorization Success: \n\n");
            STNP:
            printf("Please enter the New Shop Administrator's Password : ");
            scanf("%s", NPWD);
            printf("\nPlease enter the New Shop Administrator's Password Again : ");
            scanf("%s", CNP);
            if(strcmp(NPWD, CNP) != 0) {
                printf("\nYou are required to Enter Again.\n\n");
                sleep(2);
                goto STNP;
            }
            goto WriteIn;
        }
    }

    WriteIn:
    /*Write in "spwd.dat"*/
    printf("");
    FILE *SPWD = fopen("spwd.dat", "w");
    fprintf(SPWD, "%s", NPWD);
    fclose(SPWD);
    printf("\n Password Successfully Changed, Return in 5 seconds");
    sleep(5);
    if(role == 0) {
    	system("cls");
    	return SysAdm();
	} else {
		system("cls");
		return ShopAdm();
	}
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
                return SysAdm();
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
            return SysAdm();            		
    }
};

/*Functions*/
int DataCheck(int type) {
    char TMD[20] = "testmode\\testmode.dat", REL[20] = "stock.txt", TPI[20];
    int return_value;
    FILE *DCT = fopen(((type == 0) ? REL : TMD), "r");
    if(fgets(TPI, sizeof(TPI), DCT) != NULL) {
        return_value = 1;
    }
    return return_value;
};

void WriteInFile(struct Data dataIO, int type) {
    char TMD[20] = "testmode\\testmode.dat", REL[20] = "stock.txt", IDT[20] = "testmode\\id_tm.dat", IDR[20] = "id.dat";
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

int auth(char pw[], int type) {
	/*"pwd.dat / spwd.dat" Password Exports*/
	char spwd[10] = "spwd.dat", pwd[10] = "pwd.dat", tmp[20];
	int local_counter = 0, result = 0;
	FILE *extract_pwd = fopen(((type != 0) ? spwd : pwd), "r");
	
	while(fgets(tmp, sizeof(tmp), extract_pwd) != NULL) {
		local_counter++;
		if(local_counter == 0) {
			continue;
		}
	}
	fclose(extract_pwd);
	result = strcmp(pw, tmp);
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
	sleep(5);
	exit(0);
};
