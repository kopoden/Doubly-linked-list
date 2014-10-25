#include <stdio.h>
#include <stdlib.h>

#include "d_l_list_functions.h"

int list_errno = OK;

void list_ctor (List* L) {

    list_errno = OK;
    L->first = (element*) calloc (1, sizeof(element*));
    L->last = (element*) calloc (1, sizeof(element*));

    if ((L->first == 0) || (L->last == 0)) {
        free(L->first);
        free(L->last);
        list_errno = ERR_MEM;
        return;
    }

    L->first->nxt = L->last;
    L->first->prvs = 0;


    L->last->prvs = L->first;
    L->last->nxt = 0;

    L->ptr = L->first;

    return;
}
//============================================================================

//============================================================================
void inp_prvs (List* L, double value) {

    list_errno = OK;

    if (L->ptr->prvs == 0) {
        list_errno = ERR_ACCESS;
        return;
    }

    element* buf = L->ptr->prvs;
    L->ptr->prvs = (element*) calloc (1, sizeof(element*));

    if (L->ptr->prvs == 0) { //Not enough memory to allocate
        L->ptr->prvs = buf;  // Go back to the previous state.
        list_errno = ERR_MEM;
        return;
    }

    L->ptr->prvs->prvs = buf;
    L->ptr->prvs->nxt = L->ptr;
    buf->nxt = L->ptr->prvs;
    //Assign value
    L->ptr->prvs->data = value;
    return;
}
//============================================================================

//============================================================================
void inp_nxt (List* L, data_t value) {

    list_errno = OK;

    if (L->ptr->nxt == 0) {
        list_errno = ERR_ACCESS;
    }

    element* buf = L->ptr->nxt;
    L->ptr->nxt = (element*) calloc (1, sizeof(element*));

    if (L->ptr->nxt == 0) { //Not enough memory to allocate
        L->ptr->nxt = buf;  //Go back to the previous state of list
        list_errno = ERR_MEM;
        return;
    }
    L->ptr->nxt->nxt = buf;
    L->ptr->nxt->prvs = L->ptr;
    buf->prvs = L->ptr->nxt;
    //Assign value
    L->ptr->nxt->data = value;
    return;
}
//============================================================================

//============================================================================
void extract (List* L, data_t* value) {

    list_errno = OK;

    if (check_empty(L) == EMPTY) {
        list_errno = EMPTY;
        *value = TRASH;
        return;
    }

    *value = L->ptr->data;
    L->ptr->nxt->prvs = L->ptr->prvs;
    L->ptr->prvs->nxt = L->ptr->nxt;
    L->ptr = L->ptr->prvs;

    return;

}
//============================================================================

//============================================================================
void shft_ptr_nxt (List* L) {
    list_errno = OK;
    if (L->ptr->nxt == 0) {
        list_errno = EMPTY_LINK;
        return;
    }

    L->ptr = L->ptr->nxt;
    return;
}
//============================================================================

//============================================================================
void shft_ptr_prvs (List* L) {
    list_errno = OK;
    if (L->ptr->prvs == 0) {
        list_errno = EMPTY_LINK;
        return;
    }

    L->ptr = L->ptr->prvs;
    return;
}
//============================================================================

//============================================================================
void shft_to_first (List* L) {
    L->ptr = L->first;
    return;
}
//============================================================================

//============================================================================
void shft_to_last (List* L) {
    L->ptr = L->last;
    return;
}
//============================================================================

//============================================================================
int check_empty (List* L) {
    if ((L->first->nxt == L->last) && (L->last != 0))
        return EMPTY;

    return NOT_EMPTY;
}
//============================================================================

//============================================================================
void list_dtor (List* L) {

    shft_to_last(L);
    shft_ptr_prvs(L);
    while (L->ptr != L->first) {
        double E = 0;
        extract(L, &E);
    }
    L->first=0;
    L->last =0;
    return;
}
//=============================================================================
void my_perror (int list_errno) {
    switch (list_errno) {
        case ERR_MEM:
            printf("LIST_ERRNO = %d -- NOT ENOUGH MEMORY. LIST WASN'T CREATED OR CHANGED.\n", list_errno);
            break;
        case EMPTY:
            printf("LIST_ERRNO = %d -- LIST IS EMPTY.\n", list_errno);
            break;
        case NOT_EMPTY:
            printf("LIST_ERRNO = %d -- IS NOT EMPTY, BUT MAY BE IS SPOILED.\n", list_errno);
            break;
        case EMPTY_LINK:
            printf("LIST_ERRNO = %d -- RIGHT OR LEFT BORDER WITH EMPTY LINK WAS ACHIEVED\n", list_errno);
            break;
        case ERR_ACCESS:
            printf("LIST_ERRNO = %d -- CAN'T EXTRACT OR REWRITE FIRST AND LAST ELEMENTS.\n", list_errno);
            break;
        default:
            break;
    }
}

