#include <iostream>
#include <conio.h>

using namespace std;
#include "list_child.h"
#include "list_parent.h"

List_parent L;
List_child LC;
List_relasi LR;
address_child AC;
address_parent AP;
address_relasi AR;
infotype_parent XP;
infotype_child XC;

void mainMenu();
void registerCust();
void loginCust();
void loginSeller();
void menuCust();
void menuSeller();
void viewCatalog();
void TopUp();
void insertItem();
void listCust();
void listItem();
void setting();
void myCart();
void removeAccount();
void removeItem();

int main()
{
    createList(L);
    createList(LC);
    createList(LR);
    mainMenu();
    return 0;
}

void mainMenu(){
    system("cls");
    int pil;
    cout<<" * * * * * * * * * * * * * * * * * * * * "<<endl;
    cout<<"*          M A I N  M E N U             *"<<endl;
    cout<<"* * * * * * * * * * * * * * * * * * * * *"<<endl;
    cout<<"*  1. Register                          *"<<endl;
    cout<<"*  2. Login                             *"<<endl;
    cout<<"*  3. Admin                             *"<<endl;
    cout<<"*  99. Exit                             *"<<endl;
    cout<<" * * * * * * * * * * * * * * * * * * * * "<<endl;
    cout<<" Choose menu : ";
    cin>>pil;
    switch (pil){
    case 1:
        registerCust();
        break;
    case 2:
        loginCust();
        break;
    case 3:
        loginSeller();
        break;
    case 99:
        cout<<" *** THANKYOU FOR COMING *** "<<endl;
        break;
    }
}

void registerCust(){
    system("cls");
    cout<<"* * * * * * * * * * * * * * * * * * * * * *"<<endl;
    cout<<"             R E G I S T E R               "<<endl;
    cout<<"* * * * * * * * * * * * * * * * * * * * * *"<<endl;
    cout<<"NIM          : ";cin>>XP.id_cust;
    cout<<"Nama         : ";cin>>XP.name_cust;
    cout<<"Password     : ";cin>>XP.pass;
    cout<<"Address      : ";cin>>XP.address;
    cout<<"Contact      : ";cin>>XP.contact_no;
    XP.saldo = 0;
    if (findElm(L,XP) == NULL) {
        AP = alokasi(XP);
        address_parent Q = first(L);
        address_parent tempT = first(L);
        if(first(L) == NULL){
            insertFirst(L, AP);
        }
        else {
            while (next(Q) != first(L)){
                if (info(next(Q)).id_cust < XP.id_cust){
                    tempT = next(tempT);
                }
                Q = next(Q);
            }
            insertAfter(L,tempT,AP);
        }
        cout<<"- - - - User registered - - - -"<<endl;
        getch();
        mainMenu();
    }
    else {
        cout<<"- - - NIM already exist. Please create new account! - - -"<<endl;
        getch();
        mainMenu();
    }
}

void loginCust(){
    system("cls");
    cout<<"             L O G I N               "<<endl;
    cout<<"* * * * * * * * * * * * * * * * * * *"<<endl;
    cout<<"NIM          : ";cin>>XP.id_cust;
    cout<<"Password     : ";cin>>XP.pass;
    AP = findElm(L,XP);
    if (findElm(L,XP) != NULL) {
        if (info(AP).pass == XP.pass){
            menuCust();
        }
        else {
            cout<<"- - - Your Password is wrong! - - -"<<endl;
            getch();
            loginCust();
        }
    }
    else {
        cout<<"- - - Username Doesn't Exist - - -"<<endl;
        getch();
        mainMenu();
    }
}

void loginSeller(){
    system("cls");
    string username, pass;
    cout<<"* * * * * * * L O G I N  A D M I N * * * * * * *"<<endl;
    cout<<"------------------------------------------------"<<endl;
    cout<<"Username         : ";cin>>username;
    cout<<"Password         : ";cin>>pass;
    if (username == "nadinegerra"){
        if (pass == "1234"){
            menuSeller();
        }
    }
    else{
        cout<<"- - - NOT ADMIN!!! - - -"<<endl;
        getch();
        mainMenu();
    }
}

void menuCust(){
    system("cls");
    int pil;
    cout<<"* * * * * * * WELCOME " <<info(AP).name_cust<< " ! * * * * * * *"<<endl;
    cout<<"My Wallet    : Rp"<<info(AP).saldo<<",-"<<endl;
    cout<<"1. TopUp Saldo"<<endl;
    cout<<"2. View Catalog"<<endl;
    cout<<"3. My Cart"<<endl;
    cout<<"4. Setting"<<endl;
    cout<<"9. Back"<<endl;
    cout<<endl;
    cout<<"Choose menu : "; cin>>pil;
    switch(pil){
    case 1:
        TopUp();
        break;
    case 2:
        viewCatalog();
        break;
    case 3:
        myCart();
        break;
    case 4:
        setting();
        break;
    case 9:
        mainMenu();
        break;

    }
}

void TopUp(){
    system("cls");
    float saldo;
    cout<<"- - - - -  T O P U P   S A L D O  - - - - -"<<endl;
    cout<<"My Wallet    : Rp"<<info(AP).saldo<<",-"<<endl;
    cout<<"TopUp saldo  : Rp"; cin>>saldo;
    info(AP).saldo = info(AP).saldo+saldo;
    cout<<"TopUp success"<<endl;
    getch();
    menuCust();

}

void viewCatalog(){
    system("cls");
    infotype_child tempC;
    cout<<"      L I S T  C A T A L O G      "<<endl;
    cout<<"----------------------------------"<<endl;
    printInfo(LC);
    if (first(LC) == NULL){
        cout<<"- - - No item for sell! - - -"<<endl;
        getch();
        menuCust();
    }
    else{
        cout<<"Choose Item ID: "; cin>>tempC.item_id;
        AC = findElm(LC,tempC);
        if (AC == NULL){
            cout<<"- - - Item ID does not exist - - -"<<endl;
            getch();
            menuCust();
        }
        else{
            if ((info(AP).saldo == 0) || (info(AP).saldo < info(AC).item_price)){
                cout<<"Please TopUp your saldo!"<<endl;
                getch();
                menuCust();
            }
            else {
            AR = alokasi(AC);
            insertFirst(child(AP),AR);
            info(AP).saldo = info(AP).saldo - info(AC).item_price;
            info(AC).stock = info(AC).stock - info(AC).stock;
            cout<<"- - - Transaction Success - - -"<<endl;
            getch();
            menuCust();
            }
        }
    }
}

void myCart(){
    system("cls");
    cout<<"          M Y  C A R T           "<<endl;
    cout<<"---------------------------------"<<endl;
    printInfo(child(AP));
    getch();
    menuCust();

}

void setting(){
    system("cls");
    infotype_child x;
    address_child C;
    cout<<"-----------------------------"<<endl;
    cout<<"       L I S T  I T E M      "<<endl;
    cout<<"-----------------------------"<<endl;
    printInfo(LC);
    cout<<"-----------------------------"<<endl;
    cout<<endl;
    cout<<endl;

    findElm(LC,x);
    int pil;

    cout<<"-----------------------------"<<endl;
    cout<<"         S E T T I N G       "<<endl;
    cout<<"-----------------------------"<<endl;
    cout<<"Input Item ID : ";
    cin>>x.item_id;
    C = findElm(LC,x);

    cout<<"    1. Edit Item Name"<<endl;
    cout<<"    2. Edit Item Stock"<<endl;
    cout<<"    3. Edit Price"<<endl;
    cout<<"    4. Edit Category"<<endl;
    cout<<"    5. Edit Item Description"<<endl;
    cout<<"    6. EXIT"<<endl;
    cout<<endl;
    cout<<"Choose Menu : "; cin>>pil;
    cout<<endl;


    switch (pil){
    case 1:
        cout<<"Item Name : "<<info(C).item_name<<endl;
        cout<<"New Item Name : "; cin>>info(C).item_name;
        cout<<"Success!";
        getch();
        setting();
        break;
    case 2:
        cout<<"Item Stock : "<<info(C).stock<<endl;
        cout<<"New Item Stock : "; cin>>info(C).stock;
        cout<<"Success!";
        getch();
        setting();
        break;
    case 3:
        cout<<"Item Price : "<<info(C).item_price<<endl;
        cout<<"New Item Price : "; cin>>info(C).item_price;
        cout<<"Success!";
        getch();
        setting();
        break;
    case 4:
        cout<<"Item Category : "<<info(C).item_category<<endl;
        cout<<"New Item Category : "; cin>>info(C).item_category;
        cout<<"Success!";
        getch();
        setting();
        break;
    case 5:
        cout<<"Item Description : "<<info(C).item_desc<<endl;
        cout<<"New Item Description : "; cin>>info(C).item_desc;
        cout<<"Success!";
        getch();
        setting();
        break;
    case 6:
        menuSeller();
    }
}

void menuSeller(){
    system("cls");
    int pil;
    cout<<"* * * * * * * WELCOME NADINE & NINDYA * * * * * * *"<<endl;
    cout<<"1. Insert Item"<<endl;
    cout<<"2. List account customer"<<endl;
    cout<<"3. List item"<<endl;
    cout<<"4. Remove customer account"<<endl;
    cout<<"5. Remove Item"<<endl;
    cout<<"6. Setting"<<endl;
    cout<<"9. Back"<<endl;
    cout<<"--------------------------------------------------"<<endl;
    cout<<endl;
    cout<<"Choose Menu : "; cin>>pil;
    switch (pil){
    case 1:
        insertItem();
        break;
    case 2:
        listCust();
        break;
    case 3:
        listItem();
        break;
    case 4:
        removeAccount();
    case 5:
        removeItem();
    case 6:
        setting();
    case 9:
        mainMenu();
        break;
    }
}

void insertItem(){
    system("cls");
    cout<<"- - - - - I N S E R T  I T E M - - - - -"<<endl;
    cout<<"----------------------------------------"<<endl;
    cout<<"Item ID          : "; cin>>XC.item_id;
    cout<<"Item Name        : "; cin>>XC.item_name;
    cout<<"Item Description : "; cin>>XC.item_desc;
    cout<<"Category         : "; cin>>XC.item_category;
    cout<<"Price            : Rp"; cin>>XC.item_price;
    cout<<"Stock            : "; cin>>XC.stock;

    if (findElm(LC,XC) == NULL){
        AC = alokasi(XC);
        insertFirst(LC,AC);
        cout<<endl;
        cout<<"Input Success!"<<endl;
        getch();
        menuSeller();
    }
    else {
        cout<<"Data already exist!"<<endl;
        menuSeller();
    }
}

void listCust(){
    system("cls");
    cout<<"     L I S T  C U S T O M E R     "<<endl;
    cout<<"----------------------------------"<<endl;
    printInfo(L);
    getch();
    menuSeller();

}

void listItem(){
    system("cls");
    cout<<"       L I S T  I T E M           "<<endl;
    cout<<"----------------------------------"<<endl;
    printInfo(LC);
    getch();
    menuSeller();
}

void removeAccount(){
    system("cls");
    infotype_parent Z;
    cout<<"        R E M O V E  A C C O U N T       "<<endl;
    cout<<"-----------------------------------------"<<endl;
    cout<<"List Customers : "<<endl;
    printInfo(L);
    cout<<"-----------------------------------------"<<endl;
    cout<<endl;

    cout<<"Input Customer ID : "; cin>>Z.id_cust;
    address_parent A = first(L);
    if (findElm(L,Z) == NULL){
        cout<<"Customer ID does not exist"<<endl;
        getch();
        menuSeller();
    }
    else {
        address_parent B = findElm(L, Z);
        if (B == first(L)){
            deleteFirst(L,B);
        }
        else if (next(B) == first(L)){
            deleteLast(L,B);
        }
        else {
            do {
                if (next(A) == B){
                    deleteAfter(L,A,B);
                }
                A = next(A);
            }
            while (B != first(L));
        }
        cout<<"Delete Success!!"<<endl;
        getch();
        menuSeller();
    }


}

void removeItem()
{
    system("cls");
    address_child X;
    cout<<"           R E M O V E   I T E M         "<<endl;
    cout<<"-----------------------------------------"<<endl;
    cout<<"List Item : "<<endl;
    printInfo(LC);
    cout<<"-----------------------------------------"<<endl;
    cout<<endl;

    cout<<"Input Item ID : ";cin>>XC.item_id;

    if(findElm(LC,XC)==NULL)
    {
        cout<<"- - - WOOPS!! Item tidak tersedia - - -"<<endl;
        getch();
        menuSeller();
    }
    else
    {
        address_child C=findElm(LC,XC);
        address_child tempC;
        if(first(LC)==last(LC))
        {
            deleteFirst(LC,C);
        }
        else if(C==last(LC))
        {
            deleteLast(LC,C);
        }
        else
        {
            while (tempC != last(LC))
            {
                if(next(tempC)==C)
                {
                    deleteAfter(tempC,C);
                }
            }
        }

        cout<<"Item has been deleted!!"<<endl;
        getch();
    }

    menuSeller();
}
