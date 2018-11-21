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
ShopAdm();
CustomerAuth();
CustomerPanel();

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
int counter = 0, ret_counter = 0, Maintain = 0;

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

void SysAuth() {
    char pw[20];
    fstream AdmPwd;
    char pwd[] = "pwd.dll";
    AdmPwd.open(pwd);
    for (int i = 0; i < 0; i++) {
        getline(AdmPwd, pw);
    }
    getline(AdmPwd, pw);
    char[] SysAdmPwd = pw;
    string SysAdmAuth, FailureMsg;
    system("CLS");
    ini();
    printf("***   System Administrator Authorization Page   ***\n\n");
    FailureMsg = (counter == 0) ? "System Login Center." : "Authorization Failure, Please try again.";
    printf(FailureMsg)";
    printf("\nError Login Counter : " << counter << " times. You can try " << 6 - counter << " times\n\n");
    printf("Please type in the System Administrator's Password : ";
    scanf("%s", SysAdmAuth);
    if (counter == 5) {
        printf("You have type in the max. no of wrong password, the program will auto exit in 5 seconds.\n\n");
        system("timeout 5");
        exit(0);
    }
    if (SysAdmAuth == SysAdmPwd) {
        printf("\nAuthorization Success, You will be redirect to System Menu.\n");
        system("timeout 5");
        system("cls");
        return SysAdm();
    }
    else {
        counter = counter + 1;
        system("CLS");
        return SysAuth();
    }
}

void SysAdm() {
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
    printf("\n What is your option <1-9> ? || ";
    cin >> ch2;
    switch (ch2) {
        case 1:
            ret_counter = 0;
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
            deleted();
            break;
        case 6:
            csa();
            break;
        case 7:
            ret_counter = 0;
            csa2();
            break;
        case 8:
            emm();
            break;
        case 9:
            etm();
            break;
        default:
            printf("No this option < " << ch2 << " >, < 1 - 9 > Only.\n");
            system("timeout 5");
            return SysAdm();
    }
};

void ShopAuth() {
    string pw;
    fstream shoppwd;
    char pwd[] = "pwd.dll";
    shoppwd.open(pwd);
    for (int i = 0; i < 1; i++) {
        getline(shoppwd, pw);
    }
    getline(shoppwd, pw);
    string shopadmpw = pw;
    string shopadmauth, failmsg;
    system("CLS");
    ini();
    printf("***   Shop Administrator Authorization Page   ***\n\n");
    failmsg = (counter == 0) ? "System Login Center." : "Authorization Failure, Please try again.";
    printf(failmsg << endl;
    printf("\nError Login Counter : " << counter << " times. You can try " << 6 - counter << " times\n\n");
    printf("Please type in the Shop Administrator's Password : ";
    cin >> shopadmauth;
    if (counter == 5) {
        printf("You have type in the max. no of wrong password, the program will auto exit in 5 seconds.\n\n");
        system("timeout 5");
        exit(0);
    }
    if (shopadmauth == shopadmpw) {
        printf("\nAuthorization Sucess, You will be redirect to Shop Administration Menu.\n");
        system("timeout 5");
        system("cls");
        return ShopAdm();
    }
    else {
        counter = counter + 1;
        system("CLS");
        return ShopAuth();
    }
};

void ShopAdm() {
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
    printf("\n What is your option <1-6> ? || ";
    cin >> ch2;
    switch (ch2) {
        case 1:
            ret_counter = 1;
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
            deleted();
            break;
        case 6:
            ret_counter = 1;
            csa2();
            break;
        case 7:
            csa2();
            break;
        default:
            printf("No this option < " << ch2 << " >, < 1 - 6 > Only.\n");
            system("timeout 5");
            return ShopAdm();
    }
};

void CustomerAuth() {

};

void CustomerPanel() {

};

/*Option 1 - 5 (Common Functions)*/

void add() {
    /*Check Any Data inside the file*/


    ini();
    printf(">> Item additional Center\n\n");
    char ch3;
    Data data;
    ADD:
    printf("\nIDF: 1> Record No. 2> Item Name, 3> Item No. 4> Category, 5> Quantity, 6> Weight 7> Recipient, 8> Final Destination, and 9> Delivery Ststus\n\n");
    printf("Please enter : ";
    scanf("%d %s %d %s %d %lf %s %s %s", &data.rid, data.item_n, &data.id, data.category, &data.quantity, &data.weight, data.recip, data.final_d, data.dev_stat);

    /*Saving Data arr[]*/


    printf("\nDo you want to add another item record (y/n) : ";
    cin >> ch3;
    if (ch3 == 'y' || ch3 == 'Y') {
        goto ADD;
    }
    else {
        printf("\nYou have total entered " << counter << " Item Records.\n\n");
    }
};

void display() {

};

void search() {

};

void modify() {

};

void deleted() {
    /*string line, del = "3";
    ifstream fin;
    fin.open("pwd.dll");
    ofstream temp;
    temp.open("tmp.dll");
    while (getline(fin, line))
    {
        if (line != del) {
            temp << line << endl;
        }
    }
    temp.close();
    fin.close();
    remove("pwd.dll");
    rename("tmp.dll", "pwd.dll");*/
};

/*Option 6 - 9 (Optional Functions)*/

void csa() {
    ini();
    string spw, OldPwd, ConfirmPwd, NewPwd, ConfirmNPWd, FailureMsg;

    fstream storage;
    storage.open("pwd.dll");
    getline(storage, spw);
    for (int i = 0; i < 1; i++) {
        getline(storage, spw);
    }
    getline(storage, spw);
    string spw2 = spw;
    storage.close();

    fstream AdmPwd;
    char pwd[] = "pwd.dll";
    AdmPwd.open(pwd);
    for (int i = 0; i < 0; i++) {
        getline(AdmPwd, OldPwd);
    }
    getline(AdmPwd, OldPwd);
    string OldSysPwd = OldPwd;
    AdmPwd.close();

    FailureMsg = (counter == 0) ? "System (SYS ADMIN) Login Center." : "Authorization Failure, Please try again.";

    printf("Hello\n");
    printf(OldSysPwd << " || \n");

    if (counter > 5) {
        printf("\nError attempts lager than 5.\n\n");
        system("timeout 5");
        system("CLS");
        return SysAdm();
    }
    system("cls");
    printf("\n You have selected the option 6 : Change the Sys. Admin. Password.\n\n");
    printf("*** Identification Authorization System ***\n\n");
    printf(FailureMsg << "\n\n");
    printf("Error Counter: You still have " << 6 - counter << " chances.\n");
    printf("To prevent unknown edition of Sys. Admin. Password, PAUS established.\n\n");
    printf("Please Enter the Old Administration Password: ";
    cin >> ConfirmPwd;
    if (ConfirmPwd == OldPwd) {
        printf("\n Authorization Sucess: \n\n");
        PwTypo:
        printf("Please Enter the New Administration Password: ";
        cin >> NewPwd;
        printf("\n Please Enter it again: ";
        cin >> ConfirmNPWd;
        if (NewPwd != ConfirmNPWd) {
            printf("\nYou are required to Enter Again.\n\n");
            system("timeout 2");
            system("CLS");
            goto PwTypo;
        }
        ofstream pwd;
        pwd.open("pwd.dll");
        pwd << NewPwd << endl;
        pwd << spw2;
        pwd.close();
        printf("\n Password Successful Changed!\n\n");
        system("timeout 5");
        system("CLS");
        return SysAdm();
    }
    else {
        counter += 1;
        return csa();
    }
};

void csa2() {
    ini();
    string spw, OldPwd, ConPwd, NewPwd, ConNPwd, FailureMsg;

    fstream storage;
    storage.open("pwd.dll");
    getline(storage, spw);
    for (int i = 0; i < 0; i++) {
        getline(storage, spw);
    }
    getline(storage, spw);
    string spw2 = spw;
    storage.close();

    fstream admpwd;
    char pwd[] = "pwd.dll";
    admpwd.open(pwd);
    for (int i = 0; i < 1; i++) {
        getline(admpwd, OldPwd);
    }
    getline(admpwd, OldPwd);
    string OldSysPwd = OldPwd;
    admpwd.close();

    FailureMsg = (counter == 0) ? "System (SHOP ADMIN) Login Center." : "Authorization Failure, Please try again.";
    printf(OldSysPwd << " || \n");

    if (counter > 5) {
        system("cls");
        printf("\n\t\t***  Error attempts lager than 5.  ***.\n\n");
        system("timeout 5");
        system("CLS");
        return SysAdm();
    }
    system("cls");
    printf("\n You have selected the option 6 : Change the Shop. Admin. Password.\n\n");
    printf("*** Identification Authorization System ***\n\n");
    printf(FailureMsg << "\n\n");
    printf("Error Counter: You still have " << 6 - counter << " chances.\n");
    printf("To prevent unknown edition of Shop Admin. Password, PAUS established.\n\n");
    printf("Please Enter the Old Administration Password: ";
    scanf("%s", ConPwd);
    if (ConPwd == OldPwd) {
        printf("\n Authorization Success: \n\n");
        PwdTypo:
        printf("Please Enter the New Administration Password: ";
        scanf("%s", NewPwd);
        printf("\n Please Enter it again: ";
        scanf("%s", ConNPwd);
        if (NewPwd != ConNPwd) {
            printf("\nYou are required to Enter Again.\n\n");
            system("timeout 2");
            system("CLS");
            goto PwdTypo;
        }
        ofstream pwd;
        pwd.open("pwd.dll");
        pwd << spw2 << endl;
        pwd << NewPwd;
        pwd.close();
        printf("\n Password Successful Changed!\n\n");
        system("timeout 5");
        system("CLS");
        return SysAdm();
    }
    else {
        counter += 1;
        return csa2();
    }
};

void emm() {
    char choice;
    system("title NOTE || Maintain Mode (EMM) Running");
    ini();
    printf("Are you sure to open the Maintain Mode (Y / N) : ";
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
    system("title DANGER || TEST Mode (ETM) Running");
    char ch4;
    ini();
    printf("'\n\t***  You have enter the Test Mode (ETM)  ***\n\n");
    printf("*Info: Beware to use Testmod, Error may occur if EMT is insert !\n");
    printf("***   Shop Administration Panel   ***\n\n");
    printf("Please Enter the options < 1 - 9 > : ";
    scanf("%c", &ch4);
}

/*Function Parts*/

int main() {
    add();
}
