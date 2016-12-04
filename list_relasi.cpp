#include "list_relasi.h"

void createList(List_relasi &L) {
    first(L) = NULL;
}

address_relasi alokasi(address_child C) {
    address_relasi P = new elmlist_relasi;
    info(P) = C;
    next(P) = NULL;
    return P;
}

void insertFirst(List_relasi &L, address_relasi P) {
    next(P) = first(L);
    first(L) = P;
}

void insertLast(List_relasi &L, address_relasi P)
{
    address_relasi R = first(L);
    while(next(R) != NULL)
    {
        R = next(R);
    }
    next(R) = P;
}

void insertAfter(address_relasi &Prec, address_relasi P) {
    next(P) = next(Prec);
    next(Prec) = P;
}

void printInfo(List_relasi L) {
    address_relasi P = first(L);
    while(P !=NULL) {
        cout<<"->"<<info(info(P)).item_id<<endl;
        P = next(P);
    }
}

address_relasi findElm(List_relasi L, address_child C) {
    address_relasi P = first(L);
    if (first(L) == NULL){
        return NULL;
    }
    else {
    while(P != NULL) {
        if(info(P)== C) {
            return P;
        }
        P = next(P);
    }
    }
    return NULL;
}

void deleteFirst(List_relasi &L, address_relasi &P)
{
    P = first(L);
    first(L) = next(P);
    next(P) = NULL;
}

void deleteLast(List_relasi &L, address_relasi &P)
{
    address_relasi R = first(L);
    while(next(R) != NULL)
    {
        R = next(R);
    }
    P = next(R);
    next(R) = NULL;
}

void deleteAfter(address_relasi Prec, address_relasi &P)
{
    P = next(Prec);
    next(Prec) = next(P);
    next(P) = NULL;
}
