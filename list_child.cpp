#include "list_child.h"

void createList(List_child &L) {
    first(L) = NULL;
    last(L) = NULL;
}

address_child alokasi(infotype_child x) {
    address_child P = new elmlist_child;
    info(P) = x;
    next(P) = NULL;
    prev(P) = NULL;
    return P;
}

void insertFirst(List_child &L, address_child P) {
    if(first(L) == NULL) {
        last(L) = P;
        first(L) = P;
    } else {
        next(P) = first(L);
        prev(first(L)) = P;
        first(L) = P;
    }
}

void insertAfter(address_child &Prec, address_child P) {
    prev(next(Prec)) = P;
    next(P) = next(Prec);
    prev(P) = Prec;
    next(Prec) = P;
}

void insertLast(List_child &L, address_child P){
    if (first(L) == NULL){
        last(L) = P;
        first(L) = P;
    }
    else {
        prev(P) = last(L);
        next(last(L)) = P;
        last(L) = P;
    }
}

void deleteFirst(List_child &L, address_child &P)
{
    if(first(L) == last(L))
    {
        first(L) =NULL;
        last(L) = NULL;
    }
    else
    {
        P = first(L);
        first(L) = next(P);
        next(P) = NULL;
        prev(first(L)) = NULL;
    }

}

void deleteLast(List_child &L, address_child &P)
{
    P = last(L);
    last(L) = prev(last(L));
    prev(P) = NULL;
    next(last(L)) = NULL;
}

void deleteAfter(address_child Prec, address_child &P)
{
    P = next(Prec);
    next(Prec) = next(P);
    prev(next(P)) = Prec;
    prev(P) = NULL;
    next(P) = NULL;
}

void printInfo(List_child L) {
    address_child P = first(L);
    if (first(L) != NULL){
        while(P !=NULL) {
            cout<<"ID      : "<<info(P).item_id<<endl;
            cout<<"Name    : "<<info(P).item_name<<endl;
            cout<<"Stock   : "<<info(P).stock<<endl;
            cout<<"Desc    : "<<info(P).item_desc<<endl;
            cout<<"Price   : "<<info(P).item_price<<endl;
            cout<<"Category: "<<info(P).item_category<<endl<<endl;
            P = next(P);
        }
    }
    else {
        cout<<endl;
        cout<<"            No item inserted        "<<endl;
    }
}


address_child findElm(List_child L, infotype_child x) {
    address_child P = first(L);
    if (first(L) == NULL){
        return NULL;
    }
    else {
    while(P != NULL) {
        if(info(P).item_id == x.item_id) {
            return P;
        }
        P = next(P);
    }
    }
    return NULL;
}


